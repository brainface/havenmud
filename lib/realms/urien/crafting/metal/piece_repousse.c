//Illura@Haven, Aug 2011
//Repousse Piece for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("repousse piece");
  SetShort("a repousse piece of many metals");
  SetId( ({"piece"}) );
  SetAdjectives( ({ "repousse", "many", "metals" }) );
  SetLong("The large disc of metal depicts a gruesome battle scene in relief, in bronze and silver, chased with gold. The scene is quite lovely in craftsmanship, though grim in scope.");
  SetMass(2);
SetValue(10);
}
