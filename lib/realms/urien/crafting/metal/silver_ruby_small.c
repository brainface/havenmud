#include <lib.h>
#include <std.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("ruby necklace");
  SetShort("a silver ruby necklace");
  SetId( ({"necklace"}) );
  SetAdjectives( ({ "silver","ruby" }) );
  SetLong("Elegant and fragile silver filagree chain together to hold "
          "a ruby sparkling like a candleflame.");
  SetMass(15);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_SMALL);
  SetValue(200);
  SetDamagePoints(800);
  SetArmourType(A_AMULET);
  SetRepairDifficulty(10);
}

