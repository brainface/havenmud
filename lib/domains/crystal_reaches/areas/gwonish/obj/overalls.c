
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("overalls");
  SetId(( { "overalls"}));
  SetShort("overalls");
  SetLong("The grass stained overalls are made out of a heavy canvas.");
  SetMaterial( ({"textile"}) );
  SetWarmth(20);
  SetRepairSkills( ([
                     "textile working" : 2
                 ]) );
  SetRepairDifficulty(7);
  SetDamagePoints(350);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_SMALL);
  SetVendorType(VT_CLOTHING);
  SetMass(250);
  SetValue(90);
  SetArmourType(A_PANTS);
  
  // SetProtection(BLUNT,1);
  // SetProtection(SLASH,2);
  // SetProtection(PIERCE,1);
  // SetProtection(COLD,4);
  // SetProtection(HEAT,2);
  // SetProtection(ACID,2);
}
