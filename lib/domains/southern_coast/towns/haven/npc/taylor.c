#include <lib.h>
#include <std.h>
#include "../haven.h"
#include <vendor_types.h>
inherit LIB_OLD_VENDOR;

void makeChest();

static void create() {
  ::create();
  SetKeyName("taylor");
  SetId( ({ "taylor" }) );
  SetShort("Taylor, the shopkeep");
  SetLong("Taylor is a reputable shopkeep that has been in Haven "
          "since before most of the oldest people in town were born. "
          "His ethics and style are above question.");
  SetMorality(100);
  SetRace("elf");
  SetClass("merchant");
  SetLevel(5);
  SetGender("male");
  SetVendorType(VT_ALL);
  SetLocalCurrency("imperials");
  SetStorageRoom(H_ROOM "storage_rooms/str_sh");
  SetMaxSingleItem(12);
  SetMaxItems(500);
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

