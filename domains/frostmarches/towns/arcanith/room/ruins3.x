/*  The western path  */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("road along western wall");
  SetClimate("temperate");
  
  SetNightLight(30);
  SetExits( ([
    "east"   : ROOM "/ruins2",
    "west"   : ROOM "/ruins3a",
  ]) );

  SetDayLong("This road continues along the western part of the wall.  The "
             "remains of a building lie to the north.  The wall radiates a "
             "silver glow.");

  SetNightLong("The road is illuminated by the glow of the wall.  The "
               "remains of a building lie in the shadows to the north.  "
               "Light from the wall illuminates the road.");

  SetItems( ([
    ({ "broken road", "cracks in the road", "crack in the road", "cracks",
       "crack", "road" })  :
       "The road follows along the wall of the ruins.  The road is broken "
       "cracked by weeds.",
    ({ "remains of a building", "remain of a building", "remains", "remain",
       "buildings", "building", "shadowy building", "shadowy buildings" })  :
       "The remains of a building lie to the north.  The building slowly "
       "decays into rubble.",
    ({ "pile of rubble", "rubble", "pile" })  :
       "A pile of rubble is all that is remains of a building.",
    ({ "glowing wall", "glowing walls", "western part of the wall", 
       "western wall", "walls", "wall" })  :
       "A glowing wall illuminates the road.  It is covered in silver "
       "runes and is made of white marble.",
    ({ "spidery silver runes", "spider silver rune", "silver runes",
       "silver rune", "runes", "rune", "runes on the wall", 
       "rune on the wall" })  :
       "Spidery silver runes cover the city wall.  They glow with a silver "
       "light.",
    ({ "white marble", "marble" })  :
       "The walls are made of white marble flecked with gold.",
    ({ "tiny flecks of gold", "tiny fleck of gold", "flecks of gold",
       "flecks", "gold", "fleck of gold", "fleck", "tiny flecks", 
       "tiny fleck" })  :
       "The marble is dotted with tiny flecks of gold.",
    ({ "soft glow", "silver light", "light", "silver glow", "glow" })  :
       "A soft glow radiates from the runes on the wall.",
    ({ "heavy weeds", "heavy weed", "weeds", "weed" })   :
       "Heavy weeds wind their way through the cracks in the road.",
  ]) );

  SetSmell( ([
    "default"  :  "The smells of death and decay hangs about this area.",
  ]) );

  SetListen( ([
    "default"  :  "The area is strangely quiet.",
  ]) );

  SetInventory( ([
    NPC "/giant_snake" : 1,
  ]) );
}
