#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Leather Emporium");
  SetTown("Haven");
  SetMissionDescription(
    "You are assigned a simple quest of exploration. One to "
    "to get you more familiar with the Southern Coast and to get you "
    "armour to help protect you outside Haven Town.  You must visit "
    "Torny's Leather Emporium. Once there speak with Odele, she will be "
    "of great assistance to you.\n"
    "This quest is completed once you set foot inside the Leather Emporium."
    );
  SetTitle("the Equipped");
  SetMissionLevel(0, 10);
  SetMissionPriority(100);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)), 
  	  "/domains/southern_coast/areas/leatherstore/leatherstore") != -1) {
     who->eventPrint("You have found the Odele the Generous. Congratulations!");

     who->AddExperience(500);
     return 1;
    }
  return 0;
}

