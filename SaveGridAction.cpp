#include "SaveGridAction.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SaveGridAction::ReadActionParameters()
{
	Input* pIn = pManager->GetGrid()->GetInput();
	Output* pO = pManager->GetGrid()->GetOutput();
	pO->PrintMessage("Enter filename to save grid in: ");
	fname = pIn->GetSrting(pO)+".txt";
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	ofstream OutFile;
	OutFile.open(fname, ios::out);
	if (!(OutFile.is_open())) {
		pManager->GetGrid()->PrintErrorMessage("Error while opening file to save!");
		return;
	}
	pManager->GetGrid()->SaveAll(OutFile, 0, fname);
	pManager->GetGrid()->SaveAll(OutFile, 1, fname);
	pManager->GetGrid()->SaveAll(OutFile, 2, fname);
	OutFile.close();
	Output* pO = pManager->GetGrid()->GetOutput();
	pO->PrintMessage("Save complete");
}
SaveGridAction::~SaveGridAction()
{

}