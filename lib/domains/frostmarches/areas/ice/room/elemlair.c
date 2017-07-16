#include <lib.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a frigid lair");
  SetLong("Shattered icicles and piles of snow are scattered "
    "around the room, which appears to be the lair of a dreaded "
    "ice elemental.  Although the effect looks like it was meant to be "
    "frightening, it merely adds a lived-in atmosphere to the room.");
  SetObviousExits("west");
  SetItems( ([ ({ "shattered icicles", "icicles", "shard", "shards",
    "crystalline shard", "crystalline shards", "icicle", "shattered icicle"}):
    "Crystalline shards litter the room.",
    ({ "frigid lair", "lair", "room", "radiance", "area"}): (: GetLong :),
    ({ "small stacks of packed snow", "packed snow stacks", 
      "small stack of packed snow", "small stack of snow", 
      "small stacks of snow", "snow", "piles of snow", "pile", "piles",
      "stack", "stacks", "stack of snow", "stacks of snow", 
      "stack of packed snow", "stacks of packed snow",
      "pile of snow", "packed snow stack", 
      "snow piles", "snow pile", "scattered piles", "scattered snow piles"}):
    "Small stacks of packed snow appear at random "
    "throughout the room."]) );
  SetExits( ([ "west" : ICE_ROOM + "/icecave.c"]) );
SetClimate("underground");
  SetInventory( ([
         ICE_NPC + "/elemental" : 1,
        ]) );
}


/* Approved by Balishae on Sat Oct  4 23:18:38 1997. */
