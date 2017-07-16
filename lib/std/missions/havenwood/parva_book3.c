#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Book p3");
  SetTown("Parva");
  SetMissionDescription(
    "Nice job acquiring that tome. This next one, the client says, "
    "you may get some blood on your hands. But do you mind? I "
    "did not think so. The location of the next book is in a forest "
    "near Jidoor. A couple of sprites live in a tower in that forest. "
    "Each one possesses a spellbook. Our client only needs one book. "
    "He is very impatient, so please hurry!");
  SetTitle("the Bibliotaphic Gofer");
  SetMissionLevel(10, 500);
  SetMissionPriority(80); 
  SetReward("20000 XP");
}

int CheckCompletedMission(object who) {
  object *book = ({ });
  object *ernesto = ({ });
  int count = 0;
    
  if (base_name(environment(who)) == "/domains/havenwood/towns/parva/room/path2") {
    count = sizeof(book = filter(all_inventory(who), (: $1->GetKeyName() == "spellbook" :) ));
    if (who->GetTestChar()) debug("count1 " + count);
    ernesto = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "ernesto" :) );
    if (sizeof(book) < 1) return 0;
    if (sizeof(ernesto) < 1) return 0;
    
 		if (count >= 1) {
 			 while(count) {
        	book[count -1]->eventDestruct();
        	count--;
        	}
 			ernesto[0]->eventForce("speak Thank you! Our client will be pleased with your work.");
    	who->AddExperience(20000);
    	return 1;
    }
    return 0;
  }
}

void AssignMission(object who) {
    }


int CanGetMission(object who) {
		if (who->GetTestChar()) return 1;
		if (who->GetQuestCompleted("Book p2")) return 1;
		return 0;
  }
