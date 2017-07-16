#include <lib.h>
#include <vendor_types.h>
#include <domains.h>     
#include <std.h>         
#include "store.h"       

inherit LIB_VENDOR;

void makeChest();

static void create() {
  vendor::create();   
  SetKeyName("Feyr");
  SetId( ({ "Feyr", "steelweaver" }) );
  SetShort("Feyr the steelweaver");
  SetAdjectives( ({ "the","feyr" }) );         
  SetLong(
    "Feyr is a thin, wiry woman with mousy hair. Her fingers are lined with scabs "
    "and scars, and her fingernails are black with bruises from the constant "
    "punishment of weaving chainmail. What sacrifices she has made in trade are "
    "apparent, as her armour is sought out throughout the world for its flexibility "
    "and protection. "
  );
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Eltherian");
  SetLocalCurrency("imperials");
  SetMorality(100);
  SetClass("merchant");
  SetLevel(50);
  SetStorageRoom(STORE_DIR + "store_chain");
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
