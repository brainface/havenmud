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
  SetKeyName("leggings");
  SetId(( { "leather leggings","pair of leggings","leggings"} ));
  SetShort("a pair of leather leggings");
  SetLong("Reinforced in the knees and thighs, these leather leggings look comfortable.");
  SetMass(30);
  SetMaterial("leather");
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetWarmth(20);
  SetValue(80);
  SetDamagePoints(500);
  
  
  SetArmourType(A_PANTS);
}
