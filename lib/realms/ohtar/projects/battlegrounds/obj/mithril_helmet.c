#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helmet");
  SetId(( {"helmet", "chainmail", "chain", "mail" } ));
  SetShort("a mithril chainmail helmet");
  SetAdjectives( ({"mithril", "chainmail", "chain", "mail"}) );
  SetLong(
    "This chainmail helmet is crafted of mithril. Flairing up from the "
    "back of the helmet and running all the way to the front is a solid "
    "piece of leather that has been braided and attached for more protection. "
    "This is a piece worn by greatest of warriors. The helmet protects the "
    "head and part of the neck. The front of the helmet is mostly solid mesh "
    "with openings only for the eyes and nose. This piece of amrour offers "
    "superb protection to the wearer's head, however does lack comfort. "
    "However not enough to not want to wear." );     
  SetMass(50);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_LARGE);
  SetMaterial("mithril");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(5000);
  SetDamagePoints(2500);
  SetArmourType(A_HELMET);  
}
