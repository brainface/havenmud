#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Storm the Keep");
  SetTown("Karak");
  SetMissionDescription(
    "Are you afraid to die orc! Good.\n"
    "Sklaag has requested from Dealer reinforcments "
    "to assault the Keep and break the seige. Dealer "
    "orders you to break into the Keep and kill 6 of "
    "the footsoldiers defending the Keep. Once this is "
    "complete leave the Keep and Sklaag's unit will "
    "storm the keep."
    );
  SetTitle("the Horde Raider");
  SetMissionLevel(7, 500);
  SetMissionPriority(65);
  SetReward("20000 XP");
}


int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/hsoldier"] >= 6) {
    who->eventPrint("You have weakened the forces defending the Keep!");
    who->AddExperience(20000);
  return 1;
  }
 return 0;
}


int CanGetMission(object who) {
  if((who->GetMorality() < -999) && (who->GetNationality() == "Karak")) return 1;
  return 0;
}
