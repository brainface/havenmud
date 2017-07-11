/*    Portia   12-17-98
      a pole for the students.
 */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

 static void create() {
 item::create();
 SetShort("a thin staff");
 SetKeyName("staff");
 SetId( ({"staff"}) );
 SetAdjectives( ({"thin"}) );
 SetLong("This thin staff looks like it wouldn't "
   "be able to take much damage, as it has been formed "
   "from a small branch.");
 SetMaterials( ({"wood"}) );
 SetHands(2);
 SetRepairSkills( ([
   "weapon smithing" : 1,
   "wood working" : 1,
   ]) );
 SetRepairDifficulty(5);
 SetMass(60);
 SetValue(40);
 SetVendorType(VT_WEAPON);
 SetWeaponType("pole");
 SetDamageType(BLUNT);
 SetDamagePoints(400);
 SetClass(8);
 }
