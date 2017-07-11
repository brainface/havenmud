#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
armour::create();
  SetKeyName("boots");
  SetShort("a pair of black boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "black","pair"}) );
  SetLong("This is a pair of black boots which will protect the wearer's "
          "feet and legs up to their mid-calf. The boots are made from hard "
          "leather which will offer some protection.");
  SetMass(40);
  SetMaterial("leather");
  SetWarmth(10);
  SetProperty("multiples", 1);
  SetArmourClass(ARMOUR_LEATHER);
  SetValue(10);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_SMALL);
  SetArmourType(A_BOOT);
  SetDamagePoints(500);
  }