/* breastplate
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetShort("a heavy breastplate");
  SetKeyName("breastplate");
  SetId( ({"breastplate","plate"}) );
  SetAdjectives( ({"heavy","strong"}) );
  SetArmourType(A_SHIRT);
  SetLong(
    "This heavy breastplate looks very strong, and as if it"
    " could protect against quite a lot of damage.");
  SetVendorType(VT_ARMOUR);
  // SetProtection(BLUNT,15);
  // SetProtection(SLASH,20);
  SetArmourClass(ARMOUR_PLATE);
  // SetProtection(PIERCE,20);
  SetSize(SIZE_VERY_LARGE);
  SetMass(500);
  SetMaterial("metal");
  SetWarmth(0);
  SetValue(1000);
  SetDamagePoints(2000);
  SetRepairDifficulty(50);
  SetRepairSkills( ([
    "armour smithing" : 10,
    "metal working" : 10,
    ]) );
  }
