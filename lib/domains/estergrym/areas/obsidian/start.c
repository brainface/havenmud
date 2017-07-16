//--    Torak@Haven    --//
//-- Obsidian Apostles --//
//--      6/17/99      --//

#include <lib.h>
#include "obsidian.h"
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("a dark cave");
  SetClimate("indoors");
  SetDomain("Estergrym");
  SetLong("This dark cave rests hidden "
          "behind the waterfall.  "
          "The ceiling is high with piercing "
          "stalagtites ready to fall with "
          "the slightest echo.  The entire "
          "cave shimmers a blue hew with "
          "a rainbow of dark colors glimmering "
          "across the wall from the waterfall.  ");
  SetItems( ([
    ({ "cave", "wall" }) :
       (: GetLong :),
    ({ "waterfall" }) :
       "The waterfall just outside constantly "
       "assaults the lake with water, causing "
       "a large amount of storming noise to echo "
       "across the cave.",
    ({ "lake" }) :
       "The lake is just outside.",
    ({ "ceiling" }) :
       "The ceiling of the cave is very high and has "
       "stalagtites hanging from it.  On the northern "
       "end there seems to be a small opening.",
    ({ "stalagtite", "stalagtites" }) :
       "The stalagtites hang gothicly from the "
       "ceiling of the cave in a stoic silence "
       "warning everything of the dangers of "
       "loud noises.",
    ({ "rainbow", "colors", "color" }) :
       "With the waterfall right outside the cave, the colors "
       "glisten and shine across the walls of the cave in a "
       "burst of rainbows everywhere.",
    ({ "opening" }) :
       "The small opening is large enough to fit through.",
    ]) );
  SetExits( ([
    "out" : U_ROOM + "roomt",
    ]) );
  SetEnters( ([
    "opening" : OBSIDIAN + "main",
    ]) );
  }
