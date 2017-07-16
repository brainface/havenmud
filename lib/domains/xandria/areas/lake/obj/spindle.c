//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("spindle");
  SetId( ({ "spindle" }) );
  SetAdjectives( ({ "stone", "enormous" }) );
  SetShort("an enormous stone spindle");
  SetLong(
    "This very sharp spindle is used to quickly lash "
    "out woolen yarn. The tip looks very sharp and pointy "
    "and dangerous to fingers."
  );
  SetClass(6);
  SetDamagePoints(350);
  SetValue(75);
  SetWeaponType("pierce");
  SetDamageType(SLASH);
  SetMass(25);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_WEAPON);
}

