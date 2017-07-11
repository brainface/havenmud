
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Message Courier pt 3");
  SetTown("Haven");
  SetMissionDescription(
    "Dalahalus has need of your skills. He heard you do not "
    "hesitate when given a quest. Dalahalus, the High Priest of "
    "Kylin in Haven Town requests that you take this scroll case "
    "to Matathan, the High Priest of Kylin in Sanctum. "
    );
  SetTitle("the Haven Town Messenger");
  SetMissionLevel(5, 500);
  SetMissionPriority(90);
  SetReward("1000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *ball = ({ });
  if (base_name(environment(who)) == "/domains/peninsula/towns/sanctum/room/kylin_temple") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(ball = filter(all_inventory(who), 
                     (: $1->GetShort() == "a scroll case" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have delivered the scroll case to Matathan.");
      while(count) {
        ball[count -1]->eventDestruct();
        count--;
      }
      who->AddExperience(1000);
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
      who->eventPrint("Hustin gives you a scroll case for Matathan.");
}


int CanGetMission(object who) {
	 if(who->GetQuestCompleted("Message Courier pt 2")) return 1;
  return 0;
}
