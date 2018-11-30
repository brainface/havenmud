/*  i am a master of restraint  
 *    and did not name this a dirty hoe
 *    --mahk 2018
 */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
  item::create();
  digging::create();
  SetKeyName("hoe");
  SetId("hoe");
  SetAdjectives( ({ "rusty" }) );
  SetShort("a rusty hoe");
  SetMaterials( ({ "wood", "metal" }) );
  SetLong("A rusty, well used hoe. Ostensibly for farming, one could also "
    "use its bent blade as a makeshift shovel or fight winner.");
  SetMass(87);
  SetValue(50);
  SetProperty("farming item", 1);
  SetDamagePoints(200);
  SetDamageType(PIERCE);
  SetWeaponType("pole");
  SetClass(7);
  // i guesssss this is right --mahk
  SetVendorType(VT_PLANT);
}

