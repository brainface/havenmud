//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("inside a hut");
  SetClimate("indoors");
  SetAmbientLight(25);
  SetLong(
    "This is the hut of Big Snow, an ostrasized giant. He  "
    "lives here with his wife away from the others of Ungkh. "
    "The hut is simply furnished, with a comfortable bed in "
    "one corner, and a rickety, although very large table and "
    "set of chairs in the other. An enormous ladder leads into "
    "a loft above. "
    );
  SetSmell("The scent here seems slightly more pleasant.");
  SetListen("A fire crackles in the hearth.");
  SetItems( ([
    ({ "hut" }) :
       (: GetLong :),
    ({ "fire", "hearth" }) :
    "The hearth is a smoky fireplace set into the wall. It is "
    "large enough for an entire human to roast inside.",
    ({ "bed" }) : 
    "The bed could sleep a whole family of elves comfortably.",
    ({ "table", "set of chairs" }) : 
    "A small grove of trees gave their lives to create this "
    "massive dining set.",
    ({ "loft" }) : 
    "The loft is above this room.",
    ({ "ladder" }) : 
    "Each rung of the ladder is as big as a halfling.",
    ]) );
  SetExits( ([
    "out" : U_ROOM + "road06",
    "up" : U_ROOM + "loft",
    ]) );
  SetInventory( ([
    U_NPC "bigsnow" : 1,
    ]) );
  }
