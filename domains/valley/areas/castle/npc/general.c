#include <lib.h>
#include <vendor_types.h>
inherit LIB_VENDOR;
#include "../castle.h"

static void create() {
   vendor::create();
   SetKeyName("bulky storekeeper");
   SetShort("a large storekeeper");
   SetId( ({ "storekeeper","storekeep","keeper","keep" }) );
   SetAdjectives( ({ "large","bulky","general","store","tall",
                     "amiable" }) );
   SetLong("The general store keeper looks as if he spends a lot of "
           "time moving his items from place to place, as he looks like "
           "he's been exerting some amount of effort recently, but he "
           "doesn't look weakened by it.  He is tall and very bulky, "
           "but has a generally amiable atmosphere to him.");
   SetRace("dwarf");
   
   SetGender("male");
   SetClass("fighter");
   SetSkill("bargaining",3,2);
   SetLevel(22);
   SetMorality(-15);
   SetVendorType(VT_ALL);
   SetLocalCurrency("nuggets");
   SetStorageRoom(VC_ROOM + "/str_gen");
   SetCurrency("nuggets", 10 + random(10));
   SetMaxSingleItem(8);
}
