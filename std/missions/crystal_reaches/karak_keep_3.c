#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Silence the Mage");
  SetTown("Karak");
  SetMissionDescription(
    "You are not afraid to die! Good.\n"
    "Nasty magics have helped Beornwulf resist our assaults "
    "on his Keep. Dealer orders you to go silence the human "
    "mage helping Beornwulf. Silence the mage quickly. Now "
    "leave!"
    );
  SetTitle("the Mage Slayer");
  SetMissionLevel(10, 500);
  SetMissionPriority(40);
  SetReward("20000 XP");
}


int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/mage"] >= 1) {
    who->eventPrint("You have weakened the forces defending the Keep!");
    who->AddExperience(20000);
  return 1;
  }
 return 0;
}


int CanGetMission(object who) {
  if((who->GetMorality() < -999)) return 1;
  return 0;
}
