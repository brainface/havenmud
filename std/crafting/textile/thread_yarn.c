//Illura@Haven, Aug 2011
//Fine String for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("fine yarn");
  SetShort("a fine bit of yarn");
  SetId( ({"yarn"}) );
  SetAdjectives( ({ "fine", "bit"}) );
  SetLong("This is a thick twist of woolen yarn. It seems quite durable.");
  SetMass(1);
  SetValue(1);
}

