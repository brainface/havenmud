#include <lib.h>
#include "../wood.h"
inherit LIB_MAYOR;

static void create() {
  mayor::create();
  SetKeyName("Questeli Desatalaim");
  SetShort("Questeli Desatalaim the Elder of the Wood");
  SetMorality(300);
  SetId( ({ "questeli", "desatalaim", "elder" }) );
  SetAdjectives( ({ "questeli", "elder" }) );
  SetLong( 
    "Questeli Desatalaim is one of the clan elders. "
    "He is responsible for promotion of the citizens into the ranks of the "
    "elders of the Havenwood and also maintains the right to allow others "
    "not born in the Havenwood to reside there."
    );
  SetGender("male");
  SetTown("Havenwood");
  SetRace("wild-elf");
  SetClass("druid");
  SetLevel(60);
  SetTax(1);
  SetLocalCurrency("imperials");
  SetSpellBook( ([
    "tangle" : 100,
    "plant strike" : 100,
    "vine wall" : 100,
  ]) );
  SetCombatAction(10, ({ 
     "!cast tangle", "!cast plant strike", "!cast tangle", "!cast vine wall", "!cast plant strike"  
   }) );
  SetFirstCommands( ({ "cast vine wall", "cast vine wall", "cast vine wall", "cast vine wall" }) );
  SetTownRanks( ({
      ({ "Slave"   , "Slave" }),  /* Placeholder for SocialRank 0 */
      ({ "Citizen" , "Citizen" }),
      ({ "Hunter"  , "Huntress" }),
      ({ "Woodsman", "Woodswoman" }),
      ({ "Keeper"  , "Keeper" }),
      ({ "Forester", "Forester" }),
      ({ "Elder"   , "Elder" }),
      }) );      
}
