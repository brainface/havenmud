#include <lib.h>
#include <vendor_types.h>
#include <domains.h>     
#include <std.h>         
#include "store.h"       

inherit LIB_VENDOR;

void makeChest();

static void create() {
  vendor::create();   
  SetKeyName("kelan");
  SetId( ({ "kelan", "armoursmith" }) );
  SetShort("Kelan the burly armoursmith");
  SetAdjectives( ({ "burly" }) );         
  SetLong(                                
    "Kelan is a tall, powerfully built man. His muscles, trained to perfection "
    "after countless years of pounding metal in his smithy, bulge almost to "   
    "the point of ripping his sweat-stained shirt. His armour is known to be "  
    "of superb quality throughout the Southern Coast, proven by the renound "   
    "prestige of some of his clientele."                                        
  );                                                                            
  SetRace("human");                                                             
  SetGender("male");
  SetBaseLanguage("Eltherian");
  SetLocalCurrency("imperials");
  SetMorality(100);
  SetClass("merchant");
  SetLevel(50);
  SetStorageRoom(STORE_DIR + "store_heavy");
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
