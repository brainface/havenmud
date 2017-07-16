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
    "The fine white sand of the beach continues to the "
    "northwest while to the west it is more alive with the tides of "
    "the bay. The beach ends further northwest where it meets the cliff "
    "arms of the ridge  while the crescent forest takes its place to the "
	"north and east. "
    "South from here town takes shape, elevated above the sand on a "
	"boardwalk.",
  );
  SetItems( ([
    ({ "arms", "arm", "mountain", "ridge", "cliff" }) : 
      "The mountain ridge is highest to the southeast. The "
      "arms of the ridge cascade out, encircling the waters of the bay.",
    ({ "bay", "water", "waters", "sunlight", "moonlight", 
       "expanse", "wave", "wave" }) : 
      "The calm, clear waters of the bay lap gently back and forth "
      "across the expanse allowed by the ridge arms. Waves break gently "
      "on the beach to the west.",
    ({ "sand", "beach" }) : 
      "The fine white sand shimmers softly in the light.",
    ({ "sea" }) : 
      "The sea lies to the southwest passed the mouth of the bay.",
    ({ "town", "boardwalk" }) : 
      "A boardwalks run the course of town to the south with a pier jutting out.",
    ({ "forest" }) : 
      "A crescent shaped forest grows between the beach and the mountain ridge.",
    ({ "mouth", "mouth of the bay" }) :
      "The two ridge arms encircling the bay come closest together at the mouth "
      "of the bay which lies to the southwest, leading out to the sea.",
    ({ "pier" }) :
      "A wooden pier juts out of the beach town to the south.",
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
  ]) );
  SetListen( ([
    "default" : "Waves break gently on the beach.",
  ]) );
  SetSmell( ([
    "default" : "The beach air smells of salt and life.",
  ]) );
  SetExits( ([
    "north" : DAL_ROOM "2,3.c",
    "northwest" : DAL_ROOM "1,3.c",
    "east" : DAL_ROOM "3,2.c",
    "south" : DAL_ROOM "2,1.c",
    "west" : DAL_ROOM "1,2.c",
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
