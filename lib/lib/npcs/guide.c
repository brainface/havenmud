#include <lib.h>
inherit LIB_NPC;
int requestTour(object who, string what);
int eventTour(object *who, int iter);
string *Tour = ({ });
object *Tourists = ({ });
int TourCount = 0;
string *TourQuest;

static void create() {
  ::create();
  Tour = ({ });
  Tourists = ({ });
  TourCount = 0;
  TourQuest = allocate(2);
  AddChannel( ({ "tourooc" }) );
  AddRequestResponse("tour", (: requestTour :) );
  SetLimit(1);
  set_heart_beat(5);
  SetAction(50, ({
  	"!speak Let me show you around.",
  	"!speak You should <ask me for tour>.",
  	"!speak You could <request tour from me>",
  	}) );
}

string *SetTour(string *t) { return Tour = t; }

string *GetTour() { return Tour; }

object *AddTourist(object who) { return Tourists += ({ who }); }

object *GetTourists() { return Tourists; }

int GetTourCount() { return TourCount; }

int AddTourCount(int x) { return TourCount += x; }

int SetTourCount(int x) { return TourCount = x; }

varargs string *SetTourQuest(mixed TQT, string TQ) {
	if (arrayp(TQT)) return TourQuest = TQT;
	return TourQuest = ({ TQT, TQ });
}

string *GetTourQuest() { return TourQuest; }

void heart_beat() {
	::heart_beat();
	if (sizeof(Tourists))
	  eventTour(Tourists, TourCount);
}

mixed eventAsk(object who, string what) {
	mixed t = ::eventAsk(who, what);
	eventForce("speak If you'd like me to take you on a tour, please just "
	           "<ask guide for tour>.");
	return t;
}

void eventGreet(object who) {
  eventForce("speak If you'd like me to take you on a tour, please just "
	           "<ask " + GetKeyName() + " for tour>.");
}

mixed eventRequest(object who, string what) {
	mixed t = ::eventRequest(who, what);
	if (what != "tour") {
		eventForce("speak If you'd like me to take you on a tour, please "
		           "just <ask guide for tour>!");
		           }
	return t;
}

int requestTour(object who, string what) {
	if (what != "tour") {
		eventForce("speak Did you want a tour? If so, <request tour from tour guide>");
		return 1;
	}
	eventForce("speak Wonderful!  I'll show you around!");
	who->eventForce("follow tour guide");
	eventForce("lead " + who->GetKeyName());
	Tourists += ({ who });
	who->AddChannel( ({ "tourooc" }) );
	SetAction(0, ({ }) );
	set_heart_beat(20);
	return 1;
}

int eventTour(object *who, int num) {
	if (num < sizeof(Tour)) {
	  eventForce(Tour[num]);
	  TourCount++;
	}
	if (TourCount == sizeof(Tour)) {
		eventForce("wave");
		foreach(object tourist in Tourists) {
			if (!tourist) continue;
			if (!(tourist->GetQuestCompleted(TourQuest[1]))) {
			  tourist->AddQuest(TourQuest[0], TourQuest[1]);
			  tourist->AddDevelopmentPoints(2);
			  tourist->RemoveChannel( ({ "tourooc" }) );
			  set_heart_beat(5);
			  }
			}
		Tourists = ({ });
		TourCount = 0;
		SetAction(50, ({
  	  "!speak Let me show you around.",
  	  "!speak You should <ask me for tour>.",
  	  "!speak You could <request tour from me>",
  	  }) );
		}
	return TourCount;
}

		