/* dirty tunic
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
  SetShort("a dirty tunic");
  SetKeyName("tunic");
  SetId( ({"tunic"}) );
  SetAdjectives("dirty");
  SetArmourType(A_SHIRT);
  SetWarmth(10);
  SetLong(
    "This tunic is absolutely filthy. Dirt and muck cover it,"
    " and it is rumpled quite possibly beyond saving.");
  SetVendorType(VT_ARMOUR);
  // SetProtection(COLD, 3);
  SetSize(SIZE_VERY_LARGE);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(20);
  SetValue(10);
  SetDamagePoints(200);
  SetRepairDifficulty(5);
  SetRepairSkills( ([
    "textile working" : 1,
    ]) );
  }
