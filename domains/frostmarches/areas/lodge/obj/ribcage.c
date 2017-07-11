#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include "../lodge.h"

inherit LIB_ARMOUR;
static void create() {
  armour::create();
  SetKeyName("armour");
  SetId( ({"suit","armour"}) );
  SetShort("a suit of composite armour");
  SetLong("This armour has been crafted from the skeletal remains"
          " of a rather large animal. The breastplate is a solid"
          " piece of ribcage reinforced with what appears to be"
          " small ceramic plates. The arms and legs of this suit"
          " are made of thin leather pieces that have been covered"
          " in bones of all varieties. It looks like great protection.");
  SetAdjectives( ({"composite"}) );
  SetMass(550);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);

  SetValue(300);
  SetMaterial( ({"natural"}) );
  SetWarmth(5);
  SetRepairSkills( ([
     "natural working" : 6,
     "armour smithing" : 6,
  ]) );
  SetRepairDifficulty(15);
  SetDamagePoints(700);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  // SetProtection(SLASH,20);
  // SetProtection(BLUNT,15);
   // SetProtection(PIERCE,20);
}
