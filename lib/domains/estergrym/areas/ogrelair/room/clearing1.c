/* Ogre Lair, Estergrym
   Kairehn (17/01/2008) */

#include <lib.h>
#include "../ogrelair.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(30);
  SetShort("on a hilltop clearing");
  SetExits( ([  "west" : LAIR_ROOMS + "clearing2",
                "southeast" : LAIR_ROOMS + "path2",  ]) );
  SetSmell( ([ "default" : "There is a distinct smell of rotting flesh here.", ]) );
  SetListen( ([ "default" : "The surrounding trees rustle in the wind." ]) );
  SetLong("This small hill is entirely barren, save a large stone table upon "
          "the summit. A small path leads southeast to a patch of trees, while "
          "to the west there appears to be a cave opening. The entire area is "
          "covered by a light dusting of snow.");  
  SetItems( ([ 
    "hill" : "The hill is entirely barren, except for the presence "
             "of a large stone table upon the summit.", 
    "table" : "The table is covered with dried blood, suggesting "
              "that it is most likely used in some kind of sacrificial "
              "ritual.",
    "path" : "The small path leads southeast and west.",
    "snow" : "The snow here tends to lie only for a short time "
             "before melting.", 
  ]) );
  SetItemAdjectives( ([ 
    "hill" : "small",
    "table" : ({ "large", "stone" }),
    "path" : "small", 
  ]) );    
  SetInventory( ([    
    LAIR_NPC "weakogre" : 2,    
  ]) );                   
}
