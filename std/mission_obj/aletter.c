
#include <lib.h>
#include <std.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("letter");
  SetId( ({"letter"}));
  SetShort("a letter");
 
  SetLong("This letter was placed inside a white envelope "
          "with wax seal affixed to the outside flap. "
          "The wax seal seems to be an arcane symbol.");
  SetMass(50);
  SetValue(0);
  SetDestroyOnSell(1);
  SetMaterial( ({"natural"}) );
  }
