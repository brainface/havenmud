#include <lib.h>
#include <vendor_types.h>
inherit LIB_VENDOR;
static void create()
{
  vendor::create();
  SetShort("a treasure selling faerie dragon");
  SetLong("This is a pretty faerie dragon named Cartheny.  He is "
    "nothing more than a small lizard with butterfly wings.  His body "
    "is %^MAGENTA%^pink%^RESET%^ in hue and about a foot long and a "
    "tail the same length.  His wings are a powdery "
    "%^GREEN%^green%^RESET%^ color and he has a wingspan of about "
    "three feet.");
  SetRace("faerie dragon");
  SetGender("male");
  SetKeyName("Cartheny the treasure selling dragon");
  SetId(({"faerie dragon", "dragon"}));
  SetVendorType(VT_GEM | VT_TREASURE);
  SetLocalCurrency("cuicui");
  SetStorageRoom("miscstorage");
  SetMaxSingleItem(15);
  SetMorality(2500);
  SetClass("animal");
  SetLevel(25);
  
  SetInvis(1);
}
