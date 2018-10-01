/* Malveillant Initiation Quest
   Kairehn (12/28/2007) */
#include <lib.h>
inherit LIB_MISSION;
#include <domains.h>

static void create() {
  ::create();
  SetMissionName("Initiation");
  SetTown("Malveillant");
  SetMissionDescription(
    "You need a job? I've seen you around here, but that doesn't "
    "mean I can trust you, and in my business, trust is everything. "
    "I suppose I could give you the opportunity to prove your loyalty. "
    "Think of this as.. your initiation. Return to me with the head of "
    "an elf, and then we'll talk. I assume you aren't afraid of getting "
    "your hands dirty.."
    );  
  SetMissionLevel(5, 500);
  SetMissionPriority(60);
  SetReward("10000 XP");
}

int CheckCompletedMission(object who) {  
  object *head = ({ });
  object *cont = ({ });  
  if (base_name(environment(who)) == HAVENWOOD_TOWNS "malveillant/rooms/center2") {    
    head = filter(all_inventory(who), (: $1->GetLimb() == "head" && $1->GetRace() == "elf" :) );    
    if (sizeof(head) < 1) return 0;
    cont = filter(all_inventory(environment(who)), (: living($1) && $1->GetName() == "Vorach the Quest Giver" :));        
    if (sizeof(cont) < 1) return 0;    
    debug(cont[0]->GetName());
    cont[0]->eventForce("smirk");
    cont[0]->eventForce("speak Nice work, " + who->GetCapName() + ". I think we're going to " + 
      "enjoy working together. Dispose of that head somewhere, quietly, and see me for your next task.");    
    who->AddExperience(10000);
    return 1;
  }
  return 0;        
}

int CanGetMission(object who) {
  if (who->GetNationality() != "Malveillant") return 0;  
  return 1;
}
