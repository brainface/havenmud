//Illura@Haven
//Sept 2009
//tusk
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("tusk");
  SetShort("a long ivory tusk");
  SetId( ({"tusk"}) );
  SetAdjectives( ({"long", "ivory"}) );
  SetLong("This is a huge tusk from a rare tundra beast.");
  SetValue(300);
  SetMass(10);
  SetVendorType(VT_TREASURE);
 }
