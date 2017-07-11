//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("armlet");
  SetId( ({ "armlet" }) );
  SetAdjectives( ({ "snake", "gold" }) );
  SetShort("a snake armlet");
  SetLong(
    "This armlet is a hardened leather bracer with a stylized golden "
    "snake winding around it, such that it appears to be a snake "
    "curling around the wearer's arm. The eyes even seem to wink "
    "shrewdly."
  );
  SetMass(80);
  SetSize(SIZE_MEDIUM);
  SetValue(300);
  SetArmourClass(ARMOUR_PLATE);
  SetDamagePoints(500);
  SetArmourType(A_LONG_GLOVE);
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({"leather"}) );
  SetWarmth(3);
}
