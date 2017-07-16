// Wolf pelt
// Davantalus
// 20040721

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("pelt");
  SetShort("wolf pelt");
  SetLong(
      "This soft brown and red pelt came from a red "
      "wolf. The skin is long and abnormally shaped "
      "with just a few small imperfections from some "
      "scuffle it's previous owner was in. The leg "
      "fur is still attached, so the ovoid fur "
      "diverges occasionally."
  );
  SetId( ({ "pelt" }) );
  SetAdjectives( ({"wolf", "wolves", "wolves'"}) );
  SetValue(7);
  SetMass(3);
  SetVendorType(VT_FUR);
}
