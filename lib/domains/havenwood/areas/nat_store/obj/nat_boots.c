#include <lib.h>   
#include <vendor_types.h>
#include <size.h>        
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetId(( {"boots" } ));
  SetShort("a pair of boarskin boots");
  SetAdjectives( ({"boarskin", "pair of"}) );
  SetLong(
    "These boots are sewn from the thick, furry hide of a boar. The thick fur and "
    "leather soles would protect the wearers feat from the worst rocky roads "
    "and thorny thistles."
  );
  SetProperty("multiples", 1);
  SetMass(150);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
  SetMaterial("natural");
  SetWarmth(5);
  SetRepairDifficulty(70);
  SetValue(2500);
  SetDamagePoints(25000);
  SetArmourType(A_BOOT);
  SetWear("The hide boots feel a little scratchy.");
}

