/*    Portia   12-17-98
      a mace for the teachers.
 */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

 static void create() {
 item::create();
 SetShort("a dark mace");
 SetKeyName("mace");
 SetId( ({"mace"}) );
 SetAdjectives( ({"dark"}) );
 SetLong("This dark mace is quite heavy as it has been "
   "carved from a piece of obsidian.");
 SetMaterials( ({"natural"}) );
 SetRepairSkills( ([
   "weapon smithing" : 1,
   "natural working" : 1,
   ]) );
 SetRepairDifficulty(50);
 SetMass(80);
 SetValue(60);
 SetVendorType(VT_WEAPON);
 SetWeaponType("blunt");
 SetDamageType(BLUNT);
 SetDamagePoints(800);
 SetClass(20);
 }
