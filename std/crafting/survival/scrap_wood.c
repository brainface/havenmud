/* Mahkefel @ haven 2017
 * scrap wood
 * made by cannibalizing items
 * used to make torches
 */

#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("scrap wood");
  SetShort("a piece of scrap wood");
  SetId( ({"piece", "wood"}) );
  SetAdjectives( ({ "piece", "of", "scrap" }) );
  SetLong(
    "A pointy piece of scrap wood--it's hard to tell if it was the haft "
    "of some tool or part of a larger structure."
  );
  SetMaterials( ({"wood"}) );
  SetMass(5);
  SetValue(5);
}


int direct_scrap_obj() {
  return 0;
}
