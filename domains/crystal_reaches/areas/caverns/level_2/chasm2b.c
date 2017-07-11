/*  Level #2 - Chasm - Section #2 (The Bridge crossing) */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(50);
  SetShort("the chasm bridge crossing");

  SetLong("This section of the chasm is the narrowest part.  Found here are "
          "two ropes that are leading across the chasm.  Although, it looks "
          "too dangerous to even consider crossing.  Across the chasm "
          "there is an small encampment with all of the tools and materials "
          "to make a bridge.  Looking around the walls seem to sparkle in the "
          "dim light, below the chasm continues it's descent into oblivion.  "
          "The ledge leads to the north and south following the chasm.");

  SetSmell( ([
    "default"  :  "The distinct smell of water drifts into your nose.",
  ]) );

  SetListen( ([
    "default"  :  "A very loud roaring sound comes from the northern end of "
                  "the chasm.",
  ]) );

  SetExits( ([
    "north"  :  ROOMLV2 + "/chasm2a",
    "south"  :  ROOMLV2 + "/chasm2c",
  ]) );
  SetObviousExits("north, south");

  SetSearch( ([
    ({ "walls", "wall" })  :  "The walls around you have already been cleared "
       "of anything that is valuable.",
  ]) );

  SetItems( ([
    ({ "chasm", "large chasm" })  :  (: GetLong :),
    ({ "ropes", "two ropes", "rope" })  :
       "Two ropes cross the narrowest portion of the chasm here.  It appears "
       "that somebody is attempting to make a bridge so that the other side of "
       "the chasm is open for exploration.",
    ({ "small encampment", "encampment" })  :
       "On the other side of the chasm there is a small encampment with all "
       "of the tools and materials one would need to build a bridge.",
    ({ "tools", "tool", "materials", "material", "things" })  :
       "There are tools of all sorts and materials of all kinds, lying across "
       "the chasm.  All of the things appear to be oriented towards building "
       "a bridge.",
    ({ "bridge" })  :
       "The bridge hasn't been finished yet!",
    ({ "walls", "wall" })  :
       "In the dim light the walls sparkle from the various gems and metal to"
       "be found embedded within the walls.",
    ({ "below", "down" })  :
       "As you look down over the ledge you see the light that enters being "
       "swallowed by the darkness of the depths below you.",
    ({ "ledge" })  :
       "You are standing of a ledge that mirrors the path of the cavern.  It "
       "continues on to the north and south and out of sight into the darker "
       "areas of the chasm cavern.",
    ({ "darkness" })  :
       "It is very... dark.",
    ({ "gems", "gem", "metals", "metal", "various metals", "various gems" })  :
       "The various metals wind their way across the walls to create random "
       "patterns.  The various gems sparkle silently in the faint light here.",
  ]) );

  SetInventory( ([ NPCS + "/brbuilder" : 1, ]) );
}
