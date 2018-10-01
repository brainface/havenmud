#include <lib.h>
#include <jump.h>

inherit LIB_ITEM;
inherit LIB_JUMP;
 
 
static void create() {
   item::create();
   SetShort("a large clay pot");
   SetLong(
    "This large clay pot is painted with red "
    "outlines of fierce wolves.  it looks "
    "deeper than it is tall.  A strange purple "
    "fog wafts out from the opening on top."
   );
   SetId( ({"pot"}) );
  SetJump(
    DIR_STANDARD_DOMAIN "/room/portal", JUMP_INTO
  );
   SetMaterials( ({"natural"}) );
   SetAdjectives( ({ "large","clay" }) );
   SetKeyName("pot");
   SetPreventGet("This large clay pot is too heavy even for you!");
}
