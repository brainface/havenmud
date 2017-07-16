//
// Dalnairn Total Recode
// Torak@Haven
// 2014-2017
//

#include <lib.h>
#include <domains.h>
#include <dirs.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-tropical");
  SetShort("a clearing in the forest");
  SetLong(
    "This clearing has been cut out of the otherwise "
    "densly packed forest and is used as a burial grounds. "
    "Various grave markings and mounds are scattered across the dirt. "
    "The beach opens out westerly while the forest continues northward "
    "clinging to the arm of the ridge. "
    "A trampled path cuts into the forest. "
  );
  SetItems( ([
    ({ "path" }) :
       "The path starts here and goes north into the forest running "
       "parallel to the mountain ridge.",
    ({ "clearing" }) :
       (: GetLong :),
    ({ "ground", "grounds" }) :
       "Surrounded by the forest and with a view of the beach, "
       "this clearing has been reserved for the burial of the dead. "
       "Various grave markings and mounds are scattered across the dirt. ",
    ({ "mound", "mounds" }) :
       "The mounds of the freshly buried protrude from the ground.",
    ({ "markings", "trinkets", "trinket" }) :
       "Various markings and trinkets have been left behind across the grounds.",
    ({ "arms", "arm", "mountain", "ridge" }) : 
      "The mountain ridge is highest to the northeast. The "
      "arms of the ridge cascade out, encircling the waters of the bay.",
    ({ "bay", "water", "waters", "sunlight", "moonlight", 
       "expanse", "wave", "wave" }) : 
      "The calm, clear waters of the bay lap gently back and forth "
      "across the expanse allowed by the ridge arms. Waves break gently "
      "on the beach to the west.",
    ({ "sand" }) : 
      "The fine white sand shimmers softly in the light.",
    ({ "sea" }) : 
      "The sea lies to the northwest passed the mouth of the bay.",
    ({ "town", "beach" }) : 
      "A town sits nestled on the beach, ringed by a forest and a mountain ridge.",
    ({ "forest" }) : 
      "A crescent shaped forest grows between the beach and the mountain ridge.",
    ({ "mouth", "mouth of the bay" }) :
      "The two ridge arms encircling the bay come closest together at the mouth "
      "of the bay which lies to the northwest, leading out to the sea.",
    ({ "pier" }) :
      "A wooden pier juts out of a beach town to the northeast.",
  ]) );
  SetItemAdjectives( ([
    "marking" : ({ "grave", "various" }),
    "path" : ({ "trampled" }),
    "clearing" : ({ "cut" }),
    "ground" : ({ "burial" }),
    "arms" : ({ "crescent", "shaped", "mountain", "ridge", "rock", "outermost", "cliff" }),
    "bay" : ({ "clear", "water", "sunlight", "moonlight", "calm" }),
    "sand" : ({ "fine", "white" }),
    "sea" : ({ "" }),
    "town" : ({ "beach" }),
    "beach" : ({ "" }),
    "forest" : ({ "crescent", "densly", "packed", "shaped" }),
    "pier" : ({ "wooden" }),
  ]) );  
  SetInventory( ([
    DAL_OBJ "grave1" : 1,
    DAL_OBJ "grave2" : 1,
  ]) );
  SetListen( ([
    "default" : "Branches creak as parakeets chatter in the distance.",
  ]) );
  SetSmell( ([
    "default" : "The air is thick and damp.",
  ]) );
  SetExits( ([
    "north" : DAL_ROOM "1,-3.c",
    "west" : DAL_ROOM "0,-4.c",
    "northeast" : DAL_ROOM "2,-3.c",
  ]) ); 
  SetEnters( ([
  ]) );
}
