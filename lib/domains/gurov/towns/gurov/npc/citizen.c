#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_NPC;

void eventRogue();

static void create() {
  int setup;
  ::create();
  SetKeyName("citizen");
  SetId( ({ "citizen", "gurov_citizen" }) );
  SetShort("a citizen of the Principality of Gurov");
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetGender(random(2) ? "male" : "female");
  SetLong(
    "This citizen seems intent on going about business within the city."
    );
  SetMorality(50);
  /* deliberately no SetClass */
  switch(setup = random(4)) {
    case 0:
      AddInventory(GUROV_OBJ "inn2/cigar", 2);
      SetClass("rogue");
      break;
    case 1:
      AddInventory(STD_KNIFE "small_knife", "wield knife");
      SetClass("rogue");
      break;
    case 2:
      AddInventory(STD_MEAL "fish/guppy", 3);
      AddInventory(GUROV_OBJ "newbie_pole", "wield pole");
      SetClass("merchant");
      break;
    case 3:
      AddInventory(STD_MEAL "food/cheese", 2);
      SetClass("merchant");
      break;
    }
  SetLevel(5);
  SetCurrency("rubles", 100);
  SetWander(5);
  SetLimit(6);
  if (setup == 1) SetAction(5, (: eventRogue :) );
}

void eventRogue() {
  object *targets;
  object target;
  if (!environment()) return;
  
  targets = all_inventory(environment());
  targets = filter(targets, (: living :) );
  targets -= ({ this_object() });
  if (!sizeof(targets)) return;
  
  if (GetInCombat()) eventWimpy(); /* Attempt to flee! */
  
  target = targets[random(sizeof(targets))];
//  debug(identify(target));
  eventForce("steal money from " + target->GetKeyName());
  return;
}
