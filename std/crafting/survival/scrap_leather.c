/* Mahkefel @ haven 2017
 * scrap leather
 * made by cannibalizing items
 * used to make food you can't stop me
 */

#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("leather strip");
  SetShort("a leather strip");
  SetId( ({"leather", "strip"}) );
  SetAdjectives( ({ "leather" }) );
  SetLong(
    "A ragged strip of cured leather, torn from a larger piece."
  );
  SetMaterials( ({"leather"}) );
  SetMass(5);
  SetValue(5);
}


int direct_scrap_obj() {
  return 0;
}
