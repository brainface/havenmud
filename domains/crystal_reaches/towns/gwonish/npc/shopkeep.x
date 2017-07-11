#include <lib.h>
#include <std.h>
#include <vendor_types.h>
#include "../gwonish.h"
inherit LIB_VENDOR;

static void create() {
   ::create();
   SetKeyName("Saakan");
   SetShort("Saakan the Trader");
   SetId( ({ "trader", "saakan",  }) );
   SetAdjectives(  );
   SetLong(
     "Saakan is the closest thing to a merchant that Gwonish has to offer. "
     "His experience with trade is low, but what he lacks in skill he more "
     "than makes up for with excitement."
     );
   SetRace("lizardman");
   SetGender("male");
   SetClass("fighter");
   SetLevel(15);
   SetTown("Gwonish");
   SetLocalCurrency("rounds");
   SetMorality(-500);
   SetInventory( ([
     GWONISH_OBJ "serrated"   : "wield sword",
     STD_CLOTHING "body/loin" : "wear loincloth",
     ]) );
   SetLimit(1);
   SetStorageRoom(GWONISH_ROOM "_storage");
   SetVendorType(VT_ALL);
}