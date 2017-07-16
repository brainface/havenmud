// Monastery
// Aerelus
// 07/05/2006

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetKeyName("tattered shirt");
  SetShort("a tattered shirt");
  SetId( ({ "shirt" }) );
  SetAdjectives( ({ "tattered", }) );
  SetLong(
    "This tattered shirt is covered in dirt. It is torn in multiple "
    "places. There are holes where buttons should go down the front, "
    "but the buttons have been lost for a long time. It seems to be "
    "able to keep a person reasonably warm, but no more."
  );
  SetMass(10);
  SetValue(0);
  SetDamagePoints(1000);
  SetWarmth(20);
  SetMaterial("textile");
  SetRepairDifficulty(85);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_SHIRT);
}
