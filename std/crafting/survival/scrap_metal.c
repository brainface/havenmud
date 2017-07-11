/* Mahkefel @ haven 2017
 * scrap metal
 * made by cannibalizing items
 * used to make iunno. Caltrops? Lockpicks?
 */

#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("scrap metal");
  SetShort("a piece of scrap metal");
  SetId( ({"piece", "metal"}) );
  SetAdjectives( ({ "piece", "of", "scrap" }) );
  SetLong(
    "A mangled bit of jagged metal."
  );
  SetMaterials( ({"metal"}) );
  SetMass(5);
  SetValue(5);
}


int direct_scrap_obj() {
  return 0;
}
