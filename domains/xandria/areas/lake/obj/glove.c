//Selket@Haven
//2006
#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>
 
inherit LIB_ARMOUR;
 
static void create()
{
  armour::create();
  SetKeyName("glove");
  SetId(( { "glove"} ));
  SetShort("a flax glove");
  SetLong("The rough glove protects one from deadly papyrus cuts.");
  SetMass(15);
  SetValue(20);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(300);
  SetArmourType(A_GLOVE);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetWear("The glove scratches a little against your hands.");
  SetMaterial( ({ "textile" }) );
  SetWarmth(5);
}
