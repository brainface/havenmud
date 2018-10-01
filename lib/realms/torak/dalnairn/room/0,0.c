//
// Dalnairn Total Recode
// Torak@Haven
// 2014-2017
//

#include <lib.h>
#include <std.h>
#include <domains.h>
#include <dirs.h>
#include "../dalnairn.h"

inherit LIB_FISHING;

static void create() {
  ::create();
  SetProperty("ocean", 1);
  SetSpeed(5);
  SetFish(( [ 
      DIR_STD "fish/guppy" : 50,
      DIR_STD "fish/mackerel" : 20,
      DIR_STD "fish/seabass" : 20,
      DIR_STD "fish/yellowtail" : 10,
      DIR_STD "fish/swordfish" : 5,
      DIR_STD "shark" : 1,
  ]));
  SetChance(25);
  SetMaxFishing(25);
  SetClimate("sub-tropical");
  SetShort("a calm bay");
  SetDayLong(
    "Ringed by the arms of a crescent shaped mountain ridge, "
    "the bay's clear water glistens with sunlight as it gently "
    "laps back and forth. The bottom of the bay is clearly visible, "
    "made of a fine white sand. "
    "The ridge opens out west to the sea while to the east "
    "the bay expands and a town sits nestled on a beach. A crescent "
    "forest separates the beach town from the rock ridge behind it. "
    "The outermost arms of the ridge lie to the west "
    "from here forming the mouth of the bay. ",
  );
  SetNightLong(
    "Ringed by the arms of a crescent shaped mountain ridge, "
    "the bay's clear water shimmers with moonlight as it gently "
    "laps back and forth. The bottom of the bay is clearly visible, "
    "made of a fine white sand. "
    "The ridge opens out west to the sea while to the east "
    "the bay expands and a town sits nestled on a beach. A crescent "
    "forest separates the beach town from the rock ridge behind it. "
    "The outermost arms of the ridge lie to the west "
    "from here forming the mouth of the bay. ",
  );
  SetItems( ([
    ({ "arms", "arm", "mountain", "ridge" }) : 
      "The mountain ridge is highest to the east where a town "
      "sits nestled between a forest and a beach. The "
      "arms of the ridge cascade out, encircling the waters of the bay.",
    ({ "bay", "water", "waters", "sunlight", "moonlight", "expanse" }) : 
      "The calm, clear waters of the bay lap gently back and forth "
      "across the expanse allowed by the ridge arms.",
    ({ "bottom", "sand" }) : 
      "The fine white sand shimmers softly in the light.",
    ({ "sea" }) : 
      "The sea lies to the west passed the mouth of the bay.",
    ({ "town", "beach" }) : 
      "A town sits nestled on a beach, ringed by a forest and a mountain ridge.",
    ({ "forest" }) : 
      "A crescent shaped forest grows between the beach and the mountain ridge.",
    ({ "mouth", "mouth of the bay" }) :
      "The two ridge arms encircling the bay come closest together at the mouth "
      "of the bay which lies to the west, leading out to the sea.",
  ]) );
  SetItemAdjectives( ([
    "arms" : ({ "crescent", "shaped", "mountain", "ridge", "rock", "outermost" }),
    "bay" : ({ "clear", "water", "sunlight", "moonlight", "calm" }),
    "bottom" : ({ "clearly", "visible", "fine", "white" }),
    "sea" : ({ "" }),
    "town" : ({ "beach" }),
    "beach" : ({ "" }),
    "forest" : ({ "crescent", "shaped" }),
  ]) );
  
  if(query_night()) {
    SetInventory( ([
      // add glowing rocks for the seafloor bed (cant pick up)
      ]) );
    } else {
    SetInventory( ([
      // add dark rocks for the seafloor bed (cant pick up)
    ]) );
  }
  SetListen( ([
    "default" : "Waves splash softly across the surface of the bay.",
  ]) );
  SetSmell( ([
    "default" : "The bay air smells of salt and life.",
  ]) );
  SetExits( ([
    "northwest" : DAL_ROOM "-1,1.c",
    "north" : DAL_ROOM "0,1.c",
    "northeast" : DAL_ROOM "1,1.c",
    "east" : DAL_ROOM "1,0.c",
    "southeast" : DAL_ROOM "1,-1.c",
    "south" : DAL_ROOM "0,-1.c",
    "southwest" : DAL_ROOM "-1,-1.c",
    "west" : DAL_ROOM "-1,0.c",
  ]) ); 
  SetEnters( ([
  ]) );
}
