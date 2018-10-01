//Illura@Haven, Aug 2011
//Red Glass for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("red glass");
  SetShort("a shard of red glass");
  SetId( ({"shard", "glass"}) );
  SetAdjectives( ({ "red" }) );
  SetLong("This shard of red glass is curved, perhaps from a goblet or a bowl. It is free of bubbles and imperfections, a sure sign it was made by a master glassblower.");
  SetMass(1);
  SetValue(4);
}
