/*   Davantalus@Haven 2006024
     Luna's wedding dress.
*/

#include <lib.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("dress");
  SetShort("a gorgeous white wedding dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"gorgeous", "white", "wedding"}) );
  SetLong(
    "This snow white wedding dress was sewn for Luna An'Duheart for "
    "her marriage to Atrus. The bodice and skirt are constructed from "
    "a stark white stain. While simple the dress is both classy but "
    "sexy. It probably took close to an hour to put the entire ensemble on."
    );
  SetValue(5000);
  SetMass(45);
  SetMaterials( ({ "textile" }) );
  SetWarmth(50);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
}