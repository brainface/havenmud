#include <lib.h>
#include "../ungkh.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("gorg");
  SetShort("Gorg the Barkeep");
  SetId( ({ "gorg", "barkeep" }) );
  SetLong("Gorg is the barkeeper for the brothel of Ungkh.  "
          "He serves the finest of the worst ales in Kailie. "
          "A wicked scar crashes through his face, showing "
          "off his last battle.");
  SetRace("ogre");
  SetGender("male");
  SetClass("valkyr");
  SetLevel(12);
  SetMenuItems( ([ "piss" : U_OBJ + "pixie_piss",
                   "sap"  : U_OBJ + "borgla_sap" ]) );
  SetLocalCurrency("skins");

  SetMorality(0);
  SetCurrency("skins", 4500);
  }
