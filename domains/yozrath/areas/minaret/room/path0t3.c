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
    "pool" : "The water from above lands inside this bowl-shaped "
        "pool before continuing on its path down the channel.",
    "minaret" : (: GetLong :),
    "water" : "The water flows down from the top of the "
      "minaret, providing sustenance to an array of flora.",
    "flora" : "The various flora growing upon the minaret "
      "are lush and beautiful.",
    ( { "sand", "desert", "sands" }) : "The immense Yozrath Desert expands "
        "further than the eye can see.",
    ]) );
  SetItemAdjectives( ([
    "desert" : ({ "immense", "yozrath" }),
    "water" : ({ "flowing" }),
    "minaret" : ({ "white" }),
  ]) );
  SetInventory( ([
    MIN_NPC "/worker" : random(3) +1,
    MIN_NPC "/guardian" : random(2) +1,
    MIN_OBJ "/rope3" : 1,
    MIN_OBJ "/r_tree" : random(2),
    MIN_OBJ "/channel" : 1,
    MIN_OBJ "/r_plant" : random(4) +1,
    MIN_OBJ "/view_wt3" : 1,
    MIN_OBJ "/small_waterfall" : 1,
  ]) );
  SetListen( ([
    "default" : "The flowing water gurgles as it leaps into a waterfall.",
    ]) );
  SetSmell( ([
    "default" : "The arid air carries the scent of the sand.",
    ]) );
  SetExits( ([
    "northwest" : MIN_ROOMS "/path1t3",
  ]) );
}
