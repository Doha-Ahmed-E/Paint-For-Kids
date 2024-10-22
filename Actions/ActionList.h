#pragma once
#include"Action.h"

Action;
class ActionList
{
	Action* ActList[5];                        //array of last 5 executed actions 
	int LastAction;                            //has the location of last traced action 
	int RedoIndex;
public:
	ActionList();
	Action* getList();                          //returns last traced action  
	Action* getRedo();                          //Returns action to be redoed 
	Action* GetToDelete();                      //Returns action to be deleted
	void TraceAction(Action*);                  //traces last 5 actions done by the kid
	void Validate();                            //makes sure LastAction index never exceeds scope size
	void IncrementLastAct();                    //increments LastAction index
	void DecrementLastAct();                    //decrements LastAction index
	void IncrementRedo();                       //increments LastAction index
	void DecrementRedo();                       //decrements LastAction index
	void SortActions();                         //sorts the array to overwrite in actlist[4]
	bool canredo();                             //checks position of redo index in actlist
	bool IsTraced(Action*);
	~ActionList();
};

