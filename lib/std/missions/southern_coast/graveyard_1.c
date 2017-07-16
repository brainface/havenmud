#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Graveyard Cleanup");
  SetTown("Haven");
  SetMissionDescription(
    "A foulness has polluted the Old Cemetery here in town. I'd like you "
    "to combat it. Enter the Haven Cemetery (west of the Kylin Church) and "
    "head south.  The old cemetery is haunted by things which make my bones "
    "chill. Slay 3 decayed skeletons and a hideous ghoul and return to me."
    );
  SetTitle("the Guardian of the Old Cemetery");
  SetMissionLevel(3, 50);
  SetMissionPriority(45);
  SetReward("1500 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if ((kills[SOUTHERN_COAST_AREAS "dw/npc/lowskel"] >= 3) && kills[SOUTHERN_COAST_AREAS "dw/npc/ghoul"] >= 1) {
    who->eventPrint("You have been dubbed \"the Guardian of the Old Cemetery\" for your efforts.");
    who->AddExperience(1500);
    return 1;
  }
  return 0;
}

