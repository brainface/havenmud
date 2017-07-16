#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("dark robes");
  SetId(( { "robe", "robes","dark robes","dark robe"}));
  SetShort("dark robe");
  SetLong("The robes are made of a course dark material.");
  SetMaterial( ({"textile"}) );
  SetWarmth(20);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetRepairSkills( ([
                     "textile working" : 1
                 ]) );
  SetRepairDifficulty(7);
  SetDamagePoints(300);
  SetVendorType(VT_CLOTHING);
  SetMass(100);
  SetValue(400);
  SetArmourType(A_CLOAK);
  
  // SetProtection(BLUNT,1);
  // SetProtection(SLASH,3);
  // SetProtection(PIERCE,2);
}
