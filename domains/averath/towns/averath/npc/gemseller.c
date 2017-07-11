#include <lib.h>
#include "../averath.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetShort("Sindal the Firestone Seller");
  SetKeyName("sindal");
  SetId( ({ "seller", "sindal" }) );
  SetAdjectives( ({ "firestone" }) );
  SetRace("human");
  SetBaseLanguage("Avera");
  SetClass("merchant");
  SetLevel(10);
  SetMorality(100);
  SetLocalCurrency("ducats");
  SetMenuItems( ([
    "firestones" : AVERATH_OBJ "firestone",
    ]) );
  SetAction(5, ({
    "!speak I sell quick returning firestones! Fast way home!",
    "!speak Tired of waiting for the ferry?  Buy a firestone!",
    "!speak Use firestones to go home!",
  }) );
  SetGender("male");
  SetLong(
    "Sindal appears to be a human from the Emirate of Yozrath. He has "
    "set up shop here in Averath selling the world famous Averath firestones, "
    "which can be used to bring a native of the island home from the mainland."
    );
  SetLimit(1);
}
  