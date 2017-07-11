#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Tower Assault 1");
  SetTown("Jidoor");
  SetMissionDescription(
"This quest may put you in danger.\n"
    "Today's lesson is an unusual one--it is about the perils of magic"
    " unchecked. One of our citizens has practiced restricted necromancy"
    " and contaminated the tower in the north of town with undead. We"
    " must police our own; go to that edifice and destroy 4 of the zombies"
    " infesting it before they escape and plague the town!" 
  );
  SetTitle("the Zombie Slayer");
SetMissionLevel(3,500);
  SetMissionPriority(45);
  SetReward("1500 XP");
}

int CheckCompletedMission(object who) {
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  int zombie_kills = kills[VALLEY_AREAS "undead_tower/npc/beetle"]
    + kills[VALLEY_AREAS "undead_tower/npc/cat"]
    + kills[VALLEY_AREAS "undead_tower/npc/rat"]
    + kills[VALLEY_AREAS "undead_tower/npc/sprite_noclimb"]
    + kills[VALLEY_AREAS "undead_tower/npc/sprite"];
  if ((zombie_kills >= 4)) {
    who->eventPrint("You have been dubbed \"the Zombie Slayer\" for your efforts.");
    who->AddExperience(1500);
    return 1;
  }
  return 0;
}


