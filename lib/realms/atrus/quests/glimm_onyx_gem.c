#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Onyx Gouging for Progress");
  SetTown("Glimmerdin");
  SetMissionDescription(
    "I am rebuilding my forge and I want it to be as efficient as possible, "
        "I have be burning more coal than is needed. I would like to line the "
        "forge with something reflective and strong. I am going to need Onyx, and "
        "a lot of it unfortunately. The small pieces you miners bring me are "
        "mosaic and very pretty, but they don't cover much. Please bring me "
        "1000 pieces of shadowy onyx, I will pay you handsomely if you get them."
    );
  SetTitle("the Onyx Oxen");
  SetMissionLevel(1, 1);
  SetMissionPriority(60);
  SetReward("500 nuggets");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *gems = ({ });
  if (base_name(environment(who)) == "/domains/crystal_reaches/towns/glimmerdin/room/shop") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(gems = filter(all_inventory(who), (: $1->GetShort() == "a shadowy onyx" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1000) {
      who->eventPrint("You have brought 1000 bloodgems to Drigg.");
      while(count) {
        gems[count -1]->eventDestruct();
        count--;
      }
      who->AddCurrency("nuggets", 500);
      who->AddExperience(250000);
      who->eventPrint("You receive 500 nuggets for your back-breaking labor.");
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
  if(who->GetQuestCompleted("Blistered Bloodstone Miner")) {
  if((who->GetSkillLevel("mining")) < 50) return 1;
  }
  return 0;
}

