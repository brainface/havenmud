#include <lib.h>  
#include <domains.h>
#include <std.h>    
#include <damage_types.h>
inherit LIB_PIRATE; 
int eventCheckPlayer();  

static void create() {
  ::create();         
  SetKeyName("elf marine");
  SetShort("an elven marine");
  SetId( ({ "marine", "elf" }) );
  SetAdjectives( ({ "marine", "elf", "elven" }) );
  SetRace("elf");                                 
  SetClass("sailor");                             
  SetClass("fighter");                            
  SetLevel(125);                                  
  SetLong("This tall, sturdy elf is covered in blood and scars. He appears to be "
    "tough and is no stranger to battle, with bulging muscles and a fresh scar on his "
    "forehead. On his left breast he has a tattoo of a dragon wrapping around a "      
    "balance.");                                                                       
  SetGender("male");                                                                   
  SetCaptainAggressiveness(110);                                                       
  SetProperty("pirate", "haven");                                                        
  SetShipWander(1);                                                                    

  SetInventory( ([
    STD_WEAPON + "sword" : "wield sword",
    INNERSEA_ENCOUNTERS "obj/haven_hat"    : "wear hat",                               
    INNERSEA_ENCOUNTERS "obj/haven_pants"  : "wear trousers", 
  ]) );                                  
  SetCurrency("imperials", 2000);        
  SetSkill("enchantment", 100);          

  SetResistance(ALL_ELEMENTS,"medium");
  SetResistance(ALL_PHYSICAL,"low");

  SetMinLevel(100);
  SetMaxLevel(175);
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

