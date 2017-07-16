#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include <std.h>
#include "store.h"

inherit LIB_VENDOR;

void makeChest();

static void create() {
  vendor::create();
  SetKeyName("tornys");
  SetId( ({ "tornys", "dealer" }) );
  SetShort("Tornys the leather dealer");
  SetAdjectives( ({ "leather" }) );
  SetLong(
    "Tornys is a small, stout man with a huge grey moustache. He collects and "
    "sells leather items, and can usually be found in his store near Haven "
    "town. His products are known to be very tough, but flexible enough "
    "to cause little discomfort."
  );
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Eltherian");
  SetLocalCurrency("imperials");

  SetMorality(10);
  SetClass("merchant");
  SetLevel(30);
  AddCurrency("imperials", random(100)+1);
  SetStorageRoom(STORE_DIR + "store");
  SetProperty("no bump", 1);
  SetVendorType(VT_ARMOUR);

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

