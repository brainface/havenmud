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
    "The fine white sand of the beach continues to the southeast while "
    "to the south it is more alive with the tides of the bay. The cliff arms of the "
    "ridge abruptly prevent travel to the north while the crescent forest "
    "takes its place to the east. Further southeast, the makings of a town "
    "break the tranquility of sand.",
  );
  SetItems( ([
    ({ "arms", "arm", "mountain", "ridge", "cliff" }) : 
      "The mountain ridge is highest to the southeast. The "
      "arms of the ridge cascade out, encircling the waters of the bay.",
    ({ "bay", "water", "waters", "sunlight", "moonlight", 
       "expanse", "wave", "wave" }) : 
      "The calm, clear waters of the bay lap gently back and forth "
      "across the expanse allowed by the ridge arms. Waves break gently "
      "on the beach to the south.",
    ({ "sand" }) : 
      "The fine white sand shimmers softly in the light.",
    ({ "sea" }) : 
      "The sea lies to the west passed the mouth of the bay.",
    ({ "town", "beach" }) : 
      "A town sits nestled on the beach, ringed by a forest and a mountain ridge.",
    ({ "forest" }) : 
      "A crescent shaped forest grows between the beach and the mountain ridge.",
    ({ "mouth", "mouth of the bay" }) :
      "The two ridge arms encircling the bay come closest together at the mouth "
      "of the bay which lies to the southwest, leading out to the sea.",
    ({ "pier" }) :
      "A wooden pier juts out of a beach town to the southeast.",
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
    DAL_NPC "turtle" : 2 + random(2) + random(2),
  ]) );
  SetListen( ([
    "default" : "Waves break gently on the beach.",
  ]) );
  SetSmell( ([
    "default" : "The beach air smells of salt and life.",
  ]) );
  SetExits( ([
    "east" : DAL_ROOM "1,4.c",
    "southeast" : DAL_ROOM "1,3.c", 
    "south" : DAL_ROOM "0,3.c",
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
