#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("chalice");
  SetShort("a golden bejeweled chalice");
  SetId( ({"chalice"}) );
  SetAdjectives( ({"bejeweled","golden"}) );
  SetLong("Years ago this chalice was the prized possession"
          " of a wealthy individual. It has emeralds and rubies"
          " embedded into the golden frame that add a pleasant"
          " look as well as immeasurable value to it.");
  SetMass(50);
  SetValue(3500);
  SetVendorType(VT_TREASURE);
  SetMaterial("metal");
}
