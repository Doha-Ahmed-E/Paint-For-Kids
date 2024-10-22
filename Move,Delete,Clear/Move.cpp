#include "Move.h"
#include"..\Application Manager\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"..\Figures\CFigure.h"

Move::Move(ApplicationManager* pApp) :Action(pApp)
{
	
}

void Move::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click at One Point That You Want To Move");

	//Read one point store in point p
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->PrintMessage("the point was entered");

	pOut->ClearStatusBar();
}

void Move::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getSelectedFig())                //to only be called if there is a selected fig
	{
		f = pManager->getSelectedFig();
		if (!pManager->getRecorder()->isPlayingNow())
			ReadActionParameters();
		pOut->PrintMessage("aclick on move");

		pManager->getSelectedFig()->Movefi(pOut, p1);    //every figure is responsible for moving itself  
		pOut->ClearDrawArea();

	}
	else pOut->PrintMessage("Please select a figure first ");
}

bool Move::Undoable()
{
	return true;
}

void Move::CancelAction()
{
	Output* pOut = pManager->GetOutput();
	f->Movefi(pOut, f->PrePoint());
	pOut->ClearDrawArea();
}

void Move::RedoAction()
{
	Output* pOut = pManager->GetOutput();
	f->Movefi(pOut, p1);
	pOut->ClearDrawArea();
}
