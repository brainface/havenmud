
/* Queen's gown
   Ela 4/19/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("gown");
  SetShort("a golden gown");
  SetId( ({"gown","dress","halter-neck"}) );
  SetAdjectives( ({"silk","glittering","gold","breathtaking"}) );
  SetLong("This breathtaking gown is truly fit for royalty. It is a "
      "halter-neck made of silk in the purest shade of gold, almost glittering"
     " in its paleness. The dress falls in graceful folds to gently sweep the "
     "floor.");
  SetMass(60);
  SetValue(250);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(200);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetWarmth(15);
  // SetProtection(MAGIC, 5);
  SetArmourType(A_BODY_ARMOUR);
  SetSize(SIZE_TINY);
}
