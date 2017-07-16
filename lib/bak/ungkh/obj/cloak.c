/* A cloak
 * Ranquest@Haven
 * 02/15/99
 */
#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({"black","velvet","thick"}) );
  SetShort("A black cloak");
  SetSize(SIZE_SMALL);
  SetWarmth(20);
  SetLong(
    "This cloak is as black as night, and made for skulking"
    " in shadows with. It is made of a thick velvet.");
  SetMass(20);
  // SetProtection(COLD, 3);
  // SetProtection(PIERCE, 1);
  // SetProtection(SLASH, 1);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_CLOAK);
  SetValue(20);
  }
