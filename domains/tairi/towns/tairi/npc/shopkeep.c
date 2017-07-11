/* The shopkeep of tairi */
#include <lib.h>
#include "../tairi.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
  ::create();
  SetKeyName("tetsu");
  SetShort("Acoma Tetsu, the local merchant");
  SetRace("human");
  SetClass("merchant");
  SetLevel(25);
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetGender("male");
  SetCurrency("koken", random(1000));
  SetMorality(-200);
  SetId( ({ "acoma", "tetsu", "merchant", "citizen" }) );
  SetAdjectives( ({ "acoma", "local" }) );
  SetStorageRoom(TAI_RI_ROOM "shop_store");
  SetTown("Tairi");
  SetLocalCurrency("koken");
  SetVendorType(VT_ALL);
  SetMaxSingleItem(50);
  SetMaxItems(400);
  SetLong("Acoma Tetsu comes from one of the oldest clans of Tairi. "
          "His wealth is renown through all of the Tai valley, and his "
          "skills as a shrewd bargainer are legendary.");
  SetAction(5, ({
       "!speak Have you something to sell me?",
       "!speak Do you have something I would want to buy?",
       "!emote looks around in a bored fashion.",
       "!speak Can you afford my wares?",
    }) );
}
