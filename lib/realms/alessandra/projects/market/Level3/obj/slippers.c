#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();

  SetKeyName("slippers");
  SetShort("a pair satin slippers");
  SetId( ({"slippers"}) );
  SetAdjectives( ({"satin", "pair of", "exquisite"}) );
  SetLong(
    "Exquisite beading graces the toe of these satin slippers. The sole is "
    "leather and the satin is a dusty rose color. They look fit for a queen."
    );
  SetMass(10);
  SetWarmth(3);
  SetProperty("multiples", 1);
  SetSize(SIZE_MEDIUM);
  SetValue(175);
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({"textile"}) );
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_BOOT); 

}
