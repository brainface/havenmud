#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); 
SetArmourClass(ARMOUR_CLOTH); 
SetMaterials( ({ "textile" }) 
); 
  SetKeyName("robe");
  SetShort("a green silk robe");
 SetId( ({ "cape" }) );
  SetAdjectives( ({ "green","silk" }) );
  SetLong("The green robe is made of silk. It has markings along the "
          "back of it that resemble those seen around the forest. It "
          "is rather plain but will keep one warm.");
  SetMass(40);
  SetProperty("multiples", 1);
  SetSize(SIZE_VERY_SMALL);
  SetValue(80);
  SetDamagePoints(200);
  SetMaterial("textile");
  SetWarmth(35);
  SetArmourType(A_CLOAK);
  SetProtectionBonus(MAGIC, 10);
  SetProtectionBonus(HEAT, 10);
  SetProtectionBonus(COLD, 10);
}



