#include <lib.h>    
#include <domains.h>
#include <std.h>    
#include <damage_types.h>
inherit LIB_PIRATE;      
void DoAction();         

static void create() {
  ::create();         
  SetKeyName("handsome captain");
  SetShort("a handsome captain (elf)");
  SetId( ({ "captain", "elf" }) );     
  SetAdjectives( ({ "captain", "elf", "handsome" }) );
  SetRace("elf");                                     
   SetReligion("Kylin");
  SetTown("Haven");
  SetClass("sailor");                                 
  SetClass("fighter");                                
  SetLevel(125);                                      
  SetLong("This tall, sturdy elf has an air of authority that suggests he his a "
    "capable leader, worthy of commanding the crew of his ship. He seems no "    
    "stranger to battle, with bulging muscles and a fresh scar on his "          
    "forehead.");                                                                
  SetGender("male");                                                             
  SetSkill("enchantment", 100);                                                  
  SetCaptainAggressiveness(110);                                                 
  SetProperty("pirate", "haven");                                                  
  SetShipWander(1);                                                                
  SetInventory( ([                                                                 
    INNERSEA_ENCOUNTERS "obj/haven_hat"    : "wear hat",                               
    INNERSEA_ENCOUNTERS "obj/haven_jacket" : "wear jacket",                            
    INNERSEA_ENCOUNTERS "obj/haven_pants"  : "wear trousers",                             
    STD_WEAPON + "sword" : "wield sword",                                          
  ]) );
  SetCurrency("imperials", 2000);
  SetCombatAction(15, (: DoAction :) );
  SetResistance(ALL_ELEMENTS,"medium");
  SetResistance(ALL_PHYSICAL,"low");

  SetMinLevel(100);
  SetMaxLevel(175);
  SetBoarder(INNERSEA_ENCOUNTERS "elfwarship/elfmarine");
  SetFirstMate(INNERSEA_ENCOUNTERS "elfwarship/elfmarine");
  SetEncounterDifficulty(10); // ARGHHAVEN
}

int eventEncounterShip(object ship) {
  object targ;
  targ = ship->GetPilot();
  if(
    targ->GetRace() == "elf"
    || targ->id("jean-luc")
    || targ->id("chartercaptain")
    || targ->id("ferry captain")) {
    return 0;
  }
  return ::eventEncounterShip(ship);
}

void DoAction() {
  object pirate;
  message("enter", "An elf marine rushes to the aid "
    "of the Captain.", environment(this_object()));
  pirate = new(GetBoarder());
  pirate->SetLevel( GetLevel() - 2);
  pirate->eventMove(environment());
  call_out( (: call_other, pirate, "eventForce", "yell protect the captain!" :), 2 );
  call_out( (: call_other, pirate, "eventForce", "guard first handsome captain" :), 2 );
}

