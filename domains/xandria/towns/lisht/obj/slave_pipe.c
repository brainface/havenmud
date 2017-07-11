#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("wood pipe");
  SetShort("a wood pipe");
  SetAdjectives( ({ "wood", "wooden" }) );
  SetId( ({ "pipe", "bard_instrument" }) );
  SetVendorType(VT_INSTRUMENT);
  SetMaterials( ({ "wood" }) );
  SetClass(6);
  SetDamagePoints(1200);
  SetValue(35);
  SetLong(
    "This wood is a short (12\"), thick wooden device easily carved by "
    "the slaves of Lisht. Its primitive creation does not diminish its "
    "quality of sound."
    );
  SetMass(15);
  SetProperty("history", "This pipe was made in the slave sections of Lisht.");
}
