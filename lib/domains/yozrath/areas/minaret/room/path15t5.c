#include <lib.h>
#include "../minaret.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("the path along the spiral minaret");
  SetLong(
    "The path along the minaret is lined with stone and has a "
    "small channel running along side of it, flowing with water "
    "from the top of the minaret.  The minaret itself has been "
    "painted white.  The path leading to the top has a gradual "
    "incline.  There is quite a view from here."
  );
  SetItems( ([
    ({ "path", "ground", "stone" }) : 
        "The path is lined with stone and winds its way up the minaret.",
    "minaret" : (: GetLong :),
    "pool" : "The water from above lands inside this bowl-shaped pool "
        "before continuing on its path down the channel.",
    "water" : "The water flows down from the top of the "
      "minaret, providing sustenance to an array of flora.",
    "flora" : "The various flora growing upon the minaret "
      "are lush and beautiful.",
    ( { "sand", "desert", "sands" }) : "The immense Yozrath Desert expands "
        "further than the eye can see.",
    ]) );
  SetItemAdjectives( ([
    "desert" : ({ "immense", "yozrath" }),
    "path" : ({ "lined" }),
    "water" : ({ "flowing" }),
    "minaret" : ({ "white" }),
  ]) );
  SetInventory( ([
    MIN_NPC "/worker" : random(2) +1,
    MIN_NPC "/guardian" : random(2) +1,
    MIN_NPC "/warrior" : random(2) +1,
    MIN_OBJ "/rope7" : 1,
    MIN_OBJ "/view_t5" : 1,
    MIN_OBJ "/r_tree" : random(2),
   MIN_OBJ "/r_plant" : random (2) +1,
    MIN_OBJ "/small_waterfall" : 1,
    ]) );
  SetListen( ([
    "default" : "Water splashes from the fall into the collection pool.",
    ]) );
  SetSmell( ([
    "default" : "The arid air carries the scent of the sand.",
    ]) );
  SetInventory( ([
    MIN_OBJ "/channel" : 1,
    ]) );
  SetExits( ([
    "west" : MIN_ROOMS "/path14t5",
  ]) );
}
