
 
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Monkey Meat");
  SetTown("Baria");
  SetMissionDescription(
    "Your next mission involves retrieving items.\n"
    "Ginfur the Chef has perfected his recipe for monkey meat."
    " It is absolutely delicious. His business has been doing so"
    " well since he started making it that he is unable to keep"
    " up with demand and hunt monkeys at the same time. So,"
    " you should go and kill 15 monkeys and retrieve their meat"
    " and bring it to Ginfur in his hut for a reward."
    );
  SetTitle("the Chef's Aide");
  SetMissionLevel(1, 15);
  SetMissionPriority(90);
  SetReward("1500 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *meat = ({ });
  if (base_name(environment(who)) == "/domains/baria/towns/baria/room/commonhut") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(meat = filter(all_inventory(who), (: $1->GetShort() == "a scrap of monkey meat" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 15) {
      who->eventPrint("You have brought 15 scraps of monkey meat to Ginfur!");
      while(count) {
        meat[count -1]->eventDestruct();
        count--;
      }
      who->AddExperience(1500);
      return 1;
    }
  }
  return 0;
}
void AssignMission(object who) {
}

int CanGetMission(object who) {
 return 1;
}
