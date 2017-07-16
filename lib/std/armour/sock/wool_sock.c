#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("sock");
  SetId( ({ "sock" }) );
  SetAdjectives( ({ "wood","thick","scratchy","warm" }) );
  SetShort("a thick wool sock");
  SetLong("The sock looks warm, but scratchy");
  SetMass(10);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetValue(5);
  SetDamagePoints(200);
  
  SetArmourType(A_SOCK);
  
  
  SetWear("You wiggle your toes down into the sock.");
  SetMaterial( ({ "textile" }) );
  SetWarmth(5);
  SetRepairDifficulty(10);
  SetRepairSkills( ([
                      "textile working" : 1,
                      "armour smithing" : 1,
                 ]) );
}
