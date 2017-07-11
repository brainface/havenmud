
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Message to Gwonish");
  SetTown("Karak");
  SetMissionDescription(
    "Dealer has ordered me to find someone to deliver a message. "
    "You look did well last time. I need you do deliver "
    "this message to Sslan Sslar, High Chief of Gwonish. Dealer "
    "wanted this done yesterday. Now move out!"
    );
  SetTitle("the Errand Dog");
  SetMissionLevel(0, 500);
  SetMissionPriority(90);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *ball = ({ });
  if (base_name(environment(who)) == "/domains/crystal_reaches/towns/gwonish/room/gw04") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(ball = filter(all_inventory(who), 
                     (: $1->GetShort() == "a message for Sslan Sslar" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have delivered the message to High Chief Sslan Sslar.");
      while(count) {
        ball[count -1]->eventDestruct();
        count--;
      }
      who->AddExperience(500);
      return 1;
    }
  }
  return 0;
}

void AssignMission(object who) {
     object ball = new("/std/mission_obj/message_gwonish");
     if (!ball->eventMove(who)) {
       ball->eventMove(environment(who));
      }     
      who->eventPrint("Pranak gives you a message for Sslan Sslar.");
}


int CanGetMission(object who) {
	 if(who->GetQuestCompleted("Message to Kresh")) return 1;
   return 0;
   }
