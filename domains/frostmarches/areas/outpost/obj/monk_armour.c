#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("armour");
  SetId( ({"chainmail", "suit"}) );
  SetAdjectives( ({"chain","mail"}) );
  SetShort("a suit of chainmail armour");
  SetLong("This suit of chainmail is made from a dull gray steel. No light "
          "is reflected from the unpolished surface of the chain links. "
          "The suit provides protection from injury and is flexible enough "
          "to allow the wearer free movement.");
  SetMass(800);
  SetMaterial( ({"metal"}) );
  SetRepairDifficulty(40);
  SetArmourClass(ARMOUR_CHAIN);
  SetWarmth(0);
  SetSize(SIZE_MEDIUM);
  SetValue(2000);
  SetDamagePoints(3000);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_ARMOUR);
  }