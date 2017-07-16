#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  ::create();
  SetKeyName("amulet");
  SetId(( { "amulet","collar"} ));
  SetShort("a blue and purple collar");
  SetLong("Though a degrading show of slavery this collar offers "
          "decent protection vice nothing at all.");
  SetMass(5);
  SetValue(150);
  SetDamagePoints(420);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_AMULET);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetWear("The amulet fastens in place, leaving a snug fit.");
}