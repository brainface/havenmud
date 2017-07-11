#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("dress");
  SetId(( { "dress", "blue dress", "light blue dress" } ));
  SetShort("a light blue dress");
  SetLong("This is a common light blue dress that affords little protection.");
  SetMass(100);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetWarmth(10);
  SetValue(175);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(225);
  // SetProtection(PIERCE,2);
  // SetProtection(SLASH,2);
  // SetProtection(COLD,3);
  // SetProtection(MAGIC,4);
  // SetProtection(ACID,3);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}
