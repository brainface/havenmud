/* A naga swordperson */
// mahkafel AUGUST 2010
#include <lib.h>                                               
#include <damage_types.h>                                      
#include <armour_types.h>
inherit LIB_NPC;                                               

void eventSpecial();
void eventWasp();

static void create() {
  mapping inventory;  

  npc::create();
  SetKeyName("gardener");
  SetId( ({ "bisan","gardener" }) );
  SetAdjectives( ({ "waspish" }) );               
  SetShort("a waspish gardener");                
  SetLong("SECRETELY A WASP WOMAN OH NO.");                                                        
  SetGender("female");                                                         
  SetRace("human");
  SetBaseLanguage("tai");
  SetClass("druid");                                                         
  SetSkill("poison magic",1);
  SetLevel(70);                                                             
  /*
  // give random weapons
  switch(random(2)) {   
    case 0:             
      inventory = ([    
        PLANE_OBJ "fire_scimitar" : "wield scimitar",
      ]);                                            
    break;                                           
    case 1:                                          
      inventory = ([                                 
        PLANE_OBJ "fire_axe" : 2                     
      ]);                                            

  }                                                  
  // give armour                                     
  inventory[PLANE_OBJ "obsidian_armour"] = "wear breastplate";
  */
  SetAction(30, (: eventWasp :) );
  SetCombatAction(15, (: eventSpecial :) );
  //SetEncounter(100);                      
  //SetFirstCommands( ({"wield axes"}) );// doesn't matter if this fires when he has no axes
  //SetInventory(inventory);                                                                
  //SetMeleeAttackString("flaming hand");                                                   
  //SetMeleeDamageType(HEAT);
  SetProperty("wasp_form",1); // 1 == human, 2 == wasp                                                               
  SetResistance(SHOCK|MAGIC, "weakness");
  SetResistance(POISON|HEAT|ALL_PHYSICAL, "medium");
}

//TODO: something more interesting. constrict?
void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  send_messages("immolate",
    "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name "
    "with a huge pillar of flame!", who, target, environment() );
  target->eventReceiveDamage(who, HEAT, random(500), 0,
    target->GetRandomLimb("head") );
  return;
}

void eventWasp() {
  if(GetProperty("wasp_form")==1) {
    send_messages("morph",
      "$agent_name%^GREEN%^ $agent_verb%^GREEN%^ into a large, angry wasp!",
      this_object(),0,environment() );
    SetKeyName("wasp");
    SetId( ({ "bisan","wasp" }) );
    SetAdjectives( ({ "huge" }) );               

    SetRace("wasp");
    SetShort("a huge wasp");
    SetLong("SECRETELY A WOMAN WASP OH NOES");
    SetProperty("wasp_form",2);
  } else {
    send_messages("morph",
      "$agent_name%^GREEN%^ $agent_verb%^GREEN%^ into a slim, angry gardener!",
      this_object(),0,environment());
    SetKeyName("gardener");
    SetId( ({ "bisan","gardener" }) );
    SetAdjectives( ({ "waspish" }) );               
 
    SetRace("human");
    SetShort("a waspish gardener");
    SetLong("SECRETELY A WASP WOMAN OH NOES");
    SetProperty("wasp_form",1);
  }

}
