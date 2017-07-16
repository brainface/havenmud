/* Malveillant Message Quest   
   Kairehn (12/28/2007) */
#include <lib.h>
inherit LIB_MISSION;
#include <domains.h>

static void create() {
  ::create();
  SetMissionName("A Subtle Message");
  SetTown("Malveillant");
  SetMissionDescription(
    "That was nice work earlier. I hope that head is hidden somewhere "
    "out of the way. The last thing we need is a horde of elves on "
    "our doorstep because some poor bastards kid isn't breathing anymore. "
    "Now, to business. It has come to our attention that there are a small "
    "band of rogues operating out of Haven town. How the mayor does nothing "
    "about this strikes me as absurd. I predict there may have been some "
    "financial incentive for overlooking certain activities. Anyway, "
    "my associates have asked me to deliver a special.. message. The thieves "
    "in question are based in The Divine Chalice, a small tavern in Haven. I "
    "would like you to give a black rose to the owner of the establishment, "
    "named Brook. She'll understand its meaning. This business is, and always "
    "has been, ours. Our priestess, Tallia, always keeps our church full of "
    "black roses, and will not mind if you take one."
    );  
  SetMissionLevel(15, 500);
  SetMissionPriority(61);
  SetReward("15000 XP");
}

int CheckCompletedMission(object who) {  
  object *roses = ({ });
  object *brook = ({ });
  if (base_name(environment(who)) == SOUTHERN_COAST_TOWNS "haven/room/shops/tavern") {    
    roses = filter(all_inventory(who), (: $1->GetShort() == "a black rose" :) );
    if (sizeof(roses)< 1) return 0;   
    brook = filter(all_inventory(environment(who)), (: living($1) && $1->GetName() == "Brook" :));
    if (sizeof(brook) < 1) return 0;    
    roses[0]->eventDestruct();
    who->eventPrint("You have delivered a black rose to Brook.");
    brook[0]->eventForce("speak What's this? Oh..");
    brook[0]->eventForce("quiver");    
    who->AddExperience(15000);    
    return 1;
  }
  return 0;        
}

int CanGetMission(object who) {
  if (who->GetNationality() != "Malveillant") return 0;  
  return 1;
}
