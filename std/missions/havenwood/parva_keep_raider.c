#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Raider of the Keep pt 1");
  SetTown("Parva");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "I see you're a nasty one... I heard there's need"
    " for reinforcements at Beornwulf's Keep, should"
    " you aid the orcs that are besieging it, I'm sure"
    " an award can be arranged. Kill at least 6 of"
    " Lord Beornwulf's footsoldiers and you will be"
    " rewarded."
    );
  SetTitle("the Raider of the Keep");
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
  if((who->GetMorality() < -999) && (who->GetNationality() != "Karak")) return 1;
  return 0;
}
