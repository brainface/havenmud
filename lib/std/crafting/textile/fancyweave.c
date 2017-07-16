//Illura@Haven, Aug 2011
//Fancyweave Scrap for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("fancyweave");
  SetShort("a sample of glimmering fancyweave");
  SetId( ({"sample", "fancyweave"}) );
  SetAdjectives( ({ "glimmering" }) );
  SetLong("The gilt and shimmering threads in this scrap of fancyweave shine brightly, although the nap of the weave shows a little wear. Perhaps at one time the fabric belonged to someone very special.");
  SetMass(1);
  SetValue(5);
}

