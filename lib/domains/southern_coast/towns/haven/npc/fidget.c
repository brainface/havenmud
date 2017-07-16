#include <lib.h>
#include <vendor_types.h>
#include <std.h>
#include "haven.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("fidget");
  SetId( ({ "fidget" }) );
  SetShort("Fidget, the clothier");
  SetRace("gnome");
  SetClass("merchant");
  SetGender("male");
  RemoveLanguage("Nibelungen");
  SetLanguage("Eltherian",100,1);
  SetMorality(50);
  SetLevel(6);
  SetLocalCurrency("imperials");
  SetLong("Fidget is a local clothier. He deals in fine clothing "
          "for all budgets.");
  SetMenuItems( ([
    "belt" : STD_CLOTHING + "belt/blt",
    "cape" : STD_CLOTHING + "cloak/velvet_cape",
    "fur coat" : STD_CLOTHING + "coat",
    "leather jerkin" : STD_CLOTHING + "shirt/leather_jerkin",
   ]) );
 }
