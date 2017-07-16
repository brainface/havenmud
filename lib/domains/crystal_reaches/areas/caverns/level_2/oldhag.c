/*  An Old Hag's Room  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(50);
  SetShort("an old hag's room");

  SetLong("The twisting tunnel ends in a very unusual room.  It is perfectly "
          "square with the tunnel coming into the southwest corner of it.  "
          "All of the walls, including the floor and ceiling, are covered "
          "with intricate arcane symbols.  A pile of blankets in one corner "
          "make up a bed.  The rest of the room seems to be devoted to stone "
          "workbenches with glassware filled with bubbling liquids.  Books "
          "and sheets of paper are scattered where there is any room on the "
          "benches.");

  SetSmell( ([
    "default"  :  "The bubbling liquids give off such a terrible smell that "
                  "makes it hard to breath here.",
  ]) );

  SetListen( ([
    "default"  :  "You hear the bubbling of many various liquids.",
  ]) );

  SetExits( ([
    "southwest"  :  ROOMLV2 + "/cave2b.c",
  ]) );
  SetObviousExits("southwest");

  SetItems( ([
    ({ "room", "old hags room", "hags room" })  :  (: GetLong :),
    ({ "twisting tunnel", "tunnel" })  :
       "The twisting tunnel leads out of the southwestern corner, and the "
       "tunnel looks just as unusual as the room itself, as it is rectangular "
       "instead of a natural circular shape.",
    ({ "walls", "floor", "intricate arcane symbols", "intricate symbols",
       "intricate arcane symbol", "intricate symbol", "arcane symbols",
       "wall","arcane symbol", "symbols", "ceiling", "surfaces", "surface",
       "symbol" })  :
       "Every wall, including the ceiling and floor, are covered with many "
       "intricately carved arcane symbols.  There doesn't seem to be any "
       "pattern to the symbols, nor does it seem that any symbol carved "
       "more than once on any of the surfaces.",
    ({ "blankets", "blanket", "bed" })  :
       "In one corner, taking up as little space as possible, so that the "
       "workbenches can take up the rest of the room, are a few blankets.  "
       "These blankets are little more than rags and don't seem to provide "
       "much protection from the cold damp air of the caverns.",
    ({ "stone workbenches", "stone workbench", "stone benches", "stone bench",
       "workbenches", "workbench", "benches", "bench" })  :
       "Stone workbenches are all around the room covering as much floorspace "
       "as possible.  So that there is as much workspace as possible within "
       "the room.",
    ({ "glassware" })  :
       "The glassware is filled with liquids of all colors and types, most of "
       "which are bubbling, sizzling, and/or fizzing.",
    ({ "bubbling liquids", "bubbling liquid", "liquids", "liquid" })  :
       "Liquids of all colors and types are bubbling in the glassware.",
    ({ "books", "book", "paper", "papers" })  :
       "Books, and sheets of paper cover any space on the bench not taken up "
       "by the glassware with the bubbling liquids in it.",
  ]) );

  SetInventory( ([ NPCS + "/oldhag" : 1 ]) );
}
