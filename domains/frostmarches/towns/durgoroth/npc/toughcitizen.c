#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../durgoroth.h"
inherit LIB_SENTIENT;
 
void PossibleAttack();

static void create() {
  sentient::create();
  SetKeyName("tough survivor");
  SetRace("daemon");
  SetClass("fighter");
  SetLevel(200 + random(25));
  SetGender("male");
  SetShort("a tough looking daemon survivor");
  SetId( ({ "daemon","survivor","fighter","durg_wander",
            "durg_combat" }) );
  SetAdjectives( ({ "tough", "daemon" }) );
  SetLong("This daemon is one of resilience. His arms"
          " and legs are covered in scars and fresh"
          " gashes and cuts litter his face. He looks"
          " more than capable of taking care of himself"
          " and one should be fearful unless well trained"
          " in combat.");
  SetWander(5);
  //SetAction(99, (: PossibleAttack :) );
  SetCombatAction(50, ({
    "!disorient",
    "!disarm",
    "!disarm",
    "!roar",
    }) );
  SetReligion("Saahagoth","Saahagoth");
  SetTown("Durgoroth");
  SetMorality(-2000);
//  SetEncounter( (: PossibleAttack :) );
  SetInventory( ([
     "/std/weapon/melee/brass_knuckles" : "wield knuckles",
     "/std/weapon/hack/large_axe" : "wield axe",
     DURG_OBJ "cit_chain" : "wear suit",
     ]) );
  SetCurrency("crystals", 2000);
  }


void PossibleAttack() {
  object thing;
  if (thing->GetMorality() > 500) {
  eventForce("attack " + thing->GetKeyName());
  }
  return;
}

