#include <lib.h>
#include <vendor_types.h>
#include "../glim.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
 SetKeyName("Rancor");
  SetShort("Rancor the Great Smith");
  SetRace("dwarf");
  SetReligion("Kylin", );
  SetId( ({ "rancor", "smith" }) );
  SetAdjectives( ({ "great" }) );
  SetGender("male");
  SetClass("merchant");
  SetSkill("blunt attack", 1, 2);
  SetLevel(50);
  SetVendorType(VT_WEAPON);
  SetLocalCurrency("glims");
  SetLong("Rancor is of the greatest of all dwarven smiths. He spends his time"
         "proofing weapons, overseeing their distribution and sale.");
   SetStorageRoom(G_ROOM + "weapon_storage");
  SetMorality(100);
  SetMaxSingleItem(5);
  SetInventory( ([
     G_OBJ + "hammer" : "wield hammer",
  ]) );
}
