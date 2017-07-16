/* Mahkefel @ haven 2017
 * scrap "natural"
 * made by cannibalizing items
 * used to make food you can't stop me
 * also dark torches
 */

#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("gristle");
  SetShort("a bit of gristle");
  SetId( ({"bit","gristle"}) );
  SetAdjectives( ({ "bit","of" }) );
  SetLong(
    "A fiberous and crunchy mass of... something. It looks natural, at least."
  );
  SetMaterials( ({"natural"}) );
  SetMass(5);
  SetValue(5);
}


int direct_scrap_obj() {
  return 0;
}
