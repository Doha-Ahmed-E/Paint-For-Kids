#pragma once
#include"..\Actions\Action.h"
#include"..\Figures\CCircle.h"

class AddCircleAction:public Action
{
private:
	Point P1;
	Point P2;
	GfxInfo CircleGfxInfo;
	CCircle* circ;
public:
	AddCircleAction(ApplicationManager* pApp);
	//Reads Circle parameters
	virtual void ReadActionParameters();
	virtual void RedoAction();
	virtual void CancelAction();
	virtual bool Undoable();
	//Add Circle to the ApplicationManager
	virtual void Execute();
};

