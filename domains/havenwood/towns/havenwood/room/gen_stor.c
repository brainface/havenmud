/*   portia
    A storage room for the general store.
*/

#include <lib.h>
#include <std.h>
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetInventory( ([
//      STD_STORAGE  "pouch" : 1,
      STD_FISH     "pole"  : 1,
      STD_LIGHT    "torch" : 5,
      STD_OBJ      "havenwoodmap" : 2,
      STD_PROJECTILE "long_bow" : 3,
      ]) );
  SetPurgeInterval(4);
}
