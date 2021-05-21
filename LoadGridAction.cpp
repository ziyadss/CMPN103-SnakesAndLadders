#include "LoadGridAction.h"

LoadGridAction::LoadGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

void LoadGridAction::ReadActionParameters()
{
	Input* pIn = pManager->GetGrid()->GetInput();
	Output* pO = pManager->GetGrid()->GetOutput();
	pO->PrintMessage("Enter filename to load grid from: ");
	fname = pIn->GetSrting(pO) + ".txt";
}

void LoadGridAction::Execute()
{
	ReadActionParameters();
	ifstream InFile;
	InFile.open(fname, ios::in);
	if (!(InFile.is_open())) {
		pManager->GetGrid()->PrintErrorMessage("Error while opening file to load!");
		return;
	}
	pManager->GetGrid()->LoadAll(InFile, 0, fname);
	pManager->GetGrid()->LoadAll(InFile, 1, fname);
	pManager->GetGrid()->LoadAll(InFile, 2, fname);
	InFile.close();
	Output* pO = pManager->GetGrid()->GetOutput();
	pO->PrintMessage("Load complete");
}
LoadGridAction::~LoadGridAction()
{

}