#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Plains Walking");
  SetTown("all");
  SetMissionDescription(
    "Rumors and whispers abound of a continent on the other side of "
    "the globe. I suspect the world is actually flat, and anyone trying "
    "to find said continent will simply fall off the edge. Why don't you "
    "go looking for this fabled 'Namatar', and see if you can find it? If "
    "you don't come back, I'll know I was right!\n"
    "Gods know there's no ferry or portal to take you there freely...\n"
    "You'll need a ship and some sailor stupid enough to sail it to even "
    "try."
    );
  SetTitle("the Circumnavigator");
  SetTown("Parva");
  SetMissionLevel(125,500);
  SetReward("1000000 XP");
  SetMissionPriority(10);
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)), "/domains/namatar") != -1) {
     who->eventPrint("You have found Namatar. Congratulations!");

     who->AddExperience(1000000);
     return 1;
    }
  return 0;
}

/* This mission is the gazillionith in a series of "visit" missions.
 * This one requires you visit an area without benefit of directions.
 * It is required to have completed the 1st mission in the series first.
 */

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Xandrian Journey")) {
    return 1;
  }
  return 0;
}

