#define TODOLIST  currentDuoPList->duoP->p->duoPList->duoP->objB->duoPList->nextDuoPList->duoP->objB
#define SYSTEMOBJ currentDuoPList->duoP->p->duoPList->duoP->objB

class ObjTO
{
public:
	struct DuoP {
		ObjTO* objA;
		ObjTO* objB;
		ObjTO* p;
	};
	struct DuoPList {
		DuoPList* prevDuoPList;
		DuoPList* nextDuoPList;
		DuoP* duoP;
	};
	DuoPList* duoPList;
	void callIt(DuoP* caller, ObjTO* dataIn) {
		ObjTO* data = dataIn;
		ObjTO::DuoPList* currentDuoPList = this->duoPList->prevDuoPList; //First list is a system list

		while ((currentDuoPList->duoP->objA != (TODOLIST)) && (currentDuoPList->duoP->objA != SYSTEMOBJ))	{
			currentDuoPList = currentDuoPList->prevDuoPList;
		}
		currentDuoPList = (currentDuoPList->duoP->objB)->duoPList->prevDuoPList;
		do {
			currentDuoPList->duoP->objB->callIt(currentDuoPList->duoP, data);
			currentDuoPList = currentDuoPList->prevDuoPList;
		} while (currentDuoPList->duoP->objA != SYSTEMOBJ);
	}
};