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
    "minaret" : ({ "white" } ),
  ]) );
  SetListen( ([
    "default" : "The babbling sound of water trickles down the minaret.",
    ]) );
  SetSmell( ([
    "default" : "The arid air carries the scent of the sand.",
    ]) );
  SetInventory( ([
    MIN_OBJ "/view_wt3" : 1,
    MIN_NPC "/worker" : random(3) +1,
    MIN_NPC "/guardian" : random(2) +1,
    MIN_OBJ "/r_tree" : random(2),
    MIN_OBJ "/r_plant" : random(4) +1,
    MIN_OBJ "/channel" : 1,
    ]) );
  SetExits( ([
    "southwest" : MIN_ROOMS "/path8t3",
    "northeast" : MIN_ROOMS "/path10t3",
  ]) );
}
