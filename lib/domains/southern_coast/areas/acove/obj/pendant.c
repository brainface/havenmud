/* opal pendant
  Zara 8/14/98
*/

#include <lib.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pendant");
  SetShort("a black opal pendant");
  SetId( ({"pendant"}) );
  SetAdjectives( ({"gleaming","black","opal"}) );
  SetLong("This gleaming, black opal pendant is suspended from a fine "
         "golden chain. It is the size of a small plum.");
  SetMass(30);
  SetValue(2000);
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_AMULET);
  SetVendorType(VT_TREASURE);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(700);
  SetMaterials( ({ "natural", "metal" }) );
  SetRepairDifficulty(25);
}
