#include <lib.h>
#include <vendor_types.h>
#include "../averath.h"

inherit LIB_VENDOR;
static void create() {
  vendor::create();
  SetKeyName("Gregoire");
  SetId( ({ "gregoir", "fisherman", "averath_person" }) );  
  SetShort("Gregoir the Fisherman");
  SetLong(
    "Gregoir is tall with a lean build. His hair is long and grey, and his "
    "face is home to a long unsightly scar. He has rather dirty hands that are "
    "covered in fish entrails, but his produce seems very popular amongst the "
    "local citizens regardless."
  );   
   
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetReligion("Aetarin");
  SetLocalCurrency("ducats");
  AddCurrency("ducats", random(50));
  SetMorality(0);
  SetClass("merchant");
  SetLevel(8);
   
  SetStorageRoom(AVERATH_ROOM + "fish_store");
  SetMaxItems(40);
  SetMaxSingleItem(10);
  SetVendorType(VT_FOOD);
  
  SetAction(1, ({ 
    "!emote sighs heavily.", 
    "!say if only I could leave.",
    "!emote searches the horizon.", 
  }) );
}
