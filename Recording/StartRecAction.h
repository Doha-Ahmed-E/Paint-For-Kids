#pragma once
#include"..\Actions\Action.h"
#include"..\Actions\ActionList.h"
class StartRecAction:public Action 
{
	ActionList* RecList;
public:
	StartRecAction(ApplicationManager* pApp);
	bool isRecorded();
	void ReadActionParameters();
	void Execute();
};

