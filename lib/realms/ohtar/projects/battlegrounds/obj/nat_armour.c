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
  SetId( ({"hardened", "clay", "hardened clay"}) );
  SetAdjectives( ({"hardened", "clay", "armour", "hardened clay"}) );
  SetShort("a suit of hardened clay armour");
  SetLong("The hand crafted suit of clay covers all the main parts of"
          "a body. It is very ridig and has some very sharp spots on it where "
          "it appears the clay hardened before it could be smoothed out. This "
          "suit is attached to fine lines of wire that allows the wearer of the "
          "suit to move their limbs. The inside has a small liner that appears to "
          "be that of some kind of an animal skin to help protect the wearer from "
          "the sharp clay edges. It appears that this was made by a someone that has "
          "lived in the wilderness for many years. ");
  SetMass(1000);
  SetMaterial( ({ "natural", "leather" }) );
  SetRepairDifficulty(60);
  SetArmourClass(ARMOUR_NATURAL);
  SetWarmth(6);
  SetSize(SIZE_MEDIUM);
  SetValue(5000);
  SetDamagePoints(3500);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_ARMOUR); 
}
