// Urien 110613 - Cloth/Leather Vendor
// Changed FileName, Long, Actions
// Changed Pathing - More "Solid" Now

#include <lib.h>
#include <vendor_types.h>
#include "../goblins.h"

inherit LIB_VENDOR;

static void create() {
  ::create();
  SetKeyName("Temu");
  SetId( ({ "temu", "dealer" }) );
  SetShort("Temu the leather dealer");
  SetAdjectives( ({ "leather" }) );
  SetLong(
    "Temu is a small, green skinned hairy goblin. An "
    "elongated nose sticks out from his dark black "
    "eyes. A seasoned adult Goblin with a few winters "
    "past his prime, Temu is usually found in his yurt "
    "in Kresh occupying himself with local dealings. His "
    "trade ethics only welcome a certain standard and "
    "he is known for his wares of quality. He seems "
    "well settled in despite the Goblin nomad lifestyle."
  );
  SetRace("goblin");
  SetGender("male");
  SetLocalCurrency("rounds");
  SetMorality(-10);
  SetClass("merchant");
  SetLevel(30); 
  AddCurrency("rounds", random(100)); 
  SetStorageRoom(STORE_DIR + "store");
  SetProperty("no bump", 1);  
  SetVendorType(VT_ARMOUR);  
}