
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("The Acorn");
  SetTown("Haven");
  SetMissionDescription(
    "Suvraela has need of someone to make a delivery. In the town of Sanctum, "
    "Suvraela has a friend who is famous for her love of tree growing. Please "
    "deliver this acorn to Annika. Annika resides in the Eclat Temple "
    "in Sanctum. Good luck."
    );
  SetTitle("the Squirrel");
  SetMissionLevel(0, 30);
  SetMissionPriority(90);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {  
  object *acorn = ({ });
  object *eclat = ({ });
  if (base_name(environment(who)) == "/domains/peninsula/towns/sanctum/room/eclat_temple") {    
    acorn = filter(all_inventory(who), (: $1->GetShort() == "an acorn" :) );
    if (sizeof(acorn)< 1) return 0;   
    eclat = filter(all_inventory(environment(who)), (: living($1) && $1->GetName() == "Annika" :));
    if (sizeof(eclat) < 1) return 0;    
    acorn[0]->eventDestruct();
    who->eventPrint("You have delivered an acorn to Annika.");
    eclat[0]->eventForce("speak Thank you");
    who->AddExperience(500);    
    return 1;
  }
  return 0;        
}

void AssignMission(object who) {
     object ball = new("/std/mission_obj/acorn");
     if (!ball->eventMove(who)) {
       ball->eventMove(environment(who));
      }     
      who->eventPrint("Hustin gives you an acorn for Annika.");
}


int CanGetMission(object who) {
	 
}
