#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include "../path.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("Norin");
  SetId( ({ "norin", "tanner" }) );
  SetShort("Norin, tanner of Glimmerdin");

  SetLong(
    "Norin is a short and stocky dwarf with black hair and long beard. "
    "He is proud of his family tradition of making leather goods for his "
    "fellow dwarves.  Norin is a bit short tempered when his wife, Fimana, "
    "gives away decent leather goods. "    
    );
  SetRace("dwarf");
  SetGender("male");
  SetLocalCurrency("nuggets");
  SetMorality(550);
  SetClass("merchant");
  SetLevel(30); 
  AddCurrency("nuggets", random(100)); 
  SetStorageRoom(G_ROOM "leatherstore");
  SetProperty("no bump", 1);  
  SetVendorType(VT_ARMOUR||VT_CLOTHING);  
  SetAction(4, ({ 
   	  "!say Stop it woman, sell those leather goods!",
      "!sigh.",
      }) );
}
