#pragma once
#include"..\Actions/Action.h"
#include"..\Figures\CHexagon.h"

class AddHexaAction:public Action
{
private:
	Point P;
	GfxInfo HexaGfxInfo;
	CHexagon* hex;
public:
	AddHexaAction(ApplicationManager* pApp);
	//Reads Hexagon parameters
	virtual void ReadActionParameters();
	virtual void RedoAction();
	virtual bool Undoable();
	virtual void CancelAction();
	//Add Hexagon to the ApplicationManager
	virtual void Execute();
};

