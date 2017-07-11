
#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Keep Infiltration");
  SetTown("Karak");
  SetMissionDescription(
    "This quest may put you in danger but what orc does "
    "not love danger.\n"
    "Dealer is upset the seige of the Keep is taking "
    "this long. He wants you to sneak into the Beornwulf's"
    "Keep and kill the livestock. If the humans are too "
    "hungry, they may not fight us and Sklaag's unit "
    "can assault the Keep.Kill one cow and one sheep "
    "and you will be rewarded."
    );
  SetTitle("the Horde Spoliator");
  SetMissionLevel(1, 24);
  SetMissionPriority(99);
  SetReward("1000 XP");
}


int CheckCompletedMission(object who) {
 int sheep = 0, cow = 0;
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/cow"]) cow = 1;
 if (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/sheep"]) sheep = 1;
 if(sheep >= 1 && cow >= 1) {
    who->eventPrint("You have destroyed the food supply in the Keep!");
    who->AddExperience(1000);
  return 1;
  }
 return 0;
}

int CanGetMission(object who) {
  if((who->GetNationality() == "Karak")) return 1;
  return 0;
}
