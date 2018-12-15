#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Emancipation");
  SetTown("Haven");
  SetMissionDescription(
    "I've heard a disturbing tale from a passing gelfling. It seems the vile "
    "nosferatu have enslaved elves foolish enough to live outside the "
    "protection of this great town, and are forcing them to mine for the "
    "grymxorian army. Go find this mine and slay any nosferatu foolish enough "
    "to keep our kin in chains. Show no mercy, but avoid their leader, as I "
    "fear he may end you. Hurry now, go northeast from the crossroads, then "
    "north along the north road until you see the Grymxoria Road. "
    "The mine is somewhere along this road."
    );
  SetTitle("the Slayer of Slavers");
  SetMissionLevel(15, 500);
  SetReward("15000 XP");
  SetMissionPriority(40);
}

int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if ((kills[ESTERGRYM_AREAS "prisoncamp/npc/guard"] >= 9)) {
    who->eventPrint("You have been dubbed \"the Slayer of Slavers\" for your efforts.");
    who->AddExperience(15000);
    return 1;
  }
  return 0;
}


/* This mission is the 2nd in a series of "visit" missions.
 * This one requires you visit an area without benefit of directions.
 * It is required to have completed the 1st mission in the series first.
 */

int CanGetMission(object who) {
  return 1;
}

