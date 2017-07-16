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
  SetLong(
    "Generations of decay have caused this man's flesh to rot away. He is "
    "nothing more than a skeleton now, wandering the caves below the Averath "
    "sewer system with no real goal. His skeletal structure looks solid "
    "enough to withstand combat, and he looks ready to fight."    
  );  
  SetRace("human");
  SetClass("warrior");
  SetGender("male");
  SetLevel(45);  
  AddCurrency("ducats", random(50));
  SetCombatAction(1, ({
    "!groan",    
  }) );  
  SetInventory( ([         
  ]) );
  SetEncounter(0);
  SetMorality(-400);
}