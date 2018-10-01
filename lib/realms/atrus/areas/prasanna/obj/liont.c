#include <lib.h> 
#include "prasanna.h"
inherit LIB_ITEM;

static void create() {

  item::create();
  SetKeyName("lion");
  SetShort("a topiary of a lion");
  SetId("lion","topiary");
  SetLong("This perfectly sculptured topiary is in the form "
          "of a lion. The body has well formed muscle structure and "
          "stands as tall as the average human. The mane is of rough "
          "cut branches that seem to flow down the neck of the lion. "
          "The tail protrudes straight out, but it is not held up with "
          "wires or string. It appears that the plant grew out straight "
          "naturally, just for the tail.");
  SetPreventGet("The roots are planted firmly in the ground."); 
  }
