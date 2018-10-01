#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Blistered Bloodstone Miner");
  SetTown("Glimmerdin");
  SetMissionDescription(
    "The last time I had you help me get emeralds I asked for 100 of "
        "them because I knew they would be broken and I needed to powder "
        "them anyway. This time I need Bloodstones, but they have to be "
        "perfect, so I'll need more of them to make sure. It's all about "
        "quality. Mine 250 Dark Bloodgems and return them to me."
    );
  SetTitle("the Mountain Bloodletter");
  SetMissionLevel(1, 1);
  SetMissionPriority(60);
  SetReward("50 nuggets");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *gems = ({ });
  if (base_name(environment(who)) == "/domains/crystal_reaches/towns/glimmerdin/room/shop") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(gems = filter(all_inventory(who), (: $1->GetShort() == "a dark bloodstone" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 250) {
      who->eventPrint("You have brought 250 bloodgems to Drigg.");
      while(count) {
        gems[count -1]->eventDestruct();
        count--;
      }
      who->AddCurrency("nuggets", 50);
      who->AddExperience(25000);
      who->eventPrint("You receive 50 nuggets for your back-breaking labor.");
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
  if(who->GetQuestCompleted("Gem Miner")) {
  if((who->GetSkillLevel("mining")) < 35) return 1;
  }
  return 0;
}

