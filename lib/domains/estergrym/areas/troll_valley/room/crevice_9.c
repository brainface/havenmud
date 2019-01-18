/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;


static void create()
{
  room::create();
  SetClimate("temperate");
  SetShort("a broad hollow");
  SetLong("The walls of the canyon widen into a nearly round hollow before "
          "splitting into a series of smaller, less navigable cracks.  "
          "The entire area has been cleared of the rocks and debris found "
          "elsewhere in the canyons and a few piles of skins are placed "
          "near walls.");
  SetItems( ([({"broad hollow","round hollow","hollow","crevice","canyon"}) :
                (string)GetLong(),
              ({"mountains","lower mountains"}) :
                "High above and all around, the mountains surround the crevice.",
              ({"unclimbable walls","high walls","walls","wall","basalt walls"}) :
                "Basalt walls reach into the sky at a near vertical angle.",
              ({"basalt","stone","rock","dark rock"}) :
                "The dark rock of the lower mountains is among the hardest "
                "that can be found anywhere in the world.",
              ({"rocks and debris","rocks","debris","rock"}) :
                "They have all been cleared from here, but some can be "
                "seen furter down the canyon.",
              ({"less navigable cracks","navigable cracks","cracks",}) : 
                "Not one of the cracks is large enough to enter.",
              ({"piles of skins","piles","skins","skin piles","beds",
                "pile of skins","pile","skin","skin pile","bed"}) : 
                "Although rotting, the skins appear to have been piled "
                "into beds for some creature to sleep on.",
              ({"hole"}) : 
                "The hole is quite dark and extends for some distance.",
          ]) );
  SetSearch( ([
               ({"piles of skins","piles","skins","skin piles","beds",
                "pile of skins","pile","skin","skin pile","bed"}) : 
                "Behind one of the piles, a hole leads into darkness.",
           ]) );
  SetListen( ([
    "default" : "The wind whistles through a hole in the canyon."
  ]) );
  SetInventory( ([
		VALLEY_NPC + "/big_troll" : 1,
		VALLEY_NPC + "/fat_troll" : 1,
              ]) );
  SetExits( ([
    "north" : VALLEY_ROOM + "/crevice_8",
            ]) );
  SetEnters( ([
		"hole" : VALLEY_ROOM + "/hole",
           ]) );
}
