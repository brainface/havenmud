/* Mahkefel @ haven 2017
 * cloth rag
 * made by cannibalizing items
 * used to make torches, bandages
 */

#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("cloth rag");
  SetShort("a cloth rag");
  SetId( ({"rag"}) );
  SetAdjectives( ({ "cloth" }) );
  SetLong(
    "A cloth rag, tattered beyond recognition. Clearly no longer "
    "useful for its original purpose, perhaps it could be repurposed "
    "to another."
  );
    SetMaterials( ({"textile"}) );
  SetMass(1);
  SetProperty("craft_fabric",1);
}

int direct_scrap_obj() {
  return 0;
}
