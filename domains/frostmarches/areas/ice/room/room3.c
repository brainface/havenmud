#include <lib.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an arctic landscape");
SetClimate("arctic");
  SetLong("Icy and cold, the steep snow banks taper off in this area "
    "to open exploration to the northern directions.  The never-setting "
    "sun glares off of the snow, making seeing detail difficult.");
  SetObviousExits("northwest, north, northeast, south");
  SetItems( ([ ({ "icy cold steep snow banks", "icy cold steep snow bank", 
    "snow", "snow bank", "steep snow banks", "steep banks", "steep bank", 
    "bank", "steep snow bank", "icy snow banks", "cold snow banks", 
    "icy cold snow banks", "cold icy snow banks", "icy cold snow bank", 
    "icy cold bank", "icy cold banks", "cold icy snow bank", 
    "cold icy banks", "cold icy bank"}):
    "Rising to the south and lowering to the north, these snow banks "
    "make exploration to the sides impossible.",
    ({ "never-setting sun", "sun", "glare", "light", "things", "detail"}):
    "The sun glares off of the snow, causing any other things in "
    "the area to be lost in the light.",
    ({ "arctic landscape", "area" }):
    (: GetLong :),
    ({ "northern directions", "sides", "directions" }):
    "The steep snow banks that limit exploration to the "
    "sides taper off to the north, allowing passage."]) );
  SetExits( ([ "northwest" : ICE_ROOM + "/icelake.c",
    "north": ICE_ROOM + "/ropebridge.c",
    "northeast": ICE_ROOM + "/icecave.c",
    "south": ICE_ROOM + "/room2.c"]) );
  SetInventory( ([ ICE_NPC + "/wolf.c" : 1 ]) );
}


/* Approved by Balishae on Sat Oct  4 23:05:08 1997. */
