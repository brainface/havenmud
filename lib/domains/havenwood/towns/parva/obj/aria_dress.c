 /* whore's dress
  Malak@haven 05/20/99
*/
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("black silk dress");
  SetWarmth(10);
  SetSize(SIZE_MEDIUM);
  SetShort("a black silk dress");
  SetId( ({ "dress" }) );
  SetAdjectives( ({"black", "silk" }) );
  SetLong("This soft, black dress is made from the finest "
          "of silk.  The thin, almost see through fabric leaves "
          "very little to the imagination, being too short to even "
          "hope to cover up the wearers genitalia. Slit up the sides, "
          "this dress may not be comfortable, but it makes the wearer "
          "look great.");
  SetMass(40);
  SetValue(500);
  SetDamagePoints(30);
  SetMaterial("textile");
  SetRepairDifficulty(50);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
}
