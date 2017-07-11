/*    Portia   12-17-98
      a mace for the students.
 */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

 static void create() {
 item::create();
 SetShort("a small mace");
 SetKeyName("mace");
 SetId( ({"mace"}) );
 SetAdjectives( ({"small"}) );
 SetLong("This small mace looks as though it would "
   "be useful but not very durable.");
 SetMaterials( ({"wood"}) );
 SetRepairSkills( ([
   "weapon smithing" : 1,
   "wood working" : 1,
   ]) );
 SetRepairDifficulty(5);
 SetMass(60);
 SetValue(40);
 SetVendorType(VT_WEAPON);
 SetWeaponType("blunt");
 SetDamageType(BLUNT);
 SetDamagePoints(500);
 SetClass(8);
 }
