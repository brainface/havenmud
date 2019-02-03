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
  SetProperty("coastal", 1);
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
  SetShort("a wooden pier on the bay");
  SetLong(
    "Deep wooden beams elevate and support the wooden pier "
    "above the bay waters. The planks of the pier are windswept "
    "with fine white sand. Over the edge of the pier the bottom "
    "of the bay is clearly visible. A town sits atop a boardwalk "
    "to the east surrounded by sand and ringed with a crescent "
    "forest and mountain ridge. ",
  );
  SetItems( ([
    ({ "beam", "beams" }) : 
       "Wooden beams have been driven deep into the bay to support "
	   "the pier.",
    ({ "arms", "arm", "mountain", "ridge", "cliff" }) : 
      "The mountain ridge is highest to the east. The "
      "arms of the ridge cascade out, encircling the waters of the bay.",
    ({ "water", "waters", "sunlight", "moonlight", 
       "expanse", "wave", "wave", "edge" }) : 
      "The calm, clear waters of the bay lap gently back and forth "
      "across the expanse allowed by the ridge arms. Waves break gently "
      "on the beach to the east.",
    ({ "sand", "beach", "bottom" }) : 
      "The fine white sand shimmers softly in the light.",
    ({ "sea" }) : 
      "The sea lies to the west passed the mouth of the bay.",
    ({ "town", "boardwalk" }) : 
      "The town sits upon en elevated wooden boardwalk.",
    ({ "forest" }) : 
      "A crescent shaped forest grows between the beach and the mountain ridge.",
    ({ "mouth", "mouth of the bay" }) :
      "The two ridge arms encircling the bay come closest together at the mouth "
      "of the bay which lies to the west, leading out to the sea.",
    ({ "pier", "plank", "planks", "rope", "post", "posts" }) :
      "The pier juts out into the bay allowing ships to dock. It is made of "
	  "wooden planks and supported by deep wooden beams. A fibrous rope dangles "
	  "between posts around the perimeter of the pier leaving the west end open.",
  ]) );
  SetItemAdjectives( ([
    "boardwalk" : ({ "elevated", "wooden" }),
    "beam" : ({ "wooden", "deep" }),
    "arms" : ({ "crescent", "shaped", "mountain", "ridge", "rock", "outermost", "cliff" }),
    "bay" : ({ "clear", "water", "sunlight", "moonlight", "calm", "over" }),
    "sand" : ({ "fine", "white" }),
    "sea" : ({ "" }),
    "town" : ({ "beach" }),
    "beach" : ({ "" }),
    "forest" : ({ "crescent", "shaped" }),
    "pier" : ({ "wooden", "wood", "fibrous" }),
  ]) );  
  SetInventory( ([
    DAL_NPC "cage_vendor" : 1,
    DAL_NPC "priest_damhair" : 1,
    DAL_VEH "yacht" : 1,
    DAL_OBJ "bay_dive" : 1,
    DAL_NPC "rogue" : 1,
    DAL_NPC "seagull" : 1 + random(2) + random(2),
    DAL_OBJ "warning_sign" : 1,  ]) );
  SetListen( ([
    "default" : "The water laps softly at the beams of the pier.",
  ]) );
  SetSmell( ([
    "default" : "The bay air smells of salt and life.",
  ]) );
  SetExits( ([
    "northwest" : DAL_ROOM "0,1.c",
    "north" : DAL_ROOM "1,1.c",
    "east" : DAL_ROOM "2,0.c",
    "south" : DAL_ROOM "1,-1.c",
    "southwest" : DAL_ROOM "0,-1.c",
    "west" : DAL_ROOM "0,0.c",
  ]) ); 
  SetEnters( ([
  ]) );
}


void heart_beat() {
  string wave;
  ::heart_beat();
  switch(random(6)) {
    case 0:
      wave = "%^CYAN%^The water laps softly at the beams of the pier.%^RESET%^";
    break;
    case 1:
      wave = "%^CYAN%^The water laps softly at the beams of the pier.%^RESET%^";
    break;
    case 2:
      wave = "%^CYAN%^The water laps softly at the beams of the pier.%^RESET%^";
    break;
    case 3:
      wave = "%^CYAN%^Water laps back and forth against the wooden beams "
	         "supporting the pier.%^RESET%^";
    break;
    case 4:
      wave = "%^CYAN%^Water laps back and forth against the wooden beams "
	         "supporting the pier.%^RESET%^";
    break;
    case 5:
      wave = "%^CYAN%^The water rushes forward between the beams beneath the pier!%^RESET%^";
    break;
    }
  eventPrint(wave);
  }
