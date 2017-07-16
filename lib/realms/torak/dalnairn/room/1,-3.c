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
  SetShort("a sandy beach");
  SetLong(
    "The fine white sand of the beach continues to the northeast and "
    "southwest while to the north and west it is more alive with the tides of "
    "the bay. The beach ends further southwest where it meets the cliff "
    "arms of the ridge while a temple has been erected on the edge of the "
    "crescent forest to the east. "
    "A clearing has been cut out of the forest to the south. "
    "Further northeast, the makings of a town "
    "break the tranquility of sand. To the north across the water lies a pier.",
  );
  SetItems( ([
    ({ "temple" }) : "A polished stone temple lies to the east before "
       "the forest.",
    ({ "clearing" }) : 
       "The clearing cut out of the forest to the east is quiet. ",
    ({ "arms", "arm", "mountain", "ridge", "cliff" }) : 
      "The mountain ridge is highest to the northeast. The "
      "arms of the ridge cascade out, encircling the waters of the bay.",
    ({ "bay", "water", "waters", "sunlight", "moonlight", 
       "expanse", "wave", "wave" }) : 
      "The calm, clear waters of the bay lap gently back and forth "
      "across the expanse allowed by the ridge arms. Waves break gently "
      "on the beach to the north and west.",
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
      "A wooden pier juts out of the beach town to the north.",
  ]) );
  SetItemAdjectives( ([
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
    DAL_NPC "turtle" : 1 + random(2),
    DAL_NPC "seagull" : random(3),
  ]) );
  SetListen( ([
    "default" : "Waves break gently on the beach.",
  ]) );
  SetSmell( ([
    "default" : "The beach air smells of salt and life.",
  ]) );
  SetExits( ([
    "north" : DAL_ROOM "1,-2.c",
    "northeast" : DAL_ROOM "2,-2.c",
    "east" : DAL_ROOM "2,-3.c",
    "south" : DAL_ROOM "1,-4.c",
    "southwest" : DAL_ROOM "0,-4.c",
    "west" : DAL_ROOM "0,-3.c",
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
