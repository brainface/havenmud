#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Tarantula Slayer");
  SetTown("Baria");
  SetMissionDescription(
    "It has come to our attention that the jungle is"
    " becoming overrun with excessively large"
    " tarantulas that are harassing travelers. Go"
    " into the jungle and kill 15 tarantulas and aid"
    " the safety of our travelers and you shall be"
    " rewarded."
    );
  SetTitle("the Adversary of Arachnids");
  SetMissionLevel(1, 15);
  SetMissionPriority(95);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[STD_NPC "tarantula"] >= 15) {
    who->eventPrint("You have killed 15 large tarantulas in the Barian Jungle!");
    who->AddExperience(500);
  return 1;
  }
 return 0;
}


void AssignMission(object who) {
}

int CanGetMission(object who) {
 return 1;
}
