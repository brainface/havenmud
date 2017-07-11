// Proxy!

#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("robe");
  SetId( ({ "robe" }) );
  SetAdjectives( ({ "filthy", "discolored" }) );
  SetShort("a filthy discolored robe");
  SetLong(
     "Perhaps there was a time when this garment was once a solid green color, although this is not so "
     "anymore. Small parts of the robe seem to retain their original color, while much of it has an "
     "assortment of stains, rips, tears, holes, and what appears to be smeared feces upon the bottom "
     "edges. Yellow, red, and brown are merely some of the colors that have been heavily soaked into "
     "the fabric. It appears as though whoever owned this robe previous did not care for it much, if "
     "at all. "
  );
  SetMass(150);
  SetWarmth(1);
  SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_CLOTH);
  SetMaterial( ({ "textile" }) );
  SetArmourType(A_BODY_ARMOUR);
  // SetProtection(COLD, 1);
  SetSize(SIZE_MEDIUM);
}
