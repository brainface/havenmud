/*    Portia   12-17-98
      a mace for the leaders.
 */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

 static void create() {
 item::create();
 SetShort("a huge mace");
 SetKeyName("mace");
 SetId( ({"mace"}) );
 SetAdjectives( ({"huge"}) );
 SetLong("This obsidian mace is absolutely huge. "
   "It would take someone very skilled to weild such a "
   "weapon.");
 SetMaterials( ({"natural"}) );
 SetRepairSkills( ([
   "weapon smithing" : 1,
   "wood working" : 1,
   ]) );
 SetRepairDifficulty(14);
 SetMass(120);
 SetValue(100);
 SetVendorType(VT_WEAPON);
 SetWeaponType("blunt");
 SetDamageType(BLUNT);
 SetDamagePoints(1000);
 SetClass(11);
 }
