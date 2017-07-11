#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("mask");
  SetShort("a green bear mask");
  SetId( ({ "mask" }) );
  SetAdjectives( ({ "green", "bear" }) );
  SetLong("This mask has been formed from the bones of a grizzly."
          "Once formed it was dipped in a clear sealer to add "
          "greatly to its durability without making it very heavy. "
          "After sealing the mask was covered with head of a "
          "to add a intimidating look to those who oppose one "
          "wearing it. ");
  SetValue(1000);
  SetMass(30);
  SetSize(SIZE_VERY_SMALL);
  SetWarmth(5);
  SetMaterial( ({ "natural" }) );
  SetArmourClass(ARMOUR_NATURAL);
  SetArmourType(A_HELMET);
  SetDamagePoints(2000);
  SetVendorType(VT_ARMOUR);
  SetRepairSkills( ([
          "armour smithing" : 25,
          "natural working" : 25,
         ]) );   
  SetRepairDifficulty(45);
}

