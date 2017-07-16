/*    Portia   12-17-98
      a pole for the leaders.
 */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

 static void create() {
 item::create();
 SetShort("a thick staff");
 SetKeyName("staff");
 SetId( ({"staff"}) );
 SetAdjectives( ({"thick"}) );
 SetLong("This staff is relatively thick and seems to be "
   "very heavy. It must belong to someone quite strong.");
 SetMaterials( ({"wood"}) );
 SetHands(2);
 SetRepairSkills( ([
   "weapon smithing" : 1,
   "wood working" : 1,
   ]) );
 SetRepairDifficulty(8);
 SetMass(90);
 SetValue(90);
 SetVendorType(VT_WEAPON);
 SetWeaponType("pole");
 SetDamageType(BLUNT);
 SetDamagePoints(550);
 SetClass(15);
 }
