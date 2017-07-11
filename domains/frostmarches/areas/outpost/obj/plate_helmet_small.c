#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helmet");
  SetId(( {"helmet" } ));
  SetShort("a silver helmet");
  SetAdjectives( ({"silver"}) );
  SetLong(
    "This helmet is crafted of silver steel which is well polished. A white " 
    "mane sits on the top of the helmet and runs down the back of the helmet. "
    "It offers superb protection to the wearer's head, while is comfortable "
    "enough as to not cause too much discomfort. It has adequate ventilation "
    "to help breathing, and holes big enough to keep the wearer's field of "
    "vision optimal.");     
  SetMass(75);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(2000);
  SetDamagePoints(2000);
  SetArmourType(A_HELMET);  
}