/*   Portia  10-23-98
    A storage room for the general store.
*/

#include <lib.h>
#include <std.h>

inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetInventory( ([
//    STD_STORAGE "pouch" : 5,
    STD_FISHING "pole" : 3,
    STD_INSTRUMENTS "lyre" : 1,
    STD_INSTRUMENTS "mandolin" : 1,
    STD_POLE "staff" : 3,
    STD_SLASH "sword" : 3,
    STD_LIGHT "torch" : 8,
          ]) );
  SetPurgeInterval(4);
  }
