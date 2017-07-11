#include <lib.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a rope bridge");
SetClimate("arctic");
  SetLong("Rocked by the strong winds nearby, this rope bridge is "
    "the only way to reach the other side of this chasm.  Legends "
    "say that an abominable snowman lives on the other side.");
  SetObviousExits("north, northeast, south");
  SetItems( ([ ({ "rope bridge", "bridge", "rope" }):
    (: GetLong :),
    ({ "long chasm", "wide chasm", "chasm" }):
    "Long and wide, the chasm would make even the bravest "
    "of climbers blanch at walking across this bridge.",
    ({ "strong winds", "wind", "winds", "whistle", "eerie cadence", 
      "cadence" }):
    "How do you expect to see those things? Use listen.",
    ({ "other side of chasm", "other side", "side", 
    "abominable snowman", "snowman"}):
    "Legend says that an abominable snowman lives on the other side.  "
    "But that's just a legend.  Isn't it?"]) );
  SetListen( ([ ({ "strong winds", "winds", "wind", "whistle",
    "eerie cadence", "cadence", "default" }):
    "The strong winds whistle through the chasm, creating "
    "an eerie cadence."]) );
  SetExits( ([ "north" : ICE_ROOM + "/yetiroom.c",
    "northeast": ICE_ROOM + "/boneroom.c",
    "south": ICE_ROOM + "/room3.c"]) );
  SetProperty("no bump", 1);
}


/* Approved by Balishae on Sat Oct  4 23:02:02 1997. */
