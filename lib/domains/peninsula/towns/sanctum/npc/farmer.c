#include <lib.h>
#include <std.h>
#include "../rome.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("bertal");
  SetShort("Bertal the Farmer");
  SetId( ({ "bertal", "farmer" }) );
  SetAdjectives( ({ "farmer" }) );
  SetRace("human");
  SetGender("male");
  SetClass("merchant");
  SetLevel(1);
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetLong("Bertal the farmer is a fairly young man of less than "
          "impressive abilities as a farmer. What he does excel "
          "at is selling farm produce to the citizens of Sanctum.");
  SetTown("Sanctum");
  SetLocalCurrency("imperials");
  SetMorality(75);
  SetLimit(1);
  SetMenuItems( ([
    "potato" : STD_FARMING "temperate/potato",
    "carrot" : STD_FARMING "temperate/carrot",
    "raddish" : STD_FARMING "temperate/raddish",
    ]) );
  SetAction(6, ({
    "!yell Fresh produce!  Get it here!",
    "!say Potatoes, Carrots, and Raddishes here!",
    }) );
  SetInventory( ([
    ROME_OBJ "toga" : "wear toga",
  ]) );
}
