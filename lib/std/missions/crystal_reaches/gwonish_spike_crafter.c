#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Spike Crafter");
  SetTown("Gwonish");
  SetMissionDescription(
    "Go bring me some bamboo shaftes and I will teach the "
    "craft of making bamboo spikes."
    );
  SetMissionLevel(5, 500);
  SetMissionPriority(90);
  SetReward("1000 XP");
  SetTitle("the Spike Crafter");
  }
int CheckCompletedMission(object who) {
  object *shaft = ({ });
  object recipe = new("/std/crafting/scrolls/bamboo_spike");
  object *ssorvor = ({ });
  ssorvor = filter(all_inventory(environment(who)),
      (: $1->GetKeyName() == "ssorvor" :) );   
  if (base_name(environment(who)) == "/domains/crystal_reaches/towns/gwonish/room/enclosement") {
    shaft = filter(all_inventory(who), (: $1->GetKeyName() == "bamboo shaft" :) );
    shaft[0]->eventMove(ssorvor[0]);
    ssorvor[0]->eventForce("speak Excellent work, warrior. Now I will you give "
      "you the recipe for making bamboo spikes of your own.");
    who->eventPrint("You have gathered bamboo!");
    who->eventPrint("You have been dubbed \"the Spike Crafter\" for your efforts.");
    who->AddExperience(1000);
    who->eventPrint("Ssorvor hands you a recipe.");
    recipe->eventMove(who);
    return 1;
  }
  return 0;
}
