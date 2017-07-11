/* a lyre
   Ela 11/3/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("lyre");
  SetShort("a lyre");
  SetId( ({ "lyre", "instrument" }) );
  SetAdjectives( ({ "carved", "polished", "enchanted" }) );
  SetLong("This intricately carved instrument glows with "
          "a polished sheen, showing its remarkable value "
          "and hinting of faerie enchantment.");

  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetClass(12);
  SetValue(150);
  SetMass(40);
  SetWeaponType("blunt");
  SetDamageType(MAGIC);
  SetMaterial( ({"wood"}) );
  SetRepairSkills( ([
          "wood working" : 7,
          ]) );
  SetRepairDifficulty(10);
}
