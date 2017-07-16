

#include <lib.h>
#include <std.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("jar");
  SetId( ({"jar", "organs" }));
  SetShort("a large jar of organs");
  SetAdjectives( ({ "large", "organ", "of" }) );
  SetLong("This huge glass jar is filled with various"
          " organs floating in an embalming fluid. The"
          " organs are of various bodies and are quite"
          " vile.");
  SetMass(50);
  SetValue(0);
  SetDestroyOnSell(1);
  SetMaterial( ({"natural"}) );
  }
  
