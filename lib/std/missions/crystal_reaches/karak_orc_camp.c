#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Orc Scout");
  SetTown("Karak");
  SetMissionDescription(
    "You are assigned a simple quest of exploration. Dealer is interested "
    "in how the the siege against Beornwulf's keep is going.  Head to the "
    "battlefield near the keep and report back to Pranak what you find. "
    "This quest is completed when you return with news from the battlefield."
    );
  SetTitle("the Scout");
  SetMissionLevel(0, 10);
  SetMissionPriority(100);
  SetReward("500 XP");
}



int CheckCompletedMission(object who) {
  int found = 0;
  object *pranak = ({ });
  if ((found == 0) && (base_name(environment(who)) == 
  	   "/domains/southern_coast/areas/beornwulf_keep/room/field2")) {
  	   who->eventPrint("You have found the battlefield. Report back to Pranak!");
       found = found + 1;	
       who->eventPrint(found);
  	   }
  
  if ((base_name(environment(who)) == 
  	   "/domains/crystal_reaches/towns/karak/room/rd3")) { 
    	pranak = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "pranak" :) );
    	who->eventPrint("SWEET!");
    	if (found > 0)return 0;
    	who->eventPrint("TURTLE POWER");
    	if (sizeof(pranak) < 1) return 0;
 
    pranak[0]->eventForce("speak Report!");
    who->eventForce("speak I found the battlefield");
    pranak[0]->eventForce("speak Good job Scout!");
    who->AddExperience(500);
    return 1;
    }
    return 0;
 }

int CanGetMission(object who) { 
	if (who->GetTestChar()) return 1; 
		return 0;
	}
