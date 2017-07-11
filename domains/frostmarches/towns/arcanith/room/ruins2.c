/* Wall road */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("inside the gate");
  SetClimate("temperate");
  
  SetNightLight(30);
  SetExits( ([
    "north"  : ROOM "/ruins4",
    "west"   : ROOM "/ruins3",
    "east"   : ROOM "/ruins5",
    "south"  : ROOM "/ruins1",
  ]) );

  SetDayLong("The destruction of the ruins is obvious inside the wall.  "
             "Weeds grow between the stones of the road.  Buildings crumble "
             "into rubble.  A road follows around the inside of the wall.  "
             "The second road leads deeper into the ruins.  The crossroad "
             "is bathed in the silver light of the wall.");

  SetNightLong("Eerie shadows dance among the decaying buildings.  The "
               "silver light from the wall illuminates the crossroad.  One "
               "road leads along the wall and is bathed in its light.  The "
               "second leads deeper into the ruins.  Both are being overrun "
               "by weeds.");

  SetItems( ([
    ({ "road around the inside of the wall", "road around the wall",
       "road following along the wall", "road along the wall", "road" })  :
       "This road follows along the wall that surrounds the city.  The road "
       "is bathed in its light.  Heavy weeds stick out from between the "
       "stones of the road.",
    ({ "road leading deeper into the ruins", "road into the ruins", 
       "road leading into the ruins", "road" })   :
       "The road leads deeper into the ruins and away from the walls.  "
       "The road is being broken by heavy weeds.",
    ({ "wall around the ruins", "glowing walls", "glowing wall", "walls", 
       "wall" })  :
       "The wall surrounds the ruins and radiates a silver light.  The "
       "glowing wall is covered in runes and is made of white marble.",
    ({ "silver light", "silver glow", "glow", "light" })   :
       "The wall around the ruins glows with a silver light.  The silver "
       "glow is strongest around the runes.",
    ({ "white marble", "marble" })  :
       "The walls are made of white marble flecked with gold.",
    ({ "tiny flecks of gold", "tiny fleck of gold", "flecks of gold",
       "flecks", "gold", "fleck of gold", "fleck", "tiny flecks", 
       "tiny fleck" })  :
       "The marble is dotted with tiny flecks of gold.",
    ({ "spidery silver runes", "spider silver rune", "silver runes",
       "silver rune", "runes", "rune" })   :
       "Spidery silver runes cover the city wall.  They glow with a silver "
       "light.",
    ({ "decayed buidings", "decayed building", "buildings", "building",
       "ruins", "ruin" })   :
       "The decayed buildings slowly crumble into rubble.  The ruins are "
       "filled with similar buildings.",
    ({ "crossroads" })  :
       "Two roads intersect here.  One leads around the wall, the second "
       "leads deeper into the ruins.",
    ({ "heavy weeds", "heavy weed", "large weeds", "large weed", "weeds",
       "weed" })  :
       "Large weeds strive to survive in the ruins.  They line the "
       "buildings and break the roads in the ruins.",
  ]) );

  SetSmell( ([
    "default"  : "The smells of dust and wildflowers fill the air.",
  ]) );

  SetListen( ([
    "default"  : "The occasional falling rock breaks the silence of the "
                 "ruins.",
  ]) );

  SetInventory( ([
    NPC "/koboldm"  : 2
  ]) );

}
