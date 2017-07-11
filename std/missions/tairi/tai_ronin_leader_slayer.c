#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Ronin Leader");
  SetTown("Tairi");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "Now you must travel back to the ronin camp."
    " In order to teach those outlaws a lesson"
    " you will need to kill their leader"
    );
  SetTitle("the Eradicator of Outlaws");
  SetMissionLevel(10, 500);
  SetMissionPriority(65);
  SetReward("10000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[TAIRI_AREAS "camp/npc/leader"]) {
    who->eventPrint("You have slain the Ronin Leader.");
    who->AddExperience(10000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Ronin Slayer")) return 1;
  return 0;
}

