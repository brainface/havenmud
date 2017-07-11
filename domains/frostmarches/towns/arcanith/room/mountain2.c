/*  A mountain trail leading to the ruins. */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("a trail up the mountain");
  SetClimate("arctic");
  
  SetExits(  ([
     "east"     : "/domains/frostmarches/areas/academy/room/clearing",
     "north"    : ROOM "/mountain3",
     "south"  : ROOM "/mountain1",
  ]) );

  SetDayLong(
             "The small path continues to wind up the mountain and "
             "veers off east in a trail through the trees.  Loose "
             "rocks are half buried in the snow along the path.  The "
             "trail is lined by pine trees which fill the air with their "
             "scent.  The plateau sits high above on the mountain.");

  SetNightLong("Darkness conceals the mountain path.  It is difficult "
               "to see in the darkness.  Small pine trees and large rocks "
               "stand silently in the darkness.  The only guidance on the "
               "trail is the light that comes from the plateau above.");

  SetItems( ([
    ({ "small trail", "trail", "path", "mountain path", "small path" })  :
       "This small trail snakes its way up the mountain and forks to "
       "the east through the trees.  Snow covers the "
       "mountain to the left and right of the path.",
    ({ "mountain" })   :
       "The mountain continues to rise higher into the air.  Loose stones "
       "and snow cover the mountain's surface.",
    ({ "loose stone", "loose stones", "rock", "rocks", "stones", "stone",
       "loose rock", "loose rocks" })  :
       "Loose stones lie along the mountain path.  The slightest pressure "
       "causes them to shift.",
    ({ "snow" })  :
       "A layer of pure white snow covers the trees and mountain.",
    ({ "small pine trees", "small pine tree", "pine tree", "pine trees",
       "tree", "trees" })  :
       "Pine trees line the mountain path.  Their green needles are covered "
       "in snow.",
    ({ "green needles", "green needle", "needle", "needles" })   :
       "The needles of the pine tree stay green throughout the seasons.",
    ({ "silver light", "light", "glow", "silver glow" })  :
       "Something on the plateau continues to radiate a silver light.",
    ({ "plateau" })  :
       "There is a plateau halfway up the mountain.  A silver glow shines "
       "from above it.",
  ]) );
  SetSmell( ([
    "default"  : "The smell of stone and dirt fill the air.  There is a "
                 "scent of pine in the air.",
  ]) );

  SetListen( ([
    "default"  : "The sound of loose stones sliding down the mountain "
                 "fills the air.",
  ]) );
  SetInventory( ([
    NPC "/mountain_goat" : 1,
  ]) );

}
