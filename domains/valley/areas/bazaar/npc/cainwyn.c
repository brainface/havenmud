//
// Cainwyn the trinket vendor
// Created by Athalie
//
#include <lib.h>
#include <vendor_types.h>
#include "../bazaar.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
   SetKeyName("cainwyn");
   SetId( ({ "cainwyn", "vendor", "cainwyn the trinket vendor" }) );
   SetAdjectives( ({ "trinket" }) );
   SetShort("Cainwyn the trinket vendor");
   SetLong("This bored half-elf has stringy brown hair and pale olive "
     "skin. She looks to be a little underfed and rarely makes eye "
     "contact with anyone.");
  
   SetRace("half-elf");
   SetClass("merchant"); 
   SetLevel(8);
   SetGender("female");
   SetAction(3, ({
     "!emote sighs heavily.",
   }) );
   SetLocalCurrency("rupies");
   SetCurrency("rupies",random(50));
   SetStorageRoom(BAZAAR_ROOM + "trinkstore");
   SetMaxItems(60);
   SetMaxSingleItem(10);
   SetVendorType(VT_GEM | VT_TREASURE);
}
