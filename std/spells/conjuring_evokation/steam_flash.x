// Mahkefel 20101126
//   a conjuring spell that attacks ships in an area.
//   As much as possible, this ship works like a ship
//   attack, with evokation skillchecks in the place of sailing.
//                                                              
//   i.e., a mage attacking someone 20 levels above them will   
//   just miss all the time (but gain miss experience, like ship
//   attacks!)                                                  
//                                                              

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

void eventSpellAttackShip(object who, object ship, int level);

static void create() {
   spell::create();   
   SetSpell("steam flash");
   SetSpellType(SPELL_OTHER);
   SetRules("");             
   SetSkills( ([             
      "conjuring" : 150,     
      "evokation" : 150,     
   ]) );                     
   SetAutoDamage(0);         
   SetDifficulty(100);                            
   SetDamageType(HEAT|WATER);                     
   SetEnhanceSkills( ({ "fire magic" }) );        
   SetMagicCost(216,216);                         
   SetHelp(                                       
     "With this spell, an evoker at sea boil the "
     "waters around her, ruining the wooden hulls of "
     "surrounding ships with superheated steam. However, "
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
    send_messages("exhale",                                      
      "$agent_name $agent_verb an annoying "                     
      "%^BOLD%^WHITE%^puff%^RESET%^ of steam.",                  
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
  if ( vehiclep(environment(who)) ) {         
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
    if (vehiclep(ship) && ship != myship) {
      targets += ({ship});                         
    }                                              
  }                                                

  return targets;                                  
}                                                  

int eventCast(object who, int level, string limb, object *targets) {
  foreach(object ship in targets) {                                 
    if (!ship) {                                                    
      continue;                                                     
    }                                                               
    if (!ship->GetVehicleSize()) {                                  
      continue;                                                     
    }                                                               
    eventSpellAttackShip(who,ship, level);                          
  }                                                                 
  return 1;                                                         
}                                                                   

// this is a rough copy of the launch verb's behavior, and gives
//  messages, damage, and xp in the same places of the same amount.
void eventSpellAttackShip(object who, object target, int level) {  
  int success, amount, con;                                        
  object ePilot;                                                   
  object *sailors;                                                 
  ePilot = target->GetPilot();                                     
  con = (ePilot ? ePilot->GetSkillLevel("sailing") : 0);           
  success = who->eventCheckSkill("evokation", con, 0, 0);          
  target->eventPrint(who->GetName() + " is channeling a hostile "  
    "spell against the ship!");                                    

  // attack hit
  if (success > 0) {
    // damage about small ship weapon
    amount = 20000;                                 
    // scale according to spell %                   
    amount = (amount * level) / 100;                
    // add from 0% to 200% additional damage.       
    amount += (amount * who->GetSkillLevel("fire magic"))/500;

    // tell target ship the bad news & apply damage
    target->eventPrint("The ship has struck a large "
      "%^WHITE%^BOLD%^cloud of steam!%^RESET%^");    

    // hey let's set people on fire.
    sailors = all_inventory(target);
    foreach(object sailor in sailors) {
      // it's alive, kill it           
      if (sailor->GetStaminaPoints() ) 
      {                                
        //debug("found npc or player, and screw that guy");
        sailor->eventPrint("The scalding steam burns your eyes!");
        sailor->eventReceiveDamage(this_object(),                 
          HEAT|WATER, who->GetDamage( who->GetSkillLevel("evokation"),
          "projectile combat", target->GetDefense()) / 2, 0 ,         
          target->GetRandomLimb() );                                  
        sailor->eventBlind(1,2);                                      
        sailor->AddEnemy(who); // steam flashes are generally seen as jerk moves.
      }                                                                          
    }                                                                            

    target->eventReceiveDamage(this_object(), HEAT|WATER, amount);

    // tell caster's ship the good news
    environment(who)->eventPrint("%^GREEN%^A giant cloud of steam has "
      "enveloped the enemy ship!");

    // enemy ship went boom. tell people
    if (!target) environment(who)->eventPrint("%^GREEN%^The "
      "enemy ship has been %^RED%^BOLD%^destroyed!%^RESET%^");

  // attack missed
  } else {
    // tell caster, target, & apply xps
    environment(who)->
      eventPrint("%^GREEN%^The spell has failed!%^RESET%^");
    target->eventPrint("The enemy's magic has failed.");
  }

  // casting ice floes does not make you friends
  if (target) {
    if(environment(who)->GetVehicleSize())
      environment(who)->AddShipEnemy(target);
  }
  who->AddParalyzed(1);
}

