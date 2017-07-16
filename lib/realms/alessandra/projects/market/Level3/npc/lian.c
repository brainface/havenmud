//  Portia 10-24-98
//  The owner of the Armoury.
//  Updated by Alessandra 2009

#include <lib.h>
#include <vendor_types.h>
#include "../mal.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  
  SetKeyName("lian");
  SetId( ({"lian", "owner", "vendor", "man", "dark-elf"}) );
  SetAdjectives( ({"personable"}) );
  SetShort("lian the Owner of the Armoury");
  SetLong(
     "Lian is a very personable fellow, and constantly has a large "
     "smile for all who enter. He and his twin brother Fian run the "
     "town's armoury and smithy. He likes to talk, usually about his "
     "fine wares."
     );
  SetRace("dark-elf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(25);
  SetCurrency( ([
       "roni" : random(50),
        ]) );
  SetVendorType(VT_ARMOUR);
  SetLocalCurrency("roni");
  SetStorageRoom(MAL_ROOMS3 + "arm_stor");
  SetAction(11, ({
       "!say can I interest you in some new garments today?",
       "!say I only stock the finest of goods!",
       "!emote flashes a broad smile.",
       "!say have you seen our latest shipment?",
      }) );

}
