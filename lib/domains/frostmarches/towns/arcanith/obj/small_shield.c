/* A small, leather shield - By Sardonas */

#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shield");
  SetId( ({ "shield" }) );
  SetAdjectives( ({ "small", "leather" }) );
  SetShort("a small leather shield");
  SetLong("The shield is fairly simple and worn.  It is a piece of leather "
          "stretched over a wooden frame.  There is a faded design on the "
          "front of the shield.  It seems that the design shows a crossed"
          "wand and a sword enveloped in a glowing aura.");
  SetProperty( "history", "The symbol enscribed on the shield is emblem of "
                          "the City of Arcanith.  It shows that the magic "
                          "and strength can support each other when "
                          "used in the light of goodness.  The shield "
                          "has survived the ages only to be discovered "
                          "by kobolds.");
                          
  SetMass(45);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_LEATHER);
  SetValue(10);
  SetDamagePoints(200);
  // SetProtection(BLUNT, 3);
  // SetProtection(PIERCE, 2);
  // SetProtection(SLASH, 3);
  SetArmourType(A_SHIELD);
  SetMaterial( ({ "wood", "leather" }) );
  SetWarmth(0);
  SetRepairSkills( ([ "wood working" : 1,
                      "leather working" : 1,
                      "armour smithing" :1, ]) );
  SetRepairDifficulty(5);
}
