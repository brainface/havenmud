#include <lib.h>
#include <vendor_types.h>
#include "../glim.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("Tembeg");
  SetShort("Tembeg the Armourer of Glimmerdin");
  SetRace("dwarf");
  SetReligion("Kylin", );
  SetId( ({ "tembeg", "armourer" }));
  SetMaxSingleItem(5);
  SetGender("male");
  SetClass("fighter");
  SetSkill("bargaining", 1, 2);
  SetSkill("blunt attack", 1, 1);
  SetLevel(75);
  SetVendorType(VT_ARMOUR);
  SetMorality(300);
  SetLocalCurrency("glims");
  SetCurrency("glims", random(200));
  SetLong("Tembeg oversees all transaction of armours. He seems "
          "to possess great age, but at the same time, a terrible ferocity.");
  SetStorageRoom(G_ROOM + "armor_storage");
  SetInventory( ([
     G_OBJ + "hammer" : "wield hammer",
    ]) );
}
