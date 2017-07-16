//  Clothing Vendor for Marketplace
//  Alessandra 2009

#include <lib.h>
#include <vendor_types.h>
#include "../mal.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  
  SetKeyName("mari");
  SetId( ({ "laviste", "mari laviste", "storekeeper", "woman", "dark-elf" }) );
  SetAdjectives( ({"petite", "mari"}) );
  SetShort("mari Laviste, the Storekeeper");
  SetLong(
     "Mari owns Madame Laviste's Boutique, where she sells all the exquisite "
     "clothing she makes. Raven hair spills down the petite dark-elf woman's "
     "back, and her pale blue eyes watch over the shop quietly as she works "
     "on her latest inspirations."     
     );
  SetRace("dark-elf");
  SetGender("female");
  SetClass("merchant");
  SetLevel(25);
  SetMorality(-50);
  SetLocalCurrency("roni");
  SetMaxItems(30);
  SetMaxSingleItem(3);
  SetVendorType(VT_ARMOUR);
  SetStorageRoom(MAL_ROOMS3 + "clothier_stor");
  SetInventory(([ 
     MAL_OBJ + "/clothing/elf_skirt" : "wear skirt",
     MAL_OBJ + "/clothing/elf_blouse" : "wear blouse", 
     ]));
  SetAction(11, ({ 
  	 "!emote quietly sews on a new dress.",
  	 "!say That would look stunning on you.", 
  	 }) );

}
