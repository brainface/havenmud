/* A toga
 * Ranquest@Haven
 * 02/15/99
 */
#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("toga");
  SetId( ({ "toga" }) );
  SetAdjectives( ({"white"}) );
  SetShort("A white toga");
  SetLong(
    "This white toga looks quite expensive. It is relatively"
    " free of stains and unrumpled.");
  SetMass(20);
  SetWarmth(10);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  // SetProtection(COLD, 3);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_CLOAK);
  SetValue(100);
  }
