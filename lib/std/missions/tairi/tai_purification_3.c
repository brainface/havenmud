

#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Purification Part 3");
  SetTown("Tairi");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "As you may have expected, the yurei around the"
    " shrine are not a natural occurance. There must"
    " be a force that is causing them to return from"
    " their rest. Go seek out the source of the problem"
    " and destroy it."
    );
  SetTitle("the Consecrated Defender of the Shrine");
  SetMissionLevel(25, 500);
  SetMissionPriority(35);
  SetReward("75000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[TAIRI_AREAS "shrine/npc/necro"]) {
    who->eventPrint("You have slain the evil necromancer defiling the"
                    " Shrine of the Ancients!");
    who->AddExperience(75000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Purification Part 2")) return 1;
  return 0;
}
