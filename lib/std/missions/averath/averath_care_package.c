
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Care package Delivery");
  SetTown("Averath");
  SetMissionDescription(
    "Your next mission is a delivery of items.\n"
    "Unfortunately, a distant relative of Edmond"
    " Brunel the Farmer is very ill. Her name is"
    " Calliste and she has taken up residence in"
    " the sewers to protect her precious rats."
    " Edmond has arranged a care package for her"
    " that I need you to deliver. Take this package"
    " to Calliste in the sewers and you will be"
    " rewarded with some money."
    );
  SetMissionLevel(5, 500);
  SetMissionPriority(90);
  SetReward("1200 ducats");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *ball = ({ });
  if (base_name(environment(who)) == "/domains/averath/areas/sewers/room/sewer7") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(ball = filter(all_inventory(who), 
                     (: $1->GetShort() == "a care package for Calliste" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have delivered the care package to Calliste");
      while(count) {
        ball[count -1]->eventDestruct();
        count--;
      }
      who->AddCurrency("ducats", 1200);
      who->eventPrint("You have been rewarded with 1200 ducats for your trouble.");
      return 1;
    }
  }
  return 0;
}

void AssignMission(object who) {
     object ball = new("/std/mission_obj/care_package");
     if (!ball->eventMove(who)) {
       ball->eventMove(environment(who));
      }     
      who->eventPrint("Godard gives you a care package for Calliste.");
}


int CanGetMission(object who) {
   return 1;
}
