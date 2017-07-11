#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Tropical Fruit");
  SetTown("Havenwood");
  SetMissionDescription(
    "Well done. Fendell requests your help once again. Some travelling "
    "merchant told him about this tropical fruit located in the " 
    "jungles of Baria. This same merchant also told Fendell that in the local "
    "inn in the village of Baria, a chef sells the meat of this fruit, "
    "called coconut meat. Fendell is very interested in this fruit. "
    "Please purchase four bowls of coconut meat and bring them to Fendell.");    
  SetTitle("the Gatherer of Coconuts");
  SetMissionLevel(0, 500);
  SetMissionPriority(75); 
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  object *coconut = ({ });
  object *fendell = ({ });
  int count = 0;
    
  if (base_name(environment(who)) == "/domains/havenwood/towns/havenwood/room/gelf8") {
    count = sizeof(coconut = filter(all_inventory(who), (: $1->GetKeyName() == "coconut meat" :) ));
    if (who->GetTestChar()) debug("count1 " + count);
    fendell = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "fendell" :) );
    if (sizeof(coconut) < 4) return 0;
    if (sizeof(fendell) < 1) return 0;
    
 		if (count >= 4) {
 			if (who->GetTestChar()) debug("count2 " + count);
 			while(count) {
        	coconut[count -1]->eventDestruct();
        	count--;
        	}
 			fendell[0]->eventForce("speak Thank you! What shall I put this in.");
    	who->AddExperience(500);
    	return 1;
    }
    return 0;
  }
}

void AssignMission(object who) {
     object *tyvalt = ({ });
     tyvalt = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "tyvalt" :) );
     if(who->GetCurrency("chits") < 48) {
     		tyvalt[0]->eventForce("speak Fendell wanted you to have some money");
     		who->AddCurrency("chits",48);
     	}
}


int CanGetMission(object who) {
		//if (who->GetTestChar()) return 1;
		if (who->GetQuestCompleted("Fruit Basket")) return 1;
		return 0;
  }
