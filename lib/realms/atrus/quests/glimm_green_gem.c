#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Gem Miner");
  SetTown("Glimmerdin");
  SetMissionDescription(
    "You will need to mine some gems for your first task. If I'm going "
        "to make this diadem for the great elfin paladin Arcturus I will need "
        "plenty of gems. Green gems to be specific, give it a nice green base ya?"
    "Mine 100 green gems then bring them back to me here."
    );
  SetTitle("the Gem Sniffer");
  SetMissionLevel(1, 8);
  SetMissionPriority(60);
  SetReward("5 nuggets");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *gems = ({ });
  if (base_name(environment(who)) == "/domains/crystal_reaches/towns/glimmerdin/room/shop") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(gems = filter(all_inventory(who), (: $1->GetShort() == "a small green gem" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 100) {
      who->eventPrint("You have brought 100 green gems to Drigg.");
      while(count) {
        gems[count -1]->eventDestruct();
        count--;
      }
      who->AddCurrency("nuggets", 5);
      who->eventPrint("You receive 5 nuggets for your back-breaking labor.");
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
  if((who->GetSkillLevel("mining")) < 25) return 1;
  return 0;
}
