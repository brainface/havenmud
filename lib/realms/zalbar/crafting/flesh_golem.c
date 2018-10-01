#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("flesh_golem");
  SetShort("a flesh golem body");
  SetId( ({ "flesh_golem", "body", "golem", "golem_body" }) );
  SetAdjectives( ({ "flesh", "golem" }) );
  SetLong(
    "A lifeless body that is six feet long stitched together from "
	"different");
  SetMass(64000);
  SetValue(10000);
  SetDamagePoints(20000);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_MAGIC);
}