/*  A tunnel in the eastern road, for mining trainer  */
// Mahkefel 2010

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort ("a tunnel excavated into the ruins");
  SetClimate("underground");

  SetAmbientLight(30);
  SetExits( ([
    "out"  : ROOM "/ruins5a",
  ]) );

  SetLong(
    "A small tunnel has been excavated into the ruins here. Rough debris "
    "has been removed, revealing a shattered tile fresco on what was once "
    "the road. Thick lumber beams keep the remains of the wall from "
    "collapsing in on the excavation. A glowing orb hangs from a beam on "
    "the ceiling. The dim glow "
    "of the city illuminates the mouth of the tunnel."
  );

  SetItems( ([
    ({ "tunnel" }) :
       (: GetLong :),
    ({ "ground" }) :
       "Fine marble dust litters the shattered tiles that cover the ground.",
    ({ "marble", "dust", "stone" }) :
       "Incessant digging has reduced the marble debris of the crumbled wall "
       "to a fine dust.",
    ({ "orb" }) :
       "The orb glows faintly with magic.",
    ({ "shards", "runes", "shard", "rune" }):
       "Some of the runes still glow with a dim blue light.",
    ({ "lumber", "beams", "beam", "ceiling" }) :
       "Thick oaken beams hold several tons of rock at bay.",
    ({ "wall", "debris" }):
       "The ruined wall collapsed here, burying the street under tons of stone.",
    ({ "tile", "fresco" }):
       "The graceful lines of the fresco are damaged and indescipherable.",
    ({ "road" }):
       "This tunnel evidently lies along a buried road.",
    ({ "glow", "city" }) :
       "The city outside, even in its ruined state, glows brighter than the "
       "meager illumination of the tunnel."
  ]) );

  SetItemAdjectives( ([
    "wall" : ({"fallen", "rough"}),
    "tunnel" : ({"small"}),
    "fresco" : ({"shattered", "tile"}),
    "beams" : ({"thick", "lumber"}),
    "orb" : ({"glowing"}),
    "shards" : ({"intact"}),
  ]) );

  SetListen( ([
    "default"  : "A hissing sound comes from outside."
  ]) );

   SetInventory( ([
      NPC "/miner" : 1,
      OBJ "/shelf" : 1,
   ]) );

   SetSpecialMineral(OBJ "/marble_chunk" );
}
