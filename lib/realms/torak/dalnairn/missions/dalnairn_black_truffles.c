//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
//
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Black Truffles");
  SetTown("Dalnairn");
  SetMissionDescription(
    "Your next mission involves retrieving items.\n"
    "Throdrior the Head Chef has perfected his recipe for Black Truffle Souffle."
    " It is absolutely delicious. His business has been doing so"
    " well since he started making it that he is unable to keep"
    " up with demand and gather truffles at the same time. So,"
    " you should go and collect 3 truffles "
    " and bring them to Throdrior in his kitchen for a reward."
    );
  SetTitle("the Chef's Gofer");
  SetMissionLevel(1, 4);
  SetMissionPriority(90);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *truffle = ({ });
  if (base_name(environment(who)) == "/domains/averath/towns/dalnairn/room/building/rest_kitchen") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(truffle = filter(all_inventory(who),
      (: $1->GetShort() == "a black truffle" :) 
    ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 3) {
      who->eventPrint("You have brought 3 black turffles to Throdrior!");
      while(count) {
        meat[count -1]->eventDestruct();
        count--;
      }
      who->AddExperience(500);
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
