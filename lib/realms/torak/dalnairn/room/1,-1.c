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
  if(query_night()) {
    SetProperty("coastal", 1);
    SetShort("in the swash on the beach");
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
    SetInventory( ([
      DAL_NPC "moon_jelly" : random (6),
    DAL_NPC "lobster" : random(3),
      DAL_VEH "bouy" : 1,
      // fisherman, crabs, birds
    ]) );
    SetListen( ([
      "default" : "Waves break gently on the beach.",
    ]) );
  } else {
	SetProperty("ocean", 1);
    SetShort("a calm bay");
    SetSpeed(5);
    SetFish(( [ 
    ]));
    SetChance(25);
    SetMaxFishing(25);
    SetInventory( ([
      DAL_VEH "bouy" : 1,
      // lobsters, fish, crabs
    ]) );
	SetListen( ([
      "default" : "Waves splash softly across the surface of the bay.",
    ]) );
  }
  SetClimate("sub-tropical");
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
    "Ringed by the arms of a cresent shaped mountain ridge, "
    "the swash zone of the beach is where the turbulant layer of water "
    "washes up on the beach after an incoming wave has broken. "
    "The bay extends out to the west while the beach is to directly east. "
    "A forest seperates a town on the beach from the mountain ridge.",
  );
  SetItems( ([
    ({ "swash", "zone", "swash zone" }) : (: GetLong :),
	({ "wave", "waves", "distance" }) :
	   "Incoming waves from the bay break in the distance coming "
	   "closer to shore before they roll into the froth.",
	({ "water", "froth" }) :
	   "The white frothy layer of water swashes back and forth "
	   "across the sandy shore with the incoming breaking waves.",
    ({ "arms", "arm", "mountain", "ridge" }) : 
      "The mountain ridge is highest to the east where a town "
      "sits nestled between a forest and a beach. The "
      "arms of the ridge cascade out, encircling the waters of the bay.",
    ({ "bay", "sunlight", "moonlight", "expanse" }) : 
      "The calm, clear waters of the bay lap gently back and forth "
      "across the expanse allowed by the ridge arms.",
    ({ "sand", "beach", "shore" }) : 
       "The fine white sand is soaked through and glistens softly in the light.",
    ({ "bottom" }) :
	   "The fine white sand shimmers softly in the light.",
    ({ "sea" }) : 
      "The sea lies to the west passed the mouth of the bay.",
    ({ "town" }) : 
      "A town sits nestled on a beach, ringed by a forest and a mountain ridge.",
    ({ "forest" }) : 
      "A crescent shaped forest grows between the beach and the mountain ridge.",
    ({ "mouth", "mouth of the bay" }) :
      "The two ridge arms encircling the bay come closest together at the mouth "
      "of the bay which lies to the west, leading out to the sea.",
  ]) );
  SetItemAdjectives( ([
    "wave" : ({ "incoming" }),
    "water" : ({ "frothy", }),
    "arms" : ({ "crescent", "shaped", "mountain", "ridge", "rock", "outermost" }),
    "bay" : ({ "clear", "water", "sunlight", "moonlight", "calm" }),
    "bottom" : ({ "clearly", "visible", "fine", "white" }),
    "sea" : ({ "" }),
    "town" : ({ "beach" }),
    "beach" : ({ "sandy" }),
    "forest" : ({ "crescent", "shaped" }),
  ]) );
  SetSmell( ([
    "default" : "The bay air smells of salt and life.",
  ]) );
  SetExits( ([
    "northwest" : DAL_ROOM "0,0.c",
    "north" : DAL_ROOM "1,0.c",
    "east" : DAL_ROOM "2,-1.c",
    "south" : DAL_ROOM "1,-2.c",
    "southwest" : DAL_ROOM "0,-2.c",
    "west" : DAL_ROOM "0,-1.c",
  ]) ); 
  SetEnters( ([
  ]) );
}
 void heart_beat() {
  string wave;
  ::heart_beat();
  switch(random(6)) {
    case 0:
      wave = "%^CYAN%^Waves crash gently across the beach.%^RESET%^";
    break;
    case 1:
      wave = "%^CYAN%^Waves crash gently across the beach.%^RESET%^";
    break;
    case 2:
      wave = "%^CYAN%^Waves crash gently across the beach.%^RESET%^";
    break;
    case 3:
      wave = "%^CYAN%^The soft churn of the waves echoes across the beach.%^";
    break;
    case 4:
      wave = "%^CYAN%^The soft churn of the waves echoes across the beach.%^";
    break;
    case 5:
      wave = "%^CYAN%^A large wave breaks and crashes thunderously on the beach!%^RESET%^";
    break;
    }
  eventPrint(wave);
  }
