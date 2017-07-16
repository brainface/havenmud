// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetKeyName("robe");
  SetShort("a stunning white robe");
  SetId( ({"robe"}) );
  SetAdjectives( ({"white", "stunning"}) );
  SetLong(
    "This stunning white robe is a lovely article of clothing. It seems "
    "both functional and attractive. It is white, with the symbol of the "
    "Kylin faith, a balance entwined with a red dragon, sewn on the front. "
    "The dragon symbol seems to emit a very faint red glow. "
  );
  SetMass(50);
  SetValue(300);
  SetDamagePoints(1000);
  SetWarmth(30);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_BODY_ARMOUR);
  //SetProtectionBonus(MAGIC, 40);
}

/** Approved by Laoise at Sun May 21 17:03:39 2006. **/