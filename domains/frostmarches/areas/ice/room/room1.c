#include <lib.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an icy road");
  SetClimate("arctic");
  SetLong("The weather in this area is getting colder, as is evident "
    "by an icy circle on the ground where some spilt water froze.  "
    "The road travels south to the snowy region of Keryth, and north to "
    "a region of snow and ice.  Snowstorms appear far off to the north.");
  SetObviousExits("north, south");
  SetItems( ([ ({ "cold weather", "weather"}):
    "The weather is getting colder to the north.",
    ({ "area"}): (: GetLong :),
    ({ "icy circle", "ice", "circle", "ice circle", "circle of ice", "ground", 
    "spilt water", "spilled water", "water", "frozen water", 
    "frozen spilt water", "spilt frozen water", "frozen spilled water",
    "spilled frozen water", "road" }):
    "A circle of ice has been formed of spilt water on the ground.",
    ({ "icy road", "road", "caves", "Keryth", "snowy region of Keryth" }):
    "The road leads to the snowy region of Keryth to the south.",
    ({ "region of snow and ice", "region of snow", "region of ice", 
    "region" }):
    "The road leads to a region of snow and ice to the north.",
    ({"snowstorms", "snowstorm", "snow", "storms"}):
    "Snowstorms appear far off to the north."]) );
  SetExits( ([ "north" : ICE_ROOM + "/room2.c",
      "south": ICE_ROOM + "/road5.c"]) );
}


/* Approved by Balishae on Sat Oct  4 23:07:32 1997. */
