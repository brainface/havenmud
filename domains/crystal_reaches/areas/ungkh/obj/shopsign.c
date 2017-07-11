//Selket@Haven
//2006
#include "../ungkh.h"
#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sign");
  SetShort("a sign");
  SetId( ({"sign"}) );
  SetLong("The sign stands in front of the shop.");
  SetMaterial( ({"wood"}) );
  SetPreventGet("After trying unsuccessfully to yank the sign from "
    "the post, you realize you didn't really want it anyway.");
  SetRead("Riesin's Herbs and Stuff.");
}
