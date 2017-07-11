// Island
// Aerelus

#include <lib.h>
#include "../island.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("herman");
  SetShort("Herman the Mad");
  SetId( ({ "herman" }) );
  SetAdjectives( ({"mad"}) );
  SetLong(
    "This old, tall man looks like he has been here for a very long time. "
    "His long gray beard reaches past his stomach, and looks like it hasn't "
    "been washed in months, if not longer. While time has clearly taken its "
    "toll on this man, he is very well built and looks very capable of "
    "defending himself."    
  );  
  SetRace("human");
  SetClass("fighter");
  SetLevel(8);
  SetGender("male");
  SetReligion("agnostic");
  SetBaseLanguage("Enlan");
  SetMorality(0);  
  SetInventory( ([
    ISLAND_OBJ "loincloth" : "wear loincloth",    
  ]) );
  SetAction(6, ({
    "!say Are you here for me birthday? Did ya bring me a present?",
    "!say Ahh, it must be Toastday.",
    "!jig",
  }) );
  SetCombatAction(10, ({
    "!say Heye! That tickles!",
    "!bwah",
  }) );
 }
