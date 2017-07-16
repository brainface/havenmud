#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Defender of the Keep pt 2");
  SetTown("Haven");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "Lord Beornwulf was very grateful for your"
    " assistance in fighting off the orcish raiders."
    " Unfortunately, they keep coming and his men"
    " have been tied to the walls holding off the"
    " attack. He asks that you once again step up"
    " and enter into service and destroy the"
    " orc captain, Sklaag, in an attempt to"
    " scatter the forces of the orcs."
    );
  SetTitle("the Destroyer of the Orcish Raiding Party");
  SetMissionLevel(40, 500);
  SetMissionPriority(65);
  SetReward("100000 XP");
}


int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/orccaptain"] >= 1) {
    who->eventPrint("You have killed Sklaag the Mauler and scattered the"
                    " orcs besieging the Keep!");
    who->AddExperience(100000);
  return 1;
  }
 return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Defender of the Keep pt 1") &&
     (who->GetMorality() > 1000)) return 1;
  return 0;
}
