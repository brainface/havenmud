#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Book p2");
  SetTown("Parva");
  SetMissionDescription(
    "Your back. That mage just came back and gave me the location of "
    "the second book he needs to acquire. He told me in the town of "
    "Keryth, a dwarf has set up a laboratory in that town. This dwarf "
    "has the tome our mage client needs. Just return the book. No "
    "questions asked.");
  //SetTitle(" ");
  SetMissionLevel(10, 500);
  SetMissionPriority(80); 
  SetReward("5000 XP");
}

int CheckCompletedMission(object who) {
  object *book = ({ });
  object *ernesto = ({ });
  int count = 0;
    
  if (base_name(environment(who)) == "/domains/havenwood/towns/parva/room/path2") {
    count = sizeof(book = filter(all_inventory(who), (: $1->GetKeyName() == "weighty tome" :) ));
    if (who->GetTestChar()) debug("count1 " + count);
    ernesto = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "ernesto" :) );
    if (sizeof(book) < 1) return 0;
    if (sizeof(ernesto) < 1) return 0;
    
 		if (count >= 1) {
 			 while(count) {
        	book[count -1]->eventDestruct();
        	count--;
        	}
 			ernesto[0]->eventForce("speak Thank you! Two down.");
    	who->AddExperience(5000);
    	return 1;
    }
    return 0;
  }
}

void AssignMission(object who) {
    }


int CanGetMission(object who) {
		if (who->GetTestChar()) return 1;
		if (who->GetQuestCompleted("Book p1")) return 1;
		return 0;
  }
