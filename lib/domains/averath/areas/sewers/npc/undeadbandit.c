// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include "../sewers.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("undead bandit");
  SetShort("an undead bandit");
  SetId( ({ "bandit" }) );
  SetAdjectives( ({ "undead" }) );
  SetUndead(1);
  SetLong(
    "Generations of decay have caused this man's flesh to rot away. He is "
    "nothing more than a skeleton now, wandering the caves below the Averath "
    "sewer system with no real goal. His skeletal structure looks solid "
    "enough to withstand combat, and he looks ready to fight."    
 	  );  
  SetRace("human");
  SetClass("rogue");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetLevel(45);  
  AddCurrency("ducats", random(150)+1);
  SetCombatAction(1, ({
    "!groan",    
  	}) );  
  SetInventory( ([         
  	]) );
  SetEncounter(0);
  SetMorality(-400);
}