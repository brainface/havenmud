/*  SPAH! SPAH ROUND HERE! */
// Mahkefel 2011             
//   reveals casual information about a ship (the desc) without risk of drowning.
//   High navigation skill gets useful information, like "it's about to explode" 
//   stealth opposes this check--pirates are harder to spy on than merchantmen   
#include <lib.h>                                                                 
inherit LIB_VERB;                                                                

static void create() {
  ::create();         
  SetVerb("spy");     
  SetRules("on STR"); 
  SetErrorMessage("spy on what ship?");
  SetHelp("Syntax:    spy on <SHIP>  
"
    "Use this command to spy on a nearby ship, possibly revealing "
    "weaknesses or occupants.
"                                   
    "Anyone can hold a spyglass, but a high navigation skill increases "
    "the information you gain from stealthy pirates.
"                 
    "See also: help ships");                                            
}                                                                       

mixed can_spy_on_str(string str) {
 object ship = environment(this_player());
 object who = this_player();              
 object target;                           
 if (!vehiclep(ship)) {                   
   return "But you are not in a ship!";   
 }                                        
 if (who->GetSleeping()) return "Your dreamscape expands in infinite directions.";
 if (who->GetParalyzed()) return "You cannot move!";                              
 if (who->GetStaminaPoints() < 50) return "You are too tired.";                   
 if (str == "ship") return "You must be more specific.";

 target = present(str, environment(ship));

 if (!vehiclep(target)) return "That's no ship!";

 return 1;                                                                        
}                                                                                 

mixed do_spy_on_str(string str) {
  object who = this_player();    
  object ship = environment(who);
  object target;                 
  object pilot;                  
  int pro, difficulty, cost, result;     

  if(environment(ship)) {
    target = present(str, environment(ship));
  } else {                                   
    who->eventPrint("Your ship seems to have abandoned you.");
    return 1;                                                 
  }                                                           

  if (!target) {
    who->eventPrint("Your target is no longer present.");
    return 1;                                            
  }                                                      

  if (target == environment(who)) {
    who->eventPrint("There are easier ways to look at your own ship.");
    return 1;                                                          
  }                                                                    

  switch(who->GetSkillLevel("navigation")) {
    case 0..20:                             
      cost = 50;                            
      break;                                
    case 21..40:                            
      cost = 40;                            
      break;                                
    case 41..80:                            
      cost = 30;                            
      break;                                
    case 81..160:                           
      cost = 20;                            
      break;                                
    case 161..999:                          
      cost = 10;                            
      break;                                
    case 1000..10000:                       
      cost = 1;                             
      break;                                
    default:                                
      cost = 50;                            
      break;                                
    }                                       
    send_messages("gaze",                   
      "$agent_name $agent_verb carefully at $target_name through a spyglass.",
      who, target,  ship );

    // for some reaosn this is diplaying to the verb user's environment,
    // not to the target ship. unimportant, might fix later.
    /*send_messages("see",                                                      
      "You see the tell-tale glint of a spyglass from $agent_name.",          
      ship, 0,  target );*/

    who->AddStaminaPoints(-cost);
                                                                                                           
    if (!target->GetPilot()) {                           
      difficulty = 0;                                    
      //who->eventPrint("There's no one at the wheel!");
    } else {
      difficulty = target->GetPilot()->GetSkillLevel("stealth");
    }

    result = who->eventCheckSkill("navigation", difficulty, 0, 100);

    // any success
    if (result > 0) {
      who->eventPrint( target->GetExternalDesc() );
    // failure
    } else {
      send_messages("fumble",                   
        "$agent_name $agent_verb about with $agent_possessive spyglass, getting "
        "alternating views of $agent_possessive thumb and the sky.",
      who, target,  ship );
      return 1;
    }

    // if decent success
    if (result > 20) {
      who->eventPrint(target->GetDriveStatus());
      who->eventPrint(target->GetWeaponStatus());
      who->eventPrint(target->GetShieldStatus());
      who->eventPrint(target->GetSensorStatus());
      who->eventPrint(target->GetItemCondition());
    } else {
      who->eventPrint("You are unable to discern any fine details of the ship.");
    }
    
    // if huge success oh hai captains
    if (result > 40) {
      who->eventPrint(target->GetInternalDesc());
    } else {
      who->eventPrint("You are unable to see anyone on deck.");
    }

    return 1;
}

