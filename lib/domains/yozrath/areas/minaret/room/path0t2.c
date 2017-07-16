/* I added no steal  nor cast here
     because you cant do that while 
     dangling from a rope */

#include <lib.h>
#include "../minaret.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetProperty("no magic", 1);
  SetProperty("no steal", 1);
  SetClimate("arid");
  SetShort("dangling upon a rope");
  SetLong(
    "A small waterfall rushes passed while dangling upon this rope.  "
    "The desert surrounds the minaret, an abrupt change from sand "
    "to flora." 
     );
  SetInventory( ([
    MIN_OBJ "/small_waterfall" : 1,
    MIN_OBJ "/rope2" : 1,
  ]) );
  SetItems( ([
    ( { "sand", "desert" }) : "The immense Yozrath Desert expands "
        "further than the eye can see.",
    "minaret" : (: GetLong :),
    "pool" : "The water from above lands inside this bowl-shaped pool "
          "before continuing on its path down the channel.",
    "water" : "The water flows down from the top of the "
        "minaret, providing sustenance to an array of flora.",
    "flora" : "The various flora growing upon the minaret "
        "are lush and beautiful.",
    "channel" : "Water jumps from the upper to channel into "
        "a collection pool on the lower channel.",
    ]) );
  SetItemAdjectives( ([
    "desert" : ({ "immense", "yozrath" }),
  ]) );
  SetListen( ([
    "default" : "The water rushes by in a soft hush.",
    ]) );
  SetSmell( ([
    "default" : "The arid air carries the scent of the sand.",
    ]) );
}
