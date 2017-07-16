// Alessandra 2013

#include <lib.h>
#include <std.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();

  SetKeyName( "boot" );
  SetId(({ "boot" }));
  SetShort( "an old boot" );
  SetAdjectives( ({ "old", "slimy", "water-logged" }) );
  SetLong(
     "Water-logged and covered in slimy seaweed, this boot has been "
     "fished out of the sea. It was probably once a very nice leather "
     "boot, but it is barely held together and at this point could not "
     "be worn."
     );
  SetVendorType(VT_TREASURE);
  SetValue(1);
  SetProperty("history", "This boot belonged to a man named Steven. "
     "The foot that this boot once covered can likely be found in "
     "the ruins of his ship at the bottom of the sea.");
}
