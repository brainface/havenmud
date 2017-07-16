//  Gypsy Camp near Gothic Manor/Cemetery
//  Alessandra 2014

#include <lib.h>
inherit LIB_ITEM;
inherit LIB_ENTER;
inherit LIB_STORAGE;
inherit LIB_EXITS;
inherit LIB_MESSAGES;

static void create() {
  item::create();

  SetKeyName("wagon");
  SetMaterials( ({ "natural" }) );
  SetShort("a colorful wagon");
  SetId(  ({"wagon", "caravan", "vardo"}) );
  SetAdjectives( ({"colorful"}) );
  SetLong(
     "This is a wagon. Which has no description."
     );
  SetPreventGet("You can't be serious.");

}

mixed direct_enter_obj() {
  return 1;
}

