#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create(); 
  SetKeyName("surcoat");
  SetShort("a white surcoat");
  SetId( ({"surcoat"}) );
  SetAdjectives( ({"white"}) );
  SetLong("This white surcoat has the symbol of Kylin, the balance "
          "entwined with a red dragon, sewn on the front. It is cut "
          "generously for comfort while being worn over armour. It "
          "hangs over the chest and back resting above the knees.");
  SetMass(40);
  SetValue(100);
  SetDamagePoints(500);
  SetArmourClass(ARMOUR_CLOTH); 
  SetMaterials( ({"textile"}) ); 
  SetWarmth(5);
  SetRepairDifficulty(10);
  SetArmourType(A_BODY_ARMOUR);
  SetSize(SIZE_SMALL);
  SetRestrictLimbs(({"torso","left leg","right leg"}));
}