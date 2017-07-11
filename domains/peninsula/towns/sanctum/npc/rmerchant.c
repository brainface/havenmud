#include <lib.h>
#include <vendor_types.h>
#include "../rome.h"
inherit LIB_VENDOR;

static void create() {
  ::create();
  SetKeyName("Frel");
  SetShort("Frel the Shadowed");
  SetId( ({ "frel" }) );
  SetAdjectives( ({ "shadowed" }) );
  SetRace("human");
  SetClass("rogue");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetGender("male");
  SetMorality(-40);
  SetLong("Frel is an old man, he is missing several fingers and an ear. Despite his "
          "demeanor he is always willing to buy and sell goods, especially "
          "to his fellow rogues.");
  SetVendorType(VT_ALL);
  SetLevel(1);
  SetStorageRoom(ROME_ROOM + "_rshop");
  SetLimit(1);
  SetLocalCurrency("imperials");
  SetSkill("bargaining", 1, 1);
  SetMaxSingleItem(400);
  SetMaxItems(10000);
  SetInventory( ([
    ROME_OBJ "toga_evil" : "wear toga",
  ]) );
}
