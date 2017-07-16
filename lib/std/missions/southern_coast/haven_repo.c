
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Reposession");
  SetTown("Haven");
  SetMissionDescription(
    "Your next mission involves retrieving items.\n"
    "Unfortunately that deadbeat gypsy musician has not paid"
    " one of my clients for the dulcimer he is in possession of."
    " If you go and fetch the dulcimer at any costs, you shall be"
    " rewarded handsomely. I'm sure he can be found somewhere"
    " at the gypsy camp off of Lloryk Road."
    );
  SetTitle("the Reposessor");
  SetMissionLevel(23, 500);
  SetMissionPriority(90);
  SetReward("10000 imperials");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *dulcimer = ({ });
  if (base_name(environment(who)) == "/domains/southern_coast/towns/haven/room/misc_buildings/charity") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(dulcimer = filter(all_inventory(who), (: $1->GetShort() == "a beautiful dulcimer" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have returned the Gypsy's dulcimer to Hustin.");
      while(count) {
        dulcimer[count -1]->eventDestruct();
        count--;
      }
      who->AddCurrency("imperials", 10000);
      who->eventPrint("You receive 10000 imperials for your trouble.");
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
  if(who->GetQuestCompleted("Bandit Leader")) return 1;
  return 0;
}
