#include <lib.h>
#include <vendor_types.h>
#include "../averath.h"

inherit LIB_VENDOR;
static void create() {
   vendor::create();
   SetKeyName("Felix Monteil");
   SetId( ({ "felix", "monteil", "averath_person" }) );   
   SetShort("Felix Monteil the Tavern Proprietor");
   SetLong(
     "Short and stocky, Felix stands at a solid meter high "
     "and weighs more than a full height man. He looks like he "
     "could easily rip any man in two. His hair is clean cut and black."
     );
   SetAdjectives( ({ "tavern" }) );   
  
   SetRace("human");
   SetGender("male");
   SetBaseLanguage("Avera");
   SetReligion("Aetarin");
   SetLocalCurrency("ducats");
   SetMorality(100);
   SetClass("merchant");
   SetLevel(5);
   AddCurrency("ducats", random(100));   
   SetStorageRoom(AVERATH_ROOM + "storage/ale_store");
   SetMaxItems(150);
   SetMaxSingleItem(20);
   SetVendorType(VT_DRINK);
   
   SetAction(1, ({ "!say what would you like today?",   }) );   
}
