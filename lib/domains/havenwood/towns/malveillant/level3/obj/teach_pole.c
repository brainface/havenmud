/*    Portia   12-17-98
      a pole for the teachers.
 */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

 static void create() {
 item::create();
 SetShort("a sturdy staff");
 SetKeyName("staff");
 SetId( ({"staff"}) );
 SetAdjectives( ({"sturdy"}) );
 SetLong("This staff seems to be very sturdy and "
   "looks as though it could take some abuse.");
 SetMaterials( ({"wood"}) );
 SetHands(2);
 SetRepairSkills( ([
   "weapon smithing" : 1,
   "wood working" : 1,
   ]) );
 SetRepairDifficulty(7);
 SetMass(70);
 SetValue(80);
 SetVendorType(VT_WEAPON);
 SetWeaponType("pole");
 SetDamageType(BLUNT);
 SetDamagePoints(450);
 SetClass(9);
 }
