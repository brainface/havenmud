

#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Organ Delivery");
  SetTown("Parva");
  SetMissionDescription(
    "Your next mission is a delivery of items.\n"
    "Some crazy gnome in the HavenWood has asked Muertan Colom"
    " to put together some organs from the recently deceased."
    " As vile as it is, they need to be delivered to the gnome."
    " So, I leave that up to you. Take these to the gnome's"
    " workshop in the HavenWood and you will be rewarded. I"
    " hear reports that he has hired some mercenaries to guard"
    " his workshop, so be careful."
    );
  SetTitle("the Organ Carrier");
  SetMissionLevel(8, 500);
  SetMissionPriority(90);
  SetReward("8000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *ball = ({ });
  if (base_name(environment(who)) == "/domains/havenwood/areas/gnome_lab/room/tree2") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(ball = filter(all_inventory(who), (: $1->GetShort() == "a large jar of organs" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have delivered the organs to the gnome.");
      while(count) {
        ball[count -1]->eventDestruct();
        count--;
      }
      who->AddExperience(8000);
      return 1;
    }
  }
  return 0;
}

void AssignMission(object who) {
     object ball = new("/std/mission_obj/jar_of_organs");
     if (!ball->eventMove(who)) {
       ball->eventMove(environment(who));
      }     
      who->eventPrint("Ernesto gives you a large jar of organs.");
}


int CanGetMission(object who) {
   return 1;
}
