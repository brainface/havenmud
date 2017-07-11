#include <lib.h>
#include "../ninja.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
  ::create();
  SetKeyName("kikuchiyo");
  SetShort("Kikuchiyo the outfitter");
  SetId( ({ "kikuchiyo", "outfitter", "ninja",
        "shopkeep" }) );
  SetRace("human");
  SetClass("merchant");
  SetLevel(25);
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetGender("male");
  SetCurrency("koken", random(1000));
  SetMorality(-200);
  SetStorageRoom(N_ROOM "ninjastore");
  SetTown("Tairi");
  SetLocalCurrency("koken");
  SetVendorType(VT_ALL);
  SetMaxSingleItem(50);
  SetMaxItems(400);
  SetLong("Kikuchiyo is the outfitter for the ninjas."
          " He has trained many years as a ninja, but in"
          " his old age all he wants to do is relax"
          " so he has taken to selling equipment to"
          " other ninjas.");
  SetAction(1, ({
       "!speak Through me, you can be equipped",
       "!speak I have what you need for your next mission?",
    }) );
}
