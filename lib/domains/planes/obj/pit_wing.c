/*
 * A heavy plate wingguard for pit fiends
 *
 * great for horrors. useless for everyone else
 */
#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("wingguard");
  SetId(( {"wingguard"} ));
  SetShort("an adamantine wingguard");
  SetAdjectives( ({"adamantine"}) );
  SetLong(
    "This is a wingguard made from some dense black metal. A thick"
    " brace runs along the tip of the wing, interlocking cleverly"
    " at the joints with thin sheets of metal which would fan out"
    " across the surface of the wing. It looks as if it would provide"
    " extreme protection to a winged creature, although only the"
    " strongest could take flight wearing such a device."
  );
  SetArmourType(A_WING);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetDamagePoints(5000);
  SetMass(500);
  SetMaterial("metal");
  SetProperty( "history",
    "Once used to guard the wings of angels serving the forces of Order,"
    " most of these sets of adamantine armour were lost in a fierce"
    " battle on the lower planes"
    " during the chaos of the godswar; the method of their forging is"
    " long lost. It is rumored they are now used by the vicious pit"
    " fiends that patrol that realm."
  );
  SetRepairDifficulty(200);
  SetSize(SIZE_LARGE);
  SetValue(5000);
  SetVendorType(VT_ARMOUR);
  SetWarmth(0);
  SetWear("The wingguard drapes over your wing.");
}

