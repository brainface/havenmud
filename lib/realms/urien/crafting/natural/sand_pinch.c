//Illura@Haven, Aug 2011
//Pinch of Sand for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("sand pinch");
  SetShort("a pinch of white sand");
  SetId( ({"pinch", "sand"}) );
  SetAdjectives( ({ "white" }) );
  SetLong("Someone went through the trouble of cleaning this sand of all debris. Perhaps it is a remnant of some summer holiday on a distant beach. It smells of salt and sea.");
  SetMass(1);
  SetValue(1);
}
