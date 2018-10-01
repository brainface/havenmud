#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Roasted Rabbit");
  SetTown("Havenwood");
  SetMissionDescription(
    "Fendell is asking for your help again. He heard that some goblins "
    "have made a camp deep in the Westwood. Some of these goblins are "
    "roasting up rabbits.  Since Fendell will not kill a rabbit, he "
    "wants you to bring him one small roasted rabbit.");
  SetTitle("the Roaster of Rabbits");
  SetMissionLevel(4, 500);
  SetMissionPriority(75); 
  SetReward("1000 XP");
}

int CheckCompletedMission(object who) {
  object *rabbit = ({ });
  object *fendell = ({ });
  int count = 0;
    
  if (base_name(environment(who)) == "/domains/havenwood/towns/havenwood/room/gelf8") {
    count = sizeof(rabbit = filter(all_inventory(who), (: $1->GetKeyName() == "roast rabbit" :) ));
    if (who->GetTestChar()) debug("count1 " + count);
    fendell = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "fendell" :) );
    if (sizeof(rabbit) < 1) return 0;
    if (sizeof(fendell) < 1) return 0;
    
 		if (count >= 1) {
 			if (who->GetTestChar()) debug("count2 " + count);
 			while(count) {
        	rabbit[count -1]->eventDestruct();
        	count--;
        	}
 			fendell[0]->eventForce("speak Thank you! This smell sooo good.");
    	who->AddExperience(1000);
    	return 1;
    }
    return 0;
  }
}

void AssignMission(object who) {
    }


int CanGetMission(object who) {
		//if (who->GetTestChar()) return 1;
		if (who->GetQuestCompleted("Tropical Fruit")) return 1;
		return 0;
  }
