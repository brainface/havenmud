
#include <lib.h>
#include <std.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("scroll case");
  SetId( ({"case"}));
  SetShort("a scroll case");
  SetAdjectives( ({"wood", "wooden", "small", "scroll"}) );
  SetLong("This small wooden scroll case is sealed by a  "
          "wax seal. On the seal is an imprint of a "
          "balance and a dragon surrounding the balance. ");
  SetMass(50);
  SetValue(0);
  SetDestroyOnSell(1);
  SetMaterial( ({"wood"}) );
  }
