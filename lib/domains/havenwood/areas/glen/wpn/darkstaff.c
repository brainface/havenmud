/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>.c
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
static void create() {
  item::create();
  SetMaterial("mithril");
  SetKeyName("staff");
  SetShort("a dark staff");
  SetLong("This staff is about six feet long and fairly heavy.  "
          "It is made of a dark, unidentifiable material that "
          "seems oddly metalic.  In the right hands it could "
          "probably be a very dangerous weapon.");
  SetId( ({ "dark staff","black staff",
            "magic staff","staff" }) );
  SetClass(16);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetDamagePoints(1600);
  SetValue(800);
  SetMass(300);
  SetHands(2); 
}
