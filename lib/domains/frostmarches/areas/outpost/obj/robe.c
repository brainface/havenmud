
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create(); 
  SetKeyName("grey robe");
  SetId( ({ "robe" }) );
  SetShort("a grey robe");
  SetAdjectives( ({ "grey"}) );
  SetLong("The grey robe is nothing out of the ordinary, but it is "
          "a fairly well made article of clothing.  The robe is rather "
          "bulky and heavy as well. It is a long flowing garment and "
          "would likely offer a slight amount of protection against "
          "the cold.");
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetWarmth(25);
  SetRepairDifficulty(10);
  SetMass(80);
  SetValue(75);
  SetDamagePoints(600);
  }