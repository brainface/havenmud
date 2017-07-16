 /* whore's dress
  Malak@haven 05/20/99
*/
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dress");

  SetShort("a black silk dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"black","tight-fitting","silk" }) );
  SetLong("This soft, black dress is made from the finest "
          "of silk.  The thin, almost see through fabric leaves "
          "very little to the imagination, being too short to even "
          "hope to cover up the wearers buttocks completly. Slit up the "
          "sides, this dress may not be comfortable, but it makes the "
          "wearer look cheap and sexy.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetValue(75);
  SetDamagePoints(150);
  SetSize(SIZE_MEDIUM);
  }
