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
    "incline."
  );
  SetItems( ([
    ({ "path", "ground", "stone" }) : 
        "The path is lined with stone and winds its way up the minaret.",
    "minaret" : (: GetLong :),
    ]) );
  SetListen( ([
    "default" : "The babbling sound of water trickles down the minaret.",
    ]) );
  SetSmell( ([
    "default" : "The arid air carries the scent of the sand.",
    ]) );
  SetItemAdjectives( ([
    "path" : ({ "lined" }),
    "water" : ({ "flowing" }),
    "minaret" : ({ "white" }),
  ]) );
  SetInventory( ([
    MIN_NPC "/worker" : random(3) +1,
    MIN_OBJ "/r_tree" : random(2),
    MIN_OBJ "/r_plant" : random(5)+2,
    MIN_OBJ "/channel" : 1,
    ]) );
  SetExits( ([
    "north" : MIN_ROOMS "/path9t1",
    "south" : MIN_ROOMS "/path11t1",
  ]) );
}
