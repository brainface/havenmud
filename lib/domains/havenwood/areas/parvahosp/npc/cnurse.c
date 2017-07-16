#include <lib.h>
#include "../ph.h"
inherit LIB_NPC;
int HealPeople();

static void create() {
   ::create();
   SetKeyName("nurse");
   SetShort("an Eclatish nurse");
   SetId( ({ "nurse" }) );
   SetAdjectives( ({ "eclatish" }) );
   SetLong(
     "Smiling tirelessly, this Eclatish nurse specialized in the care of " 
     "children and infants. She appears just an knowledgable as the "
     "other workers, and is very strong."
   );
   
   SetRace("human");
   SetClass("priest");
   SetSkill("melee combat",1,1);
   SetLevel(20);
   SetGender( ({ "male","female" })[random(2)]);
   SetReligion("Eclat","Eclat");
   SetMorality(1000);
   SetSpellBook( ([
     "mend"    : 100,
     "fortify" : 100,
   ]) );
   SetAction(3, (: HealPeople :) );
   SetCombatAction(5, ({ 
     "!cast fortify",
     "!cast mend",
   }) );
   SetInventory( ([
     PO + "/robes" : "wear robes",
     PO + "/bandages" : 4,
     PO + "/block" : 3,
     PO + "/horse" : 2,
   ]) );
   SetCurrency("cuicui",10);
   SetCurrency("oros",50);
}

int HealPeople() {
  object array blargs;
  object blarg;
  blargs = all_inventory(environment(this_object()));
  blargs = filter(blargs, (: living :));
  blarg = blargs[random(sizeof(blargs))];
  eventForce("cast mend on " + blarg->GetKeyName());
  return 1;
}
