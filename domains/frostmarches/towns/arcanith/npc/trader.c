#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include "../ruins.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("presmyr");
  SetId( ({ "presmyr", "arcanith_wander", "trader" }) );
  SetShort("Presmyr the Trader");
  SetLong("Presmyr is a goden merchant from Keryth that has settled into "
          "the ruins of Arcanith with the kobolds.  No one is quite sure "
          "as to why someone would do this."
  );

  SetRace("goden");
  SetGender("male");
  SetBaseLanguage("Koblich");
  // mahkefel 2014: removed. he is now arcanithily.
  // could be changed back but probs easier this way.
  //SetTown("Keryth");
  SetMorality(-100);
  SetClass("rogue");
  SetLevel(15);
  AddCurrency("senones", random(100)+5);

  SetStorageRoom(ROOM "/storage/store_store");
  SetLocalCurrency("senones");
  SetVendorType(VT_ALL);
  SetMaxItems(150);
  SetMaxSingleItem(20);

  // from original file
  SetLimit(1);
  SetWander(20);
  SetGender("male");
  SetFriends( ({ "lotai", "arcanith_pack_mule" }) );
  SetCombatAction(5, ({
    "!guard lotai"
  }) );

  SetFirstCommands(({ "lead mule", "lead lotai" }) );
  SetAction(10, ({
    "!say Sell it to me, Kobolds!",
    "!say I'll take whatever you find.",
    "!smirk",
    "The trader gets a sudden crazed look in his eye.",
    "!giggle crazily",
    "!grin stupidly",
    "!smirk fiendishly",
  }) );

}

