#include <lib.h>
#include <vendor_types.h>
#include <domains.h>     
#include <std.h>         
#include "store.h"       

inherit LIB_VENDOR;

void makeChest();

static void create() {
  vendor::create();   
  SetKeyName("Nicols");
  SetId( ({ "Nicols", "apprentice" }) );
  SetShort("Nicols the apprentice");
  SetAdjectives( ({ "the","nicols" }) );         
  SetLong(
    "Nicols is a pudgy half-elf of medium height, topped with a mop of red hair. "
    "After a long apprenticeship with Kelan, he's been entrusted with crafting "
    "lighter armours worn by mercenaries and others who aren't full knights and "
    "don't mind if their breastplate isn't quite the best it can be."
  );
  SetRace("half-elf");
  SetGender("male");
  SetBaseLanguage("Eltherian");
  SetLocalCurrency("imperials");
  SetMorality(100);
  SetClass("merchant");
  SetLevel(50);
  SetStorageRoom(STORE_DIR + "store_plate");
  SetMaxSingleItem(50);
  SetProperty("no bump", 1);
  SetVendorType(VT_ARMOUR);

  call_out( (: makeChest :), 0);
}
// take over one existing, unowned lootchest
//   in my room.
void makeChest() {
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
