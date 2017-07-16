//  Gypsy Camp near Gothic Manor/Cemetery
//  Alessandra 2014

#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("vardo");
  SetMaterials( ({ "natural" }) );
  SetShort("a colorful wagon");
  SetId( ({"moonman","vardo"}) );
  SetAdjectives( ({"colorful"}) );
  SetLong(
     "This is a wagon. Which has no description."
     );
  SetPreventGet("You can't be serious.");

}
