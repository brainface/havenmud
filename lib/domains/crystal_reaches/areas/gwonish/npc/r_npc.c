#include <lib.h>

inherit LIB_ITEM; 

static void create() 
{
  ::create();
  SetId("footprint");
  SetShort("a footprint");
  SetLong("This looks like the footprint of an animal that may have been "
          "here at one time.");
  SetPreventGet("You can't pick up a footprint!");
}
