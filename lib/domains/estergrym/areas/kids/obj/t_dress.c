#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dress");
  SetShort("a soaked dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({
     "soaked",
     "tattered",
     "stained"
  }) );
  SetLong(
     "The dress appears to have been of relatively "
     "good make at one point.  However, now it is "
     "nothing more then a tattered clump of cloth.  "
     "The dress is stained with dark blood drops, and "
     "is completely soaked through."
  );
  SetMass(25);
  SetValue(10);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(10);
  SetSize(SIZE_SMALL);
  SetMaterial("textile");
  SetRepairDifficulty(5);
  SetWarmth(-5);
  SetArmourType(A_BODY_ARMOUR);
}

/** Approved by Laoise at Sat Sep 11 20:28:07 2004. **/
