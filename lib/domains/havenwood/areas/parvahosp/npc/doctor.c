#include <lib.h>
#include "../ph.h"
inherit LIB_NPC;

int HealPeople();

static void create() {
  ::create();
  SetKeyName("doctor");
  SetShort("an Eclatish doctor");
  SetId( ({ "doctor" }) );
  SetAdjectives( ({ "eclatish" }) );
  SetLong(
     "Tired, yet perservering through the long work day, this Eclatish "
     "doctor works effortlessly at healing scores of patients each "
     "hour. The powers of these Eclatish priests are known throughout "
     "the area; they have mastered many of the healing skills."
  );
  SetRace("muezzin"); 
  SetClass("priest");
  SetLevel(55);
  SetReligion("Eclat","Eclat");
  SetGender( ({ "male","female" })[random(2)]);
  
  SetSpellBook( ([
    "mend"     : 100,
    "fortify"  : 100,
  ]) );
  SetMorality(1000);
  SetAction(5, (: HealPeople :) );
  SetCombatAction(5, ({ 
    "!cast fortify" 
  }) );
  switch(random(4)) {
    case 0:
    SetInventory( ([
      PO + "/sm_robes" : "wear robes",
//      PO + "/bandage" : 2,
      PO + "/vialdisease_f" : 1,
    ]) );
    break;
    case 1:
    SetInventory( ([
      PO + "/sm_robes" : "wear robes",
//      PO + "/bandage" : 4,
      PO + "/viallimb_f" : 1,
    ]) );
    break;
    case 2:
    SetInventory( ([
      PO + "/sm_robes" : "wear robes",
//      PO + "/bandage" : 2,
      PO + "/vialpois_f" : 2,
    ]) );
    break;
    case 3:
    SetInventory( ([
      PO + "/sm_robes" : "wear robes",
//      PO + "/bandage" : 4,
      PO + "/vialsight_f" : 2,
    ]) );
    break;
  }
  SetCurrency("cuicui",50);
  SetCurrency("oros",1);
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
