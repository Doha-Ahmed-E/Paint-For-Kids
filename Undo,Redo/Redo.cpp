#include "Redo.h"
#include"..\Application Manager\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
Redo::Redo(ApplicationManager* pApp) :Action(pApp)
{
}

void Redo::ReadActionParameters()
{
}

void Redo::Execute()
{
	if (pManager->GetActionList()->canredo())
	{
		pManager->GetActionList()->getRedo()->RedoAction();   //Every action is responsible for redoing itself 
		pManager->GetActionList()->IncrementRedo();    
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No Action to Redo");
	}

}
