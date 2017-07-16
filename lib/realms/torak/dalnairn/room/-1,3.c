#include <lib.h>
#include <domains.h>
#include <std.h>
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
    DAL_NPC "lobster" : random(3),
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
      // lobsters, fish, crabs
    ]) );
	SetListen( ([
      "default" : "Waves splash softly across the surface of the bay.",
    ]) );
  }
  SetClimate("sub-tropical");
  SetDayLong(
    "Stradling the northern arm of the mountain ridge the bay's clear "
    "water glistens with sunlight as it gently laps back and forth. "
    "The bottom of the bay is clearly visible, made of a fine white sand. "
    "The inlet deepens to the west into a lagoon. "
    "There is a beach east of here. ",
  );
  SetNightLong(
    "Stradling the northern arm of the mountain ridge the swash zone "
    "of the beach is where the turbulant layer of water washes up on "
    "the beach after an incoming wave has broken. "
    "The inlet deepens to the west into a lagoon. "
    "The swash zone continous east from here. ",
  );
  SetItems( ([
    ({ "inlet", "lagoon" }) :
       "The clear waters of the bay have made a permanent home "
       "of the deeper waters to the west forming a lagoon.",
    ({ "swash", "zone", "swash zone" }) : (: GetLong :),
    ({ "wave", "waves", "distance" }) :
       "Incoming waves from the bay break in the distance coming "
       "closer to shore before they roll into the froth.",
    ({ "froth" }) :
       "The white frothy layer of water swashes back and forth "
       "across the sandy shore with the incoming breaking waves.",
    ({ "arms", "arm", "mountain", "ridge" }) : 
      "The mountain ridge is highest to the southeast where a town "
      "sits nestled between a forest and a beach. The "
      "arms of the ridge cascade out, encircling the waters of the bay.",
    ({ "bay", "sunlight", "moonlight", "expanse", "water" }) : 
      "The calm, clear waters of the bay lap gently back and forth "
      "across the expanse allowed by the ridge arms.",
    ({ "sand", "beach", "shore" }) : 
       "The fine white sand is soaked through and glistens softly in the light.",
    ({ "bottom" }) :
       "The fine white sand shimmers softly in the light around a rock formation.",
    ({ "sea" }) : 
      "The sea lies to the southwest passed the mouth of the bay.",
    ({ "town" }) : 
      "A town sits nestled on a beach, ringed by a forest and a mountain ridge.",
    ({ "forest" }) : 
      "A crescent shaped forest grows between the beach and the mountain ridge.",
    ({ "mouth", "mouth of the bay" }) :
      "The two ridge arms encircling the bay come closest together at the mouth "
      "of the bay which lies to the southwest, leading out to the sea.",
  ]) );
  SetItemAdjectives( ([
    "wave" : ({ "incoming" }),
    "water" : ({ "frothy", }),
    "arms" : ({ "crescent", "shaped", "mountain", "ridge", 
                "southern", "rock", "outermost" }),
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
    "east" : DAL_ROOM "0,3.c",
    "west" : DAL_ROOM "-2,3.c",
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
