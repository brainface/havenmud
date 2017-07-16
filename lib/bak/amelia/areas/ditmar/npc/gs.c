#include <lib.h>
#include <vendor_types.h>
inherit LIB_VENDOR;
#include "ditmar.h"

static void create() {
   vendor::create();
   SetTown("Ditmar");
   SetKeyName("wayt");
   SetShort("Wayt, the general storekeeper");
   SetId( ({ "wayt","keeper","storekeeper" }) );
   SetAdjectives( ({ "general","store" }) );
   SetLong("Wayt is strange mar in the way that he doesn't mind "
           "travelling to other towns to buy and sell goods, as "
           "long as he is inside a covered wagon or other such "
           "device.  He is taller than most mar, and stands "
           "straight.  He would probably be willing to sell you "
           "something if you asked.");
   SetRace("mar");
   SetClass("merchant");
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetLevel(15);
   SetGender("male");
   SetVendorType(VT_ALL);
   SetLocalCurrency("kuique");
   SetStorageRoom(D_ROOM + "/str_wayt");
   SetMaxSingleItem(3);
   SetMorality(-3);
   SetCurrency("kuique",300000);
   SetInventory( ([
                    D_OBJ + "/robe" : "wear robe",
               ]) );
}