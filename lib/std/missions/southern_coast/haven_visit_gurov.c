
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Message Courier pt 4");
  SetTown("Haven");
  SetMissionDescription(
    "Dalahalus has need of your skills again. He has another scroll "
    "case for you to deliver. Dalahalus requests that you take this "
    "scroll case to Gurov. In Cathedral of Gurov, seek out Grigory "
    "the Patriarch of Kylin and give him the scroll case."
    );
  SetTitle("the Envoy of Haven Town");
  SetMissionLevel(5, 500);
  SetMissionPriority(90);
  SetReward("1200 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *ball = ({ });
  if (base_name(environment(who)) == "/domains/gurov/towns/gurov/room/cathedral1") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(ball = filter(all_inventory(who), 
                     (: $1->GetShort() == "a scroll case" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have delivered the scroll case to Grigory.");
      while(count) {
        ball[count -1]->eventDestruct();
        count--;
      }
      who->AddExperience(1200);
      return 1;
    }
  }
  return 0;
}

void AssignMission(object who) {
     object ball = new("/std/mission_obj/scroll_case");
     if (!ball->eventMove(who)) {
       ball->eventMove(environment(who));
      }     
      who->eventPrint("Hustin gives you a scroll case for Grigory.");
}


int CanGetMission(object who) {
	 if(who->GetQuestCompleted("Message Courier pt 3")) return 1;
  return 0;
}
