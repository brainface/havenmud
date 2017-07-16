#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Book p1");
  SetTown("Parva");
  SetMissionDescription(
    "I need your help. A mage asked me to find someone to get a few books "
    "for his research. I do not know why he could not do it himself. He "
    "said something about he could not leave his research. The first book "
    "is located near Glimmerdin. A gnome living in a cavern near some "
    "kobolds has the first book that my client wants acquired. Just bring "
    "me the book, i do not care how it is aquired."
     );
  //SetTitle(" ");
  SetMissionLevel(5, 500);
  SetMissionPriority(80); 
  SetReward("2000 XP");
}

int CheckCompletedMission(object who) {
  object *book = ({ });
  object *ernesto = ({ });
  int count = 0;
    
  if (base_name(environment(who)) == "/domains/havenwood/towns/parva/room/path2") {
    count = sizeof(book = filter(all_inventory(who), (: $1->GetKeyName() == "book" :) ));
    if (who->GetTestChar()) debug("count1 " + count);
    ernesto = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "ernesto" :) );
    if (sizeof(book) < 1) return 0;
    if (sizeof(ernesto) < 1) return 0;
    
 		if (count >= 1) {
 			 while(count) {
        	book[count -1]->eventDestruct();
        	count--;
        	}
 			ernesto[0]->eventForce("speak Thank you! My client will be pleased.");
    	who->AddExperience(2000);
    	return 1;
    }
    return 0;
  }
}

void AssignMission(object who) {
    }


int CanGetMission(object who) {
		if (who->GetTestChar()) return 1;
		return 0;
  }
