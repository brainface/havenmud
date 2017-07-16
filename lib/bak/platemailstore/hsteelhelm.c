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
  SetShort("a large heavy steel helm");
  SetAdjectives( ({"large", "steel", "heavy"}) );
  SetLong(
    "This helm is crafted of tough steel. It offers superb protection to the "
    "wearer's head, while is comfortable enough as to not cause too much "
    "discomfort. It has adequate ventilation to help breathing, and holes big "
    "enough to keep the wearer's field of vision optimal."
  );     
  SetMass(100);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_LARGE);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(2000);
  SetDamagePoints(25000);
  SetArmourType(A_HELMET);  
  SetWear("The steel helm feels very comfortable.");
}