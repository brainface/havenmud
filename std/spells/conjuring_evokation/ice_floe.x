// Mahkefel 20101126
//   a conjuring spell that attacks ships in an area.
//   As much as possible, this ship works like a ship 
//   attack, with evokation skillchecks in the place of sailing.
//                                                              
//   i.e., a mage attacking someone 20 levels above them will   
//   just miss all the time (but gain miss experience, like ship
//   attacks!)                                                  
//                                                              
//   all the target->GetVehicleSize() calls are just            
//   checks to make sure the target is a ship. The              
//   opposing ship size doesn't actually matter.                


// changed to no longer give shiny xp, and no longer takes
//   stamina but instead gives paralyze 1, to prevent spam.

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

void eventSpellAttackShip(object who, object ship, int level);

static void create() {
   spell::create();   
   SetSpell("ice floe");
   SetSpellType(SPELL_OTHER);
   SetRules("");             
   SetSkills( ([             
      "conjuring" : 200,     
      "evokation" : 200,                       
   ]) );                                       
   SetAutoDamage(0);                           
   SetDifficulty(100);                                 
   SetDamageType(COLD);                                
   SetEnhanceSkills( ({ "ice magic" }) );              
   SetMagicCost(216,216);                              
   // now just paralyzes 1.
   //SetStaminaCost(150,150);                            
   //SetRequiredStamina(300);                            
   SetHelp(                                            
     "With this spell, an evoker at sea can freeze the "
     "waters around her, damaging the hulls of "        
     "surrounding ships with crushing ice. However, "   
     "summoning such a large amount of elemental energy "
     "is extremely exhausting, and skilled captains can "
     "easily evade the attacks of less experienced mages "
     "at sea."                                            
                                                          
   );                                                      
}                                                          

// give stupid message if there's no other ships around.
int CanCast(object who, int level, mixed limb, object *targets) {

  if (!environment(who)) return 0;

  if ( !sizeof(targets) ) {
    send_messages("conjure",
      "$agent_name $agent_verb a small "
      "%^BOLD%^WHITE%^flurry%^RESET%^ of snowflakes.",
      who,0,environment());                           
  }                                                   

  return spell::CanCast(who, level, limb, targets);
}                                                  

// spell takes no arguments. this sets targets to any   
// ships in area the caster is not riding.              
varargs object *GetTargets(object who, mixed args...) { 
  object *ships;                                        
  object myship;                                        
  object sea;                                           
  object array targets = ({ });                         

  if (!environment(who)) return 0;

  // two valid possiblilties:

  //  dude is on a ship, at sea                 
  //  dude is standing in water/coastal area at sea.
  if (environment(who)->GetVehicleSize()) {         
    myship = environment(who);                      
    sea = environment(myship);                      
    if (!sea) {                                     
      //debug("dude is on a ship that has no environment. bailing.");
      return 0;                                                      
    }                                                                
  }  else {                                                          
    sea = environment(who);                                          
  }                                                                  
                                                                     
  ships = all_inventory(sea);                                        
  foreach(object ship in ships) {                                    
    if (ship->GetVehicleSize() && ship != myship) {                  
      targets += ({ship});                                           
    }                                                                
  }                                                                

  return targets;
}                

int eventCast(object who, int level, string limb, object *targets) {

  //debug("Spell Level: " + (string)level);

  foreach(object ship in targets) {
    if (!ship) {                   
      //debug("nothing there");      
      continue;                      
    }                                
    if (!ship->GetVehicleSize()) {   
      //debug("not a ship");         
      //debug(ship->GetShort());     
      continue;                      
    }                                
    //debug("doing ship attack");    
    eventSpellAttackShip(who,ship, level);
  }                                       
  return 1;                               
}                                         

// this is a rough copy of the launch verb's behavior, and gives
//  messages, damage, and xp in the same places of the same amount.
void eventSpellAttackShip(object who, object target, int level) {  
  int success, amount, con;                                        
  object ePilot;                                                   
  ePilot = target->GetPilot();                                     
  con = (ePilot ? ePilot->GetSkillLevel("sailing") : 0);           
  success = who->eventCheckSkill("evokation", con, 0, 0);          
  target->eventPrint(who->GetName() + " is channeling a hostile "  
    "spell against the ship!");                                    

  // attack hit
  if (success > 0) {
    // damage equal to medium ship weapon
    amount = 40000;                      
    // scale according to spell %        
    amount = (amount * level) / 100;     
    // add from 0% to 200% additional damage.
    amount += (amount * who->GetSkillLevel("ice magic"))/500;
    //debug(amount);                                           
                                                               
    // tell target ship the bad news & apply damage            
    target->eventPrint("The ship has struck a large "          
      "%^BLUE%^BOLD%^floe of ice!%^RESET%^");                  
    target->eventReceiveDamage(this_object(), COLD, amount);   

    // tell caster's ship the good news
    environment(who)->eventPrint("%^GREEN%^The enemy ship "
      "has struck a large %^BLUE%^BOLD%^floe of ice!%^RESET%^");
                                                                
    // apply xp
    // no additional sailing xp now who->AddExperience(con); //who->AddExperience(con *100);

    // enemy ship went boom. tell people
    if (!target) environment(who)->eventPrint("%^GREEN%^The "
      "enemy ship has been %^RED%^BOLD%^destroyed!%^RESET%^");

  // attack missed
  } else {
    // tell caster, target, & apply xps
    environment(who)->
      eventPrint("%^GREEN%^The spell has failed!%^RESET%^");
    target->eventPrint("The enemy's magic has failed.");
    //who->AddExperience(con); //who->AddExperience(con *25);
  }

  // casting ice floes does not make you friends
  if (target) {
    target->AddShipEnemy(this_object());
    if(environment(who)->GetVehicleSize())
      environment(who)->AddShipEnemy(target);
  }

  who->AddParalyzed(1); // just prevent spamming.
}

