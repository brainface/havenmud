
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("wagon");
  SetShort("a small flower wagon");
  SetId(  ({"wagon"}) );
  SetAdjectives( ({"small", "flower"}) );
  SetLong(
     "Made of wood with a metal pull handle, this is just larger than a "
     "child's wagon. Several baskets line the bed of the wagon, each "
     "containing bunches of various flowers. If you could find the "
     "vendor you could probably purchase some."
     );
  SetPreventGet("Do you need that many flowers? Perhaps you should leave some "
     "for others.");

}  