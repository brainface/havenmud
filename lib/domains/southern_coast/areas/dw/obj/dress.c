/* A classic burial dress.  Gotta look your best, ya know? */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("dress");
  SetId( ({ "dress" }) );
  SetAdjectives( ({ "thin", "white" }) );
  SetShort("a thin white dress");
  SetLong("This thin piece of cloth is a lacy formal dress which "
          "leaves very little to the imagination. Its thin material "
          "can be seen through fairly easily.");
  SetArmourType(A_BODY_ARMOUR);
  // SetProtection(MAGIC, 15);
  SetWarmth(5);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(100);
  SetValue(100);
  SetMass(30);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetProperty("magic", "This dress withstands magic somewhat.");
  }
