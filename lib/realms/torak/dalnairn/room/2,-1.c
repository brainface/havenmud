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
  SetShort("a boardwalk over the beach");
  SetLong(
    "Deep wooden beams elevate the boardwalk from the beach. "
    "The planks of the boardwalk are windswept with fine white sand. "
    "A tavern has been erected here. "
    "The boardwalk stretches north further into town where a pier "
    "stretches into the bay. "
    "The beach is to the south while the town is ringed with a "
    "crescent forest and mountain ridge.",
  );
  SetItems( ([
    ({ "tavern", "building" }) :
       "A wooden tavern has been erected here on the boardwalk. ",
    ({ "beam", "beams" }) : 
       "Wooden beams have been driven deep into the sand to support "
	   "the boardwalk and the pier. ",
    ({ "arms", "arm", "mountain", "ridge", "cliff" }) : 
      "The mountain ridge is highest to the northeast. The "
      "arms of the ridge cascade out, encircling the waters of the bay.",
    ({ "bay", "water", "waters", "sunlight", "moonlight", 
       "expanse", "wave", "wave" }) : 
      "The calm, clear waters of the bay lap gently back and forth "
      "across the expanse allowed by the ridge arms. Waves break gently "
      "on the beach to the north and south.",
    ({ "sand", "beach" }) : 
      "The fine white sand shimmers softly in the light.",
    ({ "sea" }) : 
      "The sea lies to the northwest passed the mouth of the bay.",
    ({ "town", "boardwalk" }) : 
      "The town sits upon en elevated wooden boardwalk. A pier just out to the north.",
    ({ "forest" }) : 
      "A crescent shaped forest grows between the beach and the mountain ridge.",
    ({ "mouth", "mouth of the bay" }) :
      "The two ridge arms encircling the bay come closest together at the mouth "
      "of the bay which lies to the northwest, leading out to the sea.",
    ({ "pier" }) :
      "A wooden pier stretches out into the bay supporting by wooden beams.",
  ]) );
  SetItemAdjectives( ([
    "boardwalk" : ({ "elevated", "wooden" }),
    "beam" : ({ "wooden", "deep" }),
    "building" : ({ "soot", "covered", "sooty" }),
    "arms" : ({ "crescent", "shaped", "mountain", "ridge", "rock", "outermost", "cliff" }),
    "bay" : ({ "clear", "water", "sunlight", "moonlight", "calm" }),
    "sand" : ({ "fine", "white" }),
    "sea" : ({ "" }),
    "town" : ({ "beach" }),
    "beach" : ({ "" }),
    "forest" : ({ "crescent", "shaped" }),
    "pier" : ({ "wooden" }),
  ]) );  
  SetInventory( ([
    DAL_NPC "seagull" : 1 + random(2),
  ]) );
  SetListen( ([
    "default" : "Waves break gently on the beach.",
  ]) );
  SetSmell( ([
    "default" : "The air smells of salt, life and a rank mixture of alcohol.",
  ]) );
  SetExits( ([
    "north" : DAL_ROOM "2,0.c",
    "east" : DAL_ROOM "3,-1.c",
    "south" : DAL_ROOM "2,-2.c",
    "west" : DAL_ROOM "1,-1.c",
  ]) ); 
  SetEnters( ([
    "tavern" : DAL_BLD "tavern_01",
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
      wave = "%^CYAN%^Water laps back and forth against the wooden "
	         "beams supporting the pier.%^RESET%^";
    break;
    case 3:
      wave = "%^CYAN%^Water laps back and forth against the wooden "
	         "beams supporting the pier.%^RESET%^";
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
