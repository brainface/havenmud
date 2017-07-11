#include <lib.h>
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
  /* This function should be written into every mission.  It will be
   * checked by the heart_beat of the player. It should return 0 if 
   * the player has NOT completed the mission, and should return 1
   * if the player HAS completed the mission.  
   */
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
