//Illura@Haven, Aug 2011
//Gold Filigree for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("gold filigree");
  SetShort("a delicate gold filigree");
  SetId( ({"filigree"}) );
  SetAdjectives( ({ "delicate", "gold" }) );
  SetLong("This is a delicate jewelry metalwork made of golden twisted threads. It's very pretty.");
  SetMass(1);
  SetValue(3);
}
