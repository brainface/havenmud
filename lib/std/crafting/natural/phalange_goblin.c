//Illura@Haven, Aug 2011
//Goblin Phalange for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("goblin phalange");
  SetShort("a shard of goblin phalange");
  SetId( ({"phalange"}) );
  SetAdjectives( ({ "goblin" }) );
  SetLong("This is the small finger or toe bone of a goblin. The little nub has teeth marks on it from being gnawed on and cracked open to get at the marrow.");
  SetMass(1);
  SetValue(1);
}
