#include <lib.h>
#include <vendor_types.h>
#include "../gurov.h"
inherit LIB_VENDOR;

void makeChest();
static void create() {
  ::create();
  SetKeyName("torgal");
  SetShort("Torgal the Shopkeep");
  SetId( ({ "torgal", "shopkeep" }) );
  SetVendorType(VT_ALL);
  SetGender("male");
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetLong(
    "Torgal the Shopkeep is a friendly individual who is willing to make a "
    "profit wherever one can be found. His shop has a long track record of "
    "pumping money into the local economy while still providing useful "
    "services like torchlight to travellers."
    );
  SetLocalCurrency("rubles");
  SetStorageRoom(GUROV_ROOM "storeroom");
  SetMaxSingleItem(30);
  SetMaxItems(500);
  SetClass("merchant");
  SetLevel(15);
  SetMorality(50);
  call_out( (: makeChest :), 0);
}

// take over one existing, unowned lootchest
//   in my room.
void makeChest() {
  object chest;
  // make a chest
  //chest = new(STD_OBJ "lootchest");

  // if I'm somewhere
  if ( !environment(this_object()) ) return;

  foreach( object thing in all_inventory(environment(this_object())) ) {
    if ( member_array("loot_chest", thing->GetId() ) != -1) {
      if(!thing->GetOwner()) {
        thing->SetOwner(this_object());
        return;
      }
    }
  }
}
