#include <lib.h>
#include <jump.h>
#include "../include/minaret.h"

inherit LIB_ITEM;
inherit LIB_JUMP;
 
 
static void create() {
   item::create();
   SetShort("a large oil painting");
   SetLong("The large canvas is beautifully painted and depicts "
           "a strange desert with a curious spiral minaret rising "
           "out of the vast sand.  It levitates in the air, seemingly "
           "of its own will.");
   SetId( ({"painting"}) );
  SetJump(
    MIN_ROOMS "/observatory", JUMP_INTO
  );
   SetMaterials( ({"wood", "natural"}) );
   SetAdjectives( ({ "large","oil" }) );
   SetKeyName("painting");
   SetPreventGet("The painting refuses to be budged!");
}
