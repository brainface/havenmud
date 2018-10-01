//Illura@Haven, Aug 2011
//Linen Scrap for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("linen scrap");
  SetShort("a scrap of linen");
  SetId( ({"scrap"}) );
  SetAdjectives( ({ "linen" }) );
  SetLong("This is a shredded scrap of pale filmy linen. It isn't worth very much on its own, but perhaps it could be pieced together with something.");
  SetMass(1);
}
