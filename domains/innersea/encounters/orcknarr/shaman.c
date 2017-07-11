// mahkefel 2010 or so
// a big karak sea encounter person
#include <lib.h>      
#include <domains.h>  
#include <std.h>      
#include <damage_types.h>
#include <daemons.h>     
#include <armour_types.h>
#include "reaver.h"      
inherit LIB_PIRATE;      
int eventCheckPlayer();  
void heart_beat();       
void eventRaiseDeadSailors(object ship);
object *pirates;                        

static void create() {
  ::create();         
  SetKeyName("shaman");
  SetShort("a mutated shaman (half-orc)");
  SetId( ({ "shaman", "half-orc" }) );    
  SetAdjectives( ({ "mutated", "shaman","half-orc" }) );
  SetRace("half-orc");                                  
  AddLimb("lower right arm","torso",2);                       
  AddLimb("lower left arm","torso",2);                        
  AddLimb("flipper","torso",4);                               
  AddLimb("shark fin","torso",4);                             
  AddLimb("lower right hand","lower right arm",3, ({A_WEAPON}));
  AddLimb("lower left hand","lower left arm",3, ({A_WEAPON}));  
  SetTown("Karak");                                             
  SetMorality(-1800);                                           
  SetReligion("Saahagoth");                                     
  SetClass("shaman");                                           
  SetSkill("sailing",1,1);                                      
  SetSkill("navigation",1,1);                                   
  SetSkill("swimming",1,1);                                     
  SetSkill("enchantment",1,1);                                  
  SetLevel(150);                                                
  SetLong(                                                      
    "This orcish shamaness' body is mutated by some horrible Saahagoth magic."
    "Her skin glistens with scales, and her mouth is lifted in shark-toothed "
    "grin on a face twisted in baleful glee. An additional pair of demonic "  
    "arms has grown from her torso, marking her as a favored one of Taigis."  
  );                                                                          
  SetGender("female");                                                        
  SetCaptainAggressiveness(150);                                              
  SetInventory( ([                                                            
    REAVER_DIR "glaive" : "wield glaive in lower right hand and lower left hand",
    STD_HACK "meat_hook" : "wield hook in left hand",                            
    INNERSEA_ENCOUNTERS "obj/rigging_knife" : "wield knife in right hand",       
  ]) );                                                                          
  SetProperty("pirate", 1);                                                      
  SetShipWander(1);                                                              
  SetCurrency("orcteef", 20000);                                                 
  SetEncounter( (:eventCheckPlayer:) );                                          
  pirates = ({ });                                                               
  SetCombatAction(50, ({                                                         
     "!cast divine wrath",                                                       
     "!cast ice lance",                                                          
     "!cast summon lesser effigy",                                               
     "!cast black circle",                                                       
  }) );                                                                          
  SetResistance(ALL_ELEMENTS,"medium");                                          
  SetResistance(WATER,"immune");                                                 
  SetResistance(SHOCK,"vulnerable");                                             

  SetMinLevel(150);
  SetMaxLevel(500);
  SetBoarder( REAVER_DIR "reaver" );
  SetPassengerAttacker( REAVER_DIR "mutant" );
  SetFirstMate( REAVER_DIR "reaver" );        
}                                                                                

void heart_beat() {
  ::heart_beat();  
  if (sizeof(GetMagicProtectionNames()) < 5) {
    switch(random(3)) {                       
    case 0:                                   
      eventForce("cast temperature shield");  
      break;                                  
    case 1:                                   
      eventForce("cast unholy guardian");     
      break;                                  
    case 2:                                   
      eventForce("cast umbral shield");       
      break;                                  
    }                                         
  }                                           
}                                             



string eventShipCombat(object *enemies) {
  object ship;                           
  foreach(object e in enemies) {         
   if (e) if (e->GetPilot())             
   if (e->GetPilot()->GetProperty("pirate")) enemies -= ({ e });
  }                                                             
  if(sizeof(enemies) == 0) { return ::eventShipWander(); }      
  ship = enemies[random(sizeof(enemies))];                      
  if(!random(5)) eventRaiseDeadSailors(ship);                   

  return ::eventShipCombat(enemies);
}                                                                             
                                                                              
// I really want to make this a spell eventually.
// raises all corpses on the enemy ship
// to fight their killer               
// mostly copied from animate dead spell
// also drains stamina from living non reavers
void eventRaiseDeadSailors(object ship) {     
  object zombie;                                                        
  string killer;                                                        
  int zombielevel;                                                      
  object pilot = ship->GetPilot();                                      
  object* inv = all_inventory(environment(pilot));                      
  message( "environment", "Shaman raises her arms and starts chanting " 
    "furiously!",environment());                                        
  message( "environment",                                               
    "A bitter, cold wind %^BLUE%^BOLD%^howls%^RESET%^ across "          
    "the deck!%^RESET%^", environment(pilot) );                         
  foreach(object target in inv) {                                       
    //debug("looping through inventory");                               
    // it's alive, kill it                                              
    if (target->GetStaminaPoints() && !target->GetProperty("pirate")    
      && !target->GetProperty("undead") )                               
    {                                                                   
      //debug("found npc or player, draining stamina");                 
      send_messages( ({ "blast" }),                                     
        "The wind $agent_verb $target_name!",                           
        this_object(), target, environment(pilot));                     
      message("environment", "You feel exhausted.", target );           
      // hopefully, this deals some reasonable damage according to level.
      target->eventReceiveDamage(this_object(),                          
        COLD, GetDamage(GetSkillLevel("evokation"),                      
        "projectile combat", target->GetDefense()) * 3, 0 ,              
        target->GetRandomLimb() );                                       
      target->AddStaminaPoints(-random(100));                            
      target->eventDisplayStatus();
    // it's dead, raise it                                               
    } else if (target->GetCorpseState()) {                                  
      //debug("found corpse, animating it");                                
      zombie = new(STD_SPELLS "obj/animate_zombie");                        
      if( !RACES_D->GetValidRace(target->GetRace()) ) {                       
        send_messages( ({ "disintegrate" }),                                  
          "$agent_name $agent_verb.", target, 0, environment(pilot) );        
        zombie->eventDestruct();                                              
        target->eventDestruct();                                              
        continue;                                                             
      }                                                                       
      zombie->SetUndead(1);                                                   
      zombie->SetUndeadType("zombie");                                        
      zombie->SetGender(target->GetGender());                                                                       
      zombie->SetRace(target->GetRace());
      zombie->SetClass(target->GetOriginalClass());
      zombie->SetLong("This is an animated corpse of " +
        add_article(target->GetRace()) +
        " that has been summoned back into the material world.");
      killer = zombie->GetKillerName();
      zombielevel = this_object()->GetLevel() - 10;
      if (zombielevel < 1) zombielevel = 1;

      zombie->SetLevel(zombielevel);
      zombie->SetShort("a waterlogged " + target->GetRace() + " zombie");

      zombie->SetId( ({ target->GetId()...,  "zombie", target->GetRace()}) );
      zombie->SetAdjectives( ({ target->GetAdjectives()..., "undead",
        "waterlogged" }) );
      zombie->SetKeyName("rotting " + target->GetRace());

      foreach(object thing in all_inventory(target)) {
        thing->eventMove(zombie);
      }
      target->eventDestruct();
      zombie->eventMove(environment(pilot));
      zombie->eventForce("wear all");
      zombie->eventForce("wield all");
      zombie->eventForce("speak Death to " + pilot->GetKeyName() + "!");
      zombie->eventForce("kill " + pilot->GetKeyName() );
    }
  }
  return;
}

