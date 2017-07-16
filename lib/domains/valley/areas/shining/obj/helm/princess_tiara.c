#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("tiara");
  SetShort("an emerald crested tiara");
  SetId( ({ "tiara" }) );
  SetAdjectives( ({ "emerald", "tiara" , "crested" }) );
    SetLong("The tiara was hand crafted and set with emeralds. Each "
            "emerald is set separately into a socket highlighted with "
            "gold claw-like prongs. They are all amazingly clear and "
            "clean. The front of the tiara comes to an arch and has "
            "a rather large emerald cut in a hexagon shape. In certain "
            "places the rim of the tiara curls out with small emeralds "
            "hanging from it. ");
  SetValue(15000);
  SetMass(10);
  SetSize(SIZE_VERY_SMALL);
  SetWarmth(1);
  SetMaterial( ({ "natural" }) );
  SetArmourClass(ARMOUR_NATURAL);
  SetArmourType(A_HELMET);
  SetDamagePoints(2000);
  SetVendorType(VT_ARMOUR);
  SetRepairSkills( ([
          "armour smithing" : 175,
          "natural working" : 175,
         ]) );   
  SetRepairDifficulty(100);
  SetProtectionBonus(COLD,60);
  SetProtectionBonus(HEAT,60);
  SetProtectionBonus(MAGIC,60);
}
