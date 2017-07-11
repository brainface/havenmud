  /* Lucie's boots
  Zara 8/15/98
*/
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetShort("leather boots");
  SetId( ({"boot","boots"}) );
  SetAdjectives( ({"leather","ladie's","black","butter-soft"}) );
  SetLong("These ladies' boots are black and made of "
          "butter-soft leather.");
  SetMass(40);
  SetValue(75);
  SetDamagePoints(150);
  SetProperty("multiples", 1);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_BOOT);
  SetMaterial("leather");
  SetRepairSkills( ([ "leather working" : 3, ]) );
  SetRepairDifficulty(5);
  // SetProtection(BLUNT, 2);
  // SetProtection(SLASH, 4);
  // SetProtection(PIERCE, 4);
  // SetProtection(WATER, 5);
  // SetProtection(SHOCK, 3);
  // SetProtection(COLD, 6);
  // SetProtection(HEAT, 4);
  // SetProtection(ACID, 2);

}
