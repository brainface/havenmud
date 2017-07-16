
#include <lib.h>
#include <vendor_types.h>
#include "../averath.h"

inherit LIB_VENDOR;
static void create() {
  vendor::create();
  SetKeyName("Isaak Coudray");
  SetId( ({ "isaak", "coudray", "haberdasher", "averath_person" }) );  
  SetShort("Isaak Coudray the Haberdasher");
  SetLong(
    "Isaak Coudray is a short, stout man. His face is almost bright red "
    "after years of excess alcohol consumption, though despite his drunken "
    "behaviour he remains a man of importance in Averath. He is most famous "
    "for his fine line of expensive hats, which he seems to be trying to sell."    
  );   
   
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetReligion("Aetarin");
  SetLocalCurrency("ducats");
  
  SetMorality(100);
  SetClass("merchant");
  SetLevel(8);
  AddCurrency("ducats", random(50)+10);
  
  SetStorageRoom(AVERATH_ROOM + "storage/haber_store");
  SetMaxItems(10);
  SetMaxSingleItem(10);
  SetVendorType(VT_CLOTHING);
  
  SetAction(1, ({ 
    "!say come look at my hats, peasants!",
    "!say get your fine hats right here!",
    "!say my hats are the finest, all fresh and clean, don't even smell of "
      "fish yet.",
    "!emote stumbles slightly.",     
    "!emote violently hiccups.", 
  }) );
}
