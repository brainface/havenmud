/* Mahkefel @ haven 2017
 * mithril shavings
 * made by cannibalizing items
 * used to make iunno. 
 */

#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("mithril shaving");
  SetShort("a mithril shaving");
  SetId( ({"mithril", "shaving"}) );
  SetAdjectives( ({ "mithril" }) );
  SetLong(
    "A shiny sliver of mithril, gleaming in the light."
  );
  SetMaterials( ({"mithril"}) );
  SetMass(5);
  SetValue(10);
}


int direct_scrap_obj() {
  return 0;
}
