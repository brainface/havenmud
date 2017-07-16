#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Desert Fruit");
  SetTown("Havenwood");
  SetMissionDescription(
    "Our local provisioner, Fendell is looking for someone to "
    "gather some dates. Fendell wants you since you did such a "
    "good job last time. Fendell has heard from Fizzilgig the "
    "Shopkeep that there is a fruit called a date that grows in "
    "the desert town of Yozrath.  Fendell heard it can make a "
    "dessert from these dates. He requests that you bring him "
    "two dates from Yozrath.");
  SetTitle("the Forager");
  SetMissionLevel(20,500);
  SetMissionPriority(75); 
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  object *dates = ({ });
  object *fendell = ({ });
  int count = 0;
  if (base_name(environment(who)) == "/domains/havenwood/towns/havenwood/room/gelf8") {
    count = sizeof(dates = filter(all_inventory(who), (: $1->GetKeyName() == "date" :) ));
    fendell = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "fendell" :) );
    if (sizeof(dates) < 2) return 0;
    if (sizeof(fendell) < 1) return 0;
    
  
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 2) {
        while(count) {
        dates[count -1]->eventDestruct();
        count--;
      }

    fendell[0]->eventForce("speak Thank you! I hope I like them.");
    who->AddExperience(500);
    return 1;
    }
    return 0;
 }
}


int CanGetMission(object who) {
		
		if (who->GetQuestCompleted("Blueberry Picker")) return 1;
			return 0;
  }
