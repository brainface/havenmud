#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helm");
  SetId(( {"helm" } ));
  SetShort("a chainmail helm");
  SetAdjectives( ({"large", "chainmail"}) );
  SetLong(
    "This helm is crafted of small chain links. It offers superb protection to the "
    "wearer's head, while is comfortable enough as to not cause too much "
    "discomfort. It has adequate ventilation to help breathing, and holes big "
    "enough to keep the wearer's field of vision optimal. It is lined with a fine "
    "linen."
  );     
  SetMass(75);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_LARGE);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(2000);
  SetDamagePoints(25000);
  SetArmourType(A_HELMET);  
  SetWear("The chainmail helm feels very comfortable.");
}
