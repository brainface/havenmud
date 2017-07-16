#include <lib.h>
#include <vendor_types.h>
#include "../rome.h"
inherit LIB_VENDOR;

static void create() {
  ::create();
  SetKeyName("tylus");
  SetShort("Tylus of Sanctum, Merchant Prince");
  SetId( ({ "tylus", "merchant", "prince" }) );
  SetAdjectives( ({ "merchant" }) );
  SetRace("human");
  SetClass("merchant");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetGender("male");
  SetMorality(-40);
  SetLong("Tylus of Sanctum is the dominant merchant of Sanctum. "
          "He is always willing to buy and sell goods, especially "
          "those that he can make a profit on.");
  SetVendorType(VT_ALL);
  SetLevel(1);
  SetStorageRoom(ROME_ROOM + "_shop");
  SetLimit(1);
  SetLocalCurrency("imperials");
  SetSkill("bargaining", 1, 1);
  SetMaxSingleItem(400);
  SetMaxItems(10000);
  SetInventory( ([
    ROME_OBJ "toga_rich" : "wear toga",
  ]) );
}
