/*  Scalp Helmet - Kobold Chief - Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h> 
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("scalp helmet");
  SetId( ({ "scalp helmet", "helmet" }) );
  SetAdjectives( ({ "scalp", "hideous" }) );
  SetShort("a scalp helmet");
  SetLong(
    "This helmet is made from the parts of different scalps adherred to "
    "a piece of leather. The helmet in itself probably provides little "
    "protection, although on the brighter side it is absolutely hideous."
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(60);
  SetValue(20);
  SetDamagePoints(120);
  SetSize(SIZE_SMALL);
  SetMaterial( ({ "leather", "natural" }) );
  SetWarmth(4);
}
