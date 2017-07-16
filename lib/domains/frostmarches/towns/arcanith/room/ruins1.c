/* The ruined gate of arcanith */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

int CheckPC(string dir);
 
static void create() {
  room::create();
  SetShort ("the ruined gate");
  SetClimate("temperate");
  SetNightLight(30);
  SetExits( ([
    "north"  : ROOM "/ruins2",
  ]) );
  AddExit("south", ROOM "/plateau1", (: CheckPC :) );
  SetDayLong("The remains of a tall, marble wall surround the ruins.  "
             "At one time this wall could have repelled the largest "
             "invasion, now it can't even defend the ruins from the wind.  "
             "The remains of the gate barely hang on their hinges.  Arching "
             "over the decaying gate is sign declaring the name of this "
             "once grand city.  The sign is written in Archaic, it says: "
             "Arcanith - Valgar dos Dalith.");

  SetNightLong("The wall around the ruins glows with a bright, silver "
               "radiance.  The wall is in disrepair.  At one time the wall "
               "could have easily repelled an invasion.  The gate of the city "
               "barely hang on their hinges.  A large arching sign declares "
               "the name of the city to all newcommers: Arcanith - Valgar "
               "dos Dalith.");

  SetItems( ([
    ({ "arcanith", "ruins", "city", "dalith", })  :
       "This once grand city lies decaying upon this mountain plateau.  Its "
       "empty delapidated buildings look like decayed skulls.  The city "
       "rises up the mountain.  It appears that the city was build on "
       "different tiers up the mountain.",
    ({ "building", "buildings", }) :
       "The delapidated buildings look like decayed skullls.",
    ({ "walls", "wall", })  :
       "The wall around the ruins is made of a white marble with flecks of "
       "gold.  Spidery runes are etched into the walls.  The wall glows "
       "with a bright silver light.",
    ({ "marble", "gold", }) :
       "The wall around the ruins is made of a white marble.  There are "
       "small flecks of gold embedded in the marble.",
    ({ "magic", "runes", "rune" })   :
       "The glow from the walls seems brightest around the runes.  The runes "
       "are written in the spidery script of magic.  Each rune is inlayed "
       "with silver.",
    ({ "light", "glow", })  :
       "The ruins are illuminated by a bright silver light that comes from "
       "the wall.  The glow from the walls seems brightest around the runes.",
    ({ "sign" })  :
       "The sign above the gate is a arch of white marble.  The words of the "
       "sign glow golden and declare the name of the city in Archaic.  "
       "The name of the city is: Arcanith - Valgar dos Dalith.",
    ({ "gates", "gate", "doors", "door" })  :
       "The large double doors guarding the ruins were once plated with "
       "silver, yet vandals have defaced the gates reveiling the wood "
       "underneath.  The hinges on the right door are the only ones still "
       "attached.  The left door leans on the right, forming a large gap "
       "between them.  There is enough room to enter the ruins.",
    ({ "hinge", "hinges",  })  :
       "The hinges that support the gates are very old and rusted.  "
       "The hinges on the right door are the only ones still  attached.  "
       "The left door leans on the right, forming a large gap between them.",
    ({ "right door" })    :
       "The right door still hangs on its hinges.",
    ({ "left door" })     :
       "The left door lies across the gate.",
    ({ "silver" })   :
       "The runes on the wall have been filled with silver.",
    ({ "wood" })    :
       "The gate is made of wood and silver.",
  ]) );

  SetItemAdjectives( ([
    "arcanith"  : ({ "valgar", "dos", "grand", }),
    "building"  : ({ "empty", "delapidated", }),
    "walls"     : ({ "tall", "marble", }),
    "marble"    : ({ "white", "flecks", "of", "with", "small", "marble", }),
    "magic"     : ({ "spidery", "script", "of", "magic", }),
    "light"     : ({ "bright", "silver", }),
    "gates"     : ({ "large", "double", }),
    "hinge"     : ({ "rusted", }),
     ]) );
  
  SetSmell( ([
    "default"  : "The air smells of decay an dust.  A breath of spring "
                 "blows from the city inside.",
  ]) );

  SetListen( ([
    "default"  : "The creaking hinges are the only sound to be heard.",
  ]) );

}


int CheckPC(string dir) {
   if(this_player()->id("arcanith_wander")) return 0;
   return 1;
}
