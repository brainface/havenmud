#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Fruit Basket");
  SetTown("Havenwood");
  SetMissionDescription(
    "You again! Nicely done last time. Fendell is looking for "
    "your help again. It seems Fendell is looking some fruit. "
    "Someone mentioned to Fendell there is a Valley in the "
    "Estergrym Mountains that is filled with four types "
    "of fruit. Fendell requests that you bring him two pieces "
    "of each fruit.");    
  SetTitle("the Fruit Harvester");
  SetMissionLevel(0, 500);
  SetMissionPriority(75); 
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  object *apple = ({ });
  object *orange = ({ });
  object *plum = ({ });
  object *peach = ({ });
  object *fendell = ({ });
  int count = 0;
  int counta = 0;
  int countb = 0;
  int countc = 0;
  int countd = 0;
    
  if (base_name(environment(who)) == "/domains/havenwood/towns/havenwood/room/gelf8") {
    counta = sizeof(apple = filter(all_inventory(who), (: $1->GetKeyName() == "red apple" :) ));
    countb = sizeof(orange = filter(all_inventory(who), (: $1->GetKeyName() == "small orange" :) ));
	  countc = sizeof(plum = filter(all_inventory(who), (: $1->GetKeyName() == "plum" :) ));
		countd = sizeof(peach = filter(all_inventory(who), (: $1->GetKeyName() == "fuzzy peach" :) ));
    
    fendell = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "fendell" :) );
    if (sizeof(apple) < 2) return 0;
    	if (who->GetTestChar()) debug("apple " + counta);
    if (sizeof(orange) < 2) return 0;
    	if (who->GetTestChar()) debug("orange " + countb);
    if (sizeof(plum) < 2) return 0;
    	if (who->GetTestChar()) debug("plum " + countc);
    if (sizeof(peach) < 2) return 0;
    	if (who->GetTestChar()) debug("peach " + countd);
    if (sizeof(fendell) < 1) return 0;
    
 		if ((counta >= 2) && (countb >= 2) && (countc >= 2) && (countd >= 2)) {
 			
 			while(counta) {
        	apple[counta -1]->eventDestruct();
        	counta--;
        	if (who->GetTestChar()) debug("apple " + counta);
      		}
    	while(countb) {
        	orange[countb -1]->eventDestruct();
        	countb--;
        	if (who->GetTestChar()) debug("orange " + countb);
      		}
    	while(countc) {
        	plum[countc -1]->eventDestruct();
        	countc--;
      		}
    	while(countd) {
        	peach[countd -1]->eventDestruct();
        	countd--;
      		}
 			fendell[0]->eventForce("speak Thank you! This will make a lovely snack.");
    	who->AddExperience(500);
    	return 1;
    }
    return 0;
 
  }
}

int CanGetMission(object who) {
		//if (who->GetTestChar()) return 1;
// if (who->GetQuestCompleted("Desert Fruit")) return 1
// Mahkefel 2010: removing quest that tends to strand people in yozrath
// from requirements. (I just want to limit Desert Fruit to 20 & up so it
// doesn't make newbs cry.)
		return 0;
  }
