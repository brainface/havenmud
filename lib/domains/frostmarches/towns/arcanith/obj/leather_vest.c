/* Leather armour - by Sardonas */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("vest");
  SetId( ({ "vest" }) );
  SetAdjectives( ({ "leather" }) );
  SetShort("a leather vest");
  SetLong("The leather vest is very bulky and stiff.  The leather is not of "
          "the best quality, but it serves its purpose.");
  SetMass(140);
  SetValue(80);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetVendorType(VT_ARMOUR);
  SetDamagePoints(250);
  // SetProtection(BLUNT, 1);
  // SetProtection(PIERCE, 4);
  // SetProtection(SLASH, 3);
  SetArmourType(A_VEST);
  SetMaterial( ({ "leather" }) );
  SetWarmth(10);
  SetRepairSkills( ([ "leather working" : 1,
                      "armour smithing" :1, ]) );
  SetRepairDifficulty(5);
}
