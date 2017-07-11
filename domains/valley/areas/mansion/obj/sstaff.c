/* a shepherds staff
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetShort("a long shepherd's staff");
  SetId( ({"staff", "pole"}) );
  SetAdjectives( ({ "long", "shepherd's"}) );
  SetLong("This long staff looks as though it is very old and has been used "
          "by many generations of shepherds to prod their animals.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1200);
  SetClass(8);
  SetValue(100);
  SetMass(120);
  SetMaterial( ({ "wood"}) );
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  }
