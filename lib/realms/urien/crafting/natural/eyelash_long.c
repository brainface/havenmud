//Illura@Haven, Aug 2011
//Long Eyelash for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("long eyelash");
  SetShort("a long eyelash");
  SetId( ({"eyelash", "lash"}) );
  SetAdjectives( ({ "long" }) );
  SetLong("It almost floats off of your hand, this ephemeral bit of loose hair. It is rather long, blonde at the tip.");
  SetMass(1);
  SetValue(1);
}
