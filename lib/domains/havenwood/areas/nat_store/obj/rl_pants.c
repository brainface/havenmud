#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pants");
  SetId(( {"pants"} ));
  SetShort("a pair of studded leather pants");
  SetAdjectives( ({"studded", "leather","pair of" }) );
  SetLong(
    "These armored pants are made of many steel plates riveted to an outer "
    "layer of dyed black leather and an inner layer of canvas padding. Gaps "
    "in the plating around the joints allow greater flexibility at the "
    "expense of protection."
  );
  SetMass(325);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({"leather","metal"}) );
  SetWarmth(5);
  SetRepairDifficulty(70);
  SetValue(3500);
  SetDamagePoints(4000);
  SetArmourType(A_PANTS);
  SetWear("The steel plates are a comforting weight along your skin.");
}

