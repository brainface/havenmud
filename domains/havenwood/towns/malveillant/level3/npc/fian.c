//  Portia 10-24-98
//  The owner of the smithy.
//  Updated by Alessandra 2009

#include <lib.h>
#include "../mal.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
  vendor::create();

  SetKeyName("fian");
  SetShort("fian the Owner of the Smithy");
  SetId( ({"fian", "owner", "vendor", "man", "dark-elf", "smith"}) );
  SetAdjectives( ({"small", "shrewd" }) );
  SetLong(
     "Fian is a small, shrewd dark-elf, with mischief in his "
     "eyes. He seems like he wouldn't be fooled by simple acts of "
     "deception."
     );
  SetRace("dark-elf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(25);
  SetVendorType(VT_WEAPON);
  SetCurrency( ([
       "roni" : random(50),
       ]) );
  SetLocalCurrency("roni");
  SetStorageRoom(MAL_ROOMS3 + "smithy_stor");

}
