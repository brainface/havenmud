#include <lib.h>
#include "../rome.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("Druscilla");
  SetShort("Druscilla, the owner of the Broken Stine");
  SetId( ({ "brook", "owner", "waitress", "barkeep" }) );
  SetLong("Druscilla is a fine young lady that seems to have found "
          "her place. After the local authorities closed down her "
          "original employer, the Groggy Sailor, she stepped in and helped "
          "to convince the government to allow her to re-open "
          "if she kept the rogueish scum out that had been "
          "frequenting the tavern before.");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetClass("merchant");
  SetLanguage("Imperial", 100, 1);
  SetGender("female");
  SetLevel(6);
  SetMenuItems( ([ 
  	"water" : ROME_OBJ + "water",
    "beer"  : ROME_OBJ + "beer" 
    ]) );
  SetLocalCurrency("imperials");
  SetMorality(-200);
  SetCurrency("imperials", 200);
  SetInventory( ([
    ROME_OBJ "stola_poor" : "wear stola",
  ]) );

}
