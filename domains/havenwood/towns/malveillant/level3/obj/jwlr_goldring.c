//  Fancy Ring for Jeweler
//  Alessandra

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("gold ring");
  SetId(( { "ring","gold ring"} ));
  SetShort("an elegant gold ring");
  SetLong(
     "This simply stated gold ring is elegant. The band is engraved "
     "with an ornate leafy pattern and the edges curve. It is "
     "obviously expensive and meant strictly for decoration."
     );
  SetMass(3);
  SetValue(460);
  SetSize(SIZE_MEDIUM);
  SetVendorType(VT_TREASURE|VT_ARMOUR);
  SetDamagePoints(75);
  SetMaterial("metal");
  SetArmourClass(ARMOUR_CHAIN);
  SetArmourType(A_RING);
  SetWear("The ring slides easily onto your finger.");

}
