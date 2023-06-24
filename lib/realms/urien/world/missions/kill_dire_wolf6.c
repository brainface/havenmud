// 22JUN2023 Urien@Haven 
// Kill Dire Wolves Quest

#include <lib.h>
#include <daemons.h>
#include <domains.h>
#include "../world.h"

inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Dire Wolf Slayer");
  SetTown("BrandeBountyHunter");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "For this quest, you must track down the dire wolves "
    "and slay one. The Brande Evokers have conjured them "
    "from the past and now they roam Kailie."
    );
  SetTitle("the Dire Wolf Slayer");
  SetMissionLevel(20, 500);
  SetMissionPriority(20);
  SetReward("10000 XP");
}
/*
int CheckCompletedMission(object who) {
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  int wolf_kills = kills[WORLD_NPC "dire_wolf"]
  if ((wolf_kills >= 1)) {
    who->eventPrint("You have reduced the dire wolf threat at least "
                    "by one, as requested.");
    who->AddExperience(10000);
    return 1;
  }
  return 0;
}
*/
int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[WORLD_NPC "dire_wolf"]) {
    who->eventPrint("You have reduced the dire wolf threat at least "
                    "by one, as requested.");
    who->AddExperience(10000);
    return 1;
  }
  return 0;
}
/*
void AssignMission(object who) {
}
*/
// Everyone can get this mission no prerequisits
int CanGetMission(object who) {
  return 1;
}
/* Thought this was required to be 'something' made it tc town
int CanGetMission(object who) {
	 if(who->GetTown() == "Soleil" ) return 1;
     return 0;
}
*/
