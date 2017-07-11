#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
inherit LIB_ARMOUR;
static void create()
{
  ::create();
  SetKeyName("amulet");
  SetId( ({ "amulet","necklace","gem" }) );
  SetAdjectives( ({ "ancient" }) );
  SetWarmth(0);
  SetShort("an ancient amulet");
  SetLong("The amulet is made of a heavy chain with a large "
          "gem hanging from it.  The gem glitters brightly in "
          "the light.");
  SetMass(8);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_CHAIN);
  SetValue(150);
  SetDamagePoints(600);
    // SetProtection(SLASH, 1);
    // SetProtection(PIERCE, 3);
  SetMaterial("metal");
  SetRepairSkills( ([
                     "metal working" : 4,
                     "armour smithing" : 5
                 ]) );
  SetRepairDifficulty(20);
  SetArmourType(A_AMULET);
  SetVendorType(VT_TREASURE | VT_ARMOUR | VT_GEM);
  
  SetWear("The amulet hangs heavily around your neck.");
}
