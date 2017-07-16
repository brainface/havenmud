#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Platypus Skinner");
  SetTown("Haven");
  SetMissionDescription(
    "Your next mission involves retrieving items.\n"
    "I have received a request from a local merchant for 10 platypus skins. "
    "Please head over to Platypus Bay and get them for me. You will need to "
    "kill 10 platypi and <skin> them.  Bring the skins back to me here."
    );
  SetTitle("the Platypus Skinner");
  SetMissionLevel(1, 8);
  SetMissionPriority(60);
  SetReward("500 imperials");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *skins = ({ });
  if (base_name(environment(who)) == "/domains/southern_coast/towns/haven/room/misc_buildings/charity") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(skins = filter(all_inventory(who), (: $1->GetPeltSource() == "platypus" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 10) {
      who->eventPrint("You have brought 10 platypus skins to Hustin.");
      while(count) {
        skins[count -1]->eventDestruct();
        count--;
      }
      who->AddCurrency("imperials", 500);
      who->eventPrint("You receive 500 imperials for your trouble.");
      return 1;
    }
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
  if(who->GetQuestCompleted("Platypus Bay")) return 1;
  return 0;
}
