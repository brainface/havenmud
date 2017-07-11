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
  SetKeyName("dress");
  SetShort("an elegant and beautiful dress");
  SetId( ({ "dress" }) );
  SetAdjectives( ({ "elegant","beautiful", "dress" }) );
  SetLong("The dress is definitely hand crafted from the softest of cottons "
          "and the finest silks. From every angle the dress glitters from all "
          "the gems sewed into it. The strap at the top runs around the neck to 
"
          "support the dress. It fits tightly to show all features on whoever "
          "wears it. The dress appears that it would cover to the mid thigh of "

          "someone wearing it. ");
  SetMass(40);
  SetProperty("multiples", 1);
  SetSize(SIZE_VERY_SMALL);
  SetValue(80);
  SetDamagePoints(200);
  SetMaterial("textile");
  SetWarmth(35);
  SetArmourType(A_CLOAK);
  SetProtectionBonus(MAGIC, 50);
  SetProtectionBonus(HEAT, 50);
  SetProtectionBonus(COLD,510);
}

