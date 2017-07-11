
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Message to Sklaag");
  SetTown("Karak");
  SetMissionDescription(
    "Dealer has ordered me to find someone to deliver a message. "
    "You look did well last time. Third time is a charm. I need you "
    "to deliver this message to Sklaag the Mauler. Dealer has new "
    "orders for the siege on Beornwulf's keep. Dealer wanted this "
    "done yesterday. Now move out!"
    );
  SetTitle("the Envoy of the Horde");
  SetMissionLevel(0, 500);
  SetMissionPriority(90);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *ball = ({ });
  if (base_name(environment(who)) == "/domains/southern_coast/areas/beornwulf_keep/room/tent2") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(ball = filter(all_inventory(who), 
                     (: $1->GetShort() == "a message for Sklaag the Mauler" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have delivered the message to Sklaag the Mauler.");
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
     object ball = new("/std/mission_obj/message_sklaag");
     if (!ball->eventMove(who)) {
       ball->eventMove(environment(who));
      }     
      who->eventPrint("Pranak gives you a message for Sklaag the Mauler.");
}


int CanGetMission(object who) {
	 if(who->GetQuestCompleted("Message to Gwonish")) return 1;
   return 0;
   }
