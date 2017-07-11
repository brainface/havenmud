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
  SetShort("a mithril helmet");
  SetAdjectives( ({"mithril"}) );
  SetLong(
    "This helmet is crafted of mithril and has a long flowing white mane "
    "starting from the top of the helmet. The helmet protects the head and "
    "base of the neck. The front of the helmet is open with eye slits and "
    "nose guard. It offers superb protection to the wearer's head, while "
    "is comfortable enough as to not cause too much discomfort." );     
  SetMass(50);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("mithril");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(3000);
  SetDamagePoints(2000);
  SetArmourType(A_HELMET);  
}