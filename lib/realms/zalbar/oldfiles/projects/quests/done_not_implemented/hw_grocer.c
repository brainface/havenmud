#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Shopping List");
  SetTown("Havenwood");
  SetMissionDescription(
    "Where have you been? Fendell is anxiously looking for "
    "your help. He wants to make a stew with that rabbit you "
    "brought him. Fendell has a few items he needs to make "
    "the perfect stew. Fendell is asking for you head to the "
    "town of Sanctum and the Sulumus Trading Post which is "
    "near the town of Sanctum. Fendell wants you to bring him "
    "a potato, two carrots, and a cabbage.");    
  SetTitle("the Havenwood Grocer");
  SetMissionLevel(4, 500);
  SetMissionPriority(75); 
  SetReward("1000 XP");
}

int CheckCompletedMission(object who) {
  object *potato = ({ });
  object *carrot = ({ });
  object *cabbage = ({ });
  object *fendell = ({ });
  int count = 0;
  int counta = 0;
  int countb = 0;
  int countc = 0;
  
    
  if (base_name(environment(who)) == "/domains/havenwood/towns/havenwood/room/gelf8") {
    counta = sizeof(potato = filter(all_inventory(who), (: $1->GetKeyName() == "potato" :) ));
    countb = sizeof(carrot = filter(all_inventory(who), (: $1->GetKeyName() == "carrot" :) ));
	  countc = sizeof(cabbage = filter(all_inventory(who), (: $1->GetKeyName() == "cabbage" :) ));
    
    fendell = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "fendell" :) );
    if (sizeof(potato) < 1) return 0;
    	if (who->GetTestChar()) debug("potato " + counta);
    if (sizeof(carrot) < 2) return 0;
    	if (who->GetTestChar()) debug("carrot " + countb);
    if (sizeof(cabbage) < 1) return 0;
    	if (who->GetTestChar()) debug("cabbage " + countc);
    
    if (sizeof(fendell) < 1) return 0;
    
 		if ((counta >= 1) && (countb >= 2) && (countc >= 1)) {
 			
 			while(counta) {
        	potato[counta -1]->eventDestruct();
        	counta--;
        	if (who->GetTestChar()) debug("potato " + counta);
      		}
    	while(countb) {
        	carrot[countb -1]->eventDestruct();
        	countb--;
        	if (who->GetTestChar()) debug("carrot " + countb);
      		}
    	while(countc) {
        	cabbage[countc -1]->eventDestruct();
        	countc--;
      		}
    	fendell[0]->eventForce("speak Thank you! This will make a delicious stew.");
    	who->AddExperience(1000);
    	return 1;
    }
    return 0;
 
  }
}

void AssignMission(object who) {
	   int num = 0;
     object *tyvalt = ({ });
     tyvalt = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "tyvalt" :) );
     if(who->GetCurrency("imperials") < 55) {
     	  num = 55 - (who->GetCurrency("imperials"));
     	  if (who->GetTestChar()) debug ("imperials: " + num);
     		tyvalt[0]->eventForce("speak Fendell wanted you have some money");
     		who->AddCurrency("imperials", num);
     	}
}

int CanGetMission(object who) {
		//if (who->GetTestChar()) return 1;
		if (who->GetQuestCompleted("Roasted Rabbit")) return 1;
		return 0;
  }
