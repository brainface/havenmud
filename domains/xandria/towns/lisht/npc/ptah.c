//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include "../lisht.h"
inherit LIB_VENDOR;

static void create() {
  ::create();
  SetKeyName("ptah");
  SetStorageRoom(LISHT_ROOM "gnoll/shop_storage");
  SetMaxSingleItem(100);
  SetVendorType(VT_ALL);
  SetRace("gnoll");
  SetClass("merchant");
  SetLevel(25);
  SetMorality(-400);
  SetShort("Ptah the Merchant");
  SetId( ({ "Ptah", "shopkeep", "Merchant" }) );
  SetLong(
    "Ptah spends most of his time here at the bazaar, helping "
    "people part with their goods and money. He enjoys the tinkling "
    "of coins passing through his fingers and into his pockets."
  );
  SetGender("male");
  SetBaseLanguage("Rehshai");
  SetAction(6, ({
 "!speak You should <ask ptah to browse>",
 "!speak You could <ask ptah to sell> if you see something you like.",
 "!speak You could <ask ptah to buy> your items!",
 "!speak I'd be happy to barter with you!",
        }) );
  SetCombatAction(8, ({
    "!yell Help! I am being attacked!",
    "!yell Guards!",
  }) );
  SetLocalCurrency("deben");
  SetTown("Lisht");
  SetMaxItems(1000);
  SetLimit(1);
}
