#include <std.h>
#include <lib.h>
#include "../ph.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("doctor");
  SetId( ({ "doctor" }) );
  SetShort("a sick doctor");
  SetAdjectives( ({ "sick" }) );
  SetGender( ({ "male","female" }) [random(2)]);
  SetLong(
    "After working long hours in the hospital, this unfortunate doctor "
    "came down ill. Tired and pained, " + nominative(this_object()) +
    " waits out the disease."
  );
  SetRace( ({ "muezzin","halfling","gelfling" })[random(3)]);
  SetClass("priest");
  SetLevel(10);
  
  SetReligion("Eclat","Eclat");
  SetMorality(1000);
  SetCurrency("cuicui",14);
  SetCurrency("oros",10);
  SetSpellBook( ([
    "fortify" : 100,
    "mend" : 100,
   ]) );
   SetAction(2, ({ 
     "!cast mend on me" 
   }) );
   SetCombatAction(10, ({ 
     "!cast fortify",
   }) );
   SetInventory( ([
     STD_GERMS + "pflu" : 1,
   ]) ); 
}
