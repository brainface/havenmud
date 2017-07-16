
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Message Courier pt 2");
  SetTown("Haven");
  SetMissionDescription(
    "This next quest requires you to travel to Jidoor. "
    "Alhana from the Great Library needs a letter to be deliveried "
    "to Lorka Landara of Jidoor. Lorka is the Sage of Jidoor and "
    "can be found in Great Library of Jidoor."
    );
  SetTitle("the Haven Town Courier");
  SetMissionLevel(5, 500);
  SetMissionPriority(90);
  SetReward("1000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *ball = ({ });
  if (base_name(environment(who)) == "/domains/valley/towns/jidoor/room/library/lib_sage") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(ball = filter(all_inventory(who), 
                     (: $1->GetShort() == "a letter" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have delivered the letter.");
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
     object ball = new("/std/mission_obj/aletter");
     if (!ball->eventMove(who)) {
       ball->eventMove(environment(who));
      }     
      who->eventPrint("Hustin gives you a letter.");
}


int CanGetMission(object who) {
	 if(who->GetQuestCompleted("Message Courier")) return 1;
  return 0;
}
