#include <lib.h>
#include <vendor_types.h>
#include "../averath.h"

inherit LIB_VENDOR;
static void create() {
  vendor::create();
  SetKeyName("Gregoire");
  SetId( ({"gregoire", "fisherman", "averath_person" }) );
  SetShort("Gregoire the Fisherman");
  SetLong(
    "Gregoire is tall with a lean build. His hair is long and grey, and his "
    "face is home to a long unsightly scar. He has rather dirty hands that are "
    "covered in fish entrails, but his produce seems very popular amongst the "
    "local citizens regardless."
  );   
   
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetReligion("Aetarin");
  SetLocalCurrency("ducats");
  
  SetMorality(250);
  SetClass("merchant");
  SetLevel(8);
  AddCurrency("ducats", random(50)+5); 
  
  SetStorageRoom(AVERATH_ROOM + "storage/fish_store");
  SetMaxItems(40);
  SetMaxSingleItem(10);
  SetVendorType(VT_FOOD);
  
  SetAction(1, ({ 
    "!emote sighs heavily.", 
    "!say if only I could leave.",
    "!emote searches the horizon.", 
  }) );
}
