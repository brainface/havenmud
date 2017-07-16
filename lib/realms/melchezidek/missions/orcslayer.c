#include <lib.h>
#include <daemons.h>
#define NUMBER_REQUIRED 6
#define NPC "/domains/southern_coast/areas/beornwulf_keep/npc/osoldier"
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Quest Template");
  SetTown("None");
  SetMissionDescription(
   ""
    );
  SetTitle("the Title");
  SetMissionLevel(0, 5);
  SetMissionPriority(50);
  SetReward("None - Test Char Quest");
}

int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[NPC] >= NUMBER_REQUIRED) {
  return 1;
  }
 return 0;
}

void AssignMission(object who) {
  /* This function will be called by the mission control NPC at the 
   * time the mission is assigned. This function is where you would
   * want to do stuff like giving out a map, or a ticket, etc.
   */
}

/* int CanGetMission(object who)
 * Use this function to be able to check for "special" mission requirements,
 * such as having completed a previous mission in a series.
 */

int CanGetMission(object who) {
  return 1;
}
