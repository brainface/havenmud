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
  SetShort("a green wolf mask");
  SetId( ({ "mask" }) );
  SetAdjectives( ({ "green", "wolf" , "mask" }) );
    SetLong("The green mask is handcrafted from the skull of a wolf. "
          "It was obviously coated with some sort of liquid. The eye "
          "slots are cut very small but are big enough for one to see "
          "through. The snout was removed and a small bone barrier put "
          "in its place. The small carvings in the bones resemble many "
          "seen around the forest. It appears to be part of a full "
          "outfit. ");
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
  SetProtectionBonus(COLD,20);
  SetProtectionBonus(BLUNT,20);
  SetProtectionBonus(SLASH,20);
  SetProtectionBonus(HEAT,20);
  SetProtectionBonus(MAGIC,20);
  SetProtectionBonus(PIERCE,20);
}
