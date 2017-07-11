
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Message to Kresh");
  SetTown("Karak");
  SetMissionDescription(
    "Dealer has ordered me to find someone to deliver a message. "
    "You look like you can follow orders. I need you do deliver "
    "this message to Urg Unt Alla, Goblin Khan of Kresh. Dealer "
    "wanted this done yesterday. Now move out!"
    );
  SetTitle("the Runner");
  SetMissionLevel(0, 500);
  SetMissionPriority(90);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *ball = ({ });
  if (base_name(environment(who)) == "/domains/southern_coast/towns/kresh/room/tents/leader") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(ball = filter(all_inventory(who), 
                     (: $1->GetShort() == "a message for Urg Unt Alla" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have delivered the message to Urg Unt Alla.");
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
     object ball = new("/std/mission_obj/message");
     if (!ball->eventMove(who)) {
       ball->eventMove(environment(who));
      }     
      who->eventPrint("Pranak gives you a message for Urg Unt Alla.");
}


int CanGetMission(object who) {
	 if((who->GetRace() == "orc" ) || (who->GetRace() == "half-orc"))return 1;
	 return 0;
}
