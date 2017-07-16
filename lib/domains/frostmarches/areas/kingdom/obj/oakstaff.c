
/* An oak staff
   Ela 4/19/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetShort("an oaken staff");
  SetId( ({"oak staff","staff"}) );
  SetAdjectives( ({"oaken","thick","sturdy","sanded","smooth"}) );
  SetLong("The thick staff is made of sturdy oak and carefully sanded to a "
          "smooth finish.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetClass(10);
  SetValue(75);
  SetMass(60);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetMaterial( ({"wood"}) );
  SetRepairSkills( ([
           "wood working" : 5,
          "weapon smithing" : 5,
           ]) );
  SetRepairDifficulty(5);
}
