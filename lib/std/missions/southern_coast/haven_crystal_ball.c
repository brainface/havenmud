#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Crystal Ball Delivery");
  SetTown("Haven");
  SetMissionDescription(
    "It seems the gypsy fortuneteller has ordered a new"
    " crystal ball from an unnamed magician in Haven Town."
    " I need you to deliver this crystal ball to the"
    " gypsy fortuneteller who can be found at the gypsy"
    " camp north of Lloryk Road."
    );
  SetTitle("the Crystal Courier");
  SetMissionLevel(15, 500);
  SetMissionPriority(75);
  SetReward("10000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *ball = ({ });
  if (base_name(environment(who)) == "/domains/crystal_reaches/areas/camp/room/wagon16") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(ball = filter(all_inventory(who), (: $1->GetShort() == "a crystal ball" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have delivered the crystal ball to the Fortuneteller!");
      while(count) {
        ball[count -1]->eventDestruct();
        count--;
      }
      who->AddExperience(10000);
      return 1;
    }
  }
  return 0;
}

void AssignMission(object who) {
     object ball = new("/std/mission_obj/crystal_ball");
     if (!ball->eventMove(who)) {
       ball->eventMove(environment(who));
      }     
}


int CanGetMission(object who) {
  if(who->GetQuestCompleted("Bandit Leader")) return 1;
  return 0;
}


