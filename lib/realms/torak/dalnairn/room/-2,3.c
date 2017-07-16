#include <lib.h>
#include <domains.h>
#include <std.h>
#include <dirs.h>
#include "../dalnairn.h"

inherit LIB_FISHING;

static void create() {
  ::create();
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
  SetProperty("ocean", 1);
  SetClimate("sub-tropical");
  SetShort("a deep lagoon");
  SetDayLong(
    "Tucked inside an inlet of the northern ridge arm, "
    "the lagoon's blue water glistens with sunlight as it "
    "gently laps back and forth. "
    "From atop the ridge a waterfall flows over the "
    "cliff face pouring into the lagoon. "
    "The waters of the lagoon go down deep sinking into the abyss. "
    "The bay stretches out to the east where it meets the sandy beach.",
  );
  SetNightLong(
    "Tucked inside an inlet of the northern ridge arm, "
    "the lagoon's black water glistens with moonlight as it "
    "gently laps back and forth. "
    "From atop the ridge a waterfall flows over the "
    "cliff face pouring into the lagoon. "
    "The waters of the lagoon go down deep sinking into the abyss. "
    "The swash zone stretches out to the east where it meets the sandy beach.",
  );
  SetItems( ([
    ({ "waterfall", "floe", "surface", "falls" }) :
       "Falling from the northern ridge a waterfall "
       "pours down its drink into the lagoon where it "
       "splashes, plunging deep into the otherwise gentle surface.",
    ({ "down", "abyss", "light" }) :
       "The depths of the lagoon delve beyond where light can travel "
       "into the abyss.",
    ({ "wave", "waves", "distance" }) :
       "Incoming waves from the bay break in the distance coming "
       "closer to shore before they roll into the froth.",
    ({ "froth", "swash", "swash zone" }) :
       "The white frothy layer of water swashes back and forth "
       "across the sandy shore with the incoming breaking waves.",
    ({ "arms", "arm", "mountain", "ridge", "cliff", "cliff face", "face" }) : 
       "Nestled inside this inlet the mountain ridge blocks the view "
       "beyond it except for the natural exit to the east.",
    ({ "sunlight", "moonlight" }) : 
      "The water laps back and forth in the shimmering light.",
    ({ "sand", "beach", "shore" }) : 
       "The fine white sand is soaked through and glistens softly in the light.",
    ({ "forest", "exit", "east" }) : 
      "A forest grows between the beach and the mountain ridge to the east.",
    ({ "lagoon", "water", "waters", "inlet" }) : (: GetLong :),
  ]) );
  SetItemAdjectives( ([
    "wave" : ({ "incoming" }),
    "water" : ({ "blue", "black", }),
    "arms" : ({ "crescent", "shaped", "mountain", "ridge", 
                "southern", "rock", "outermost", "northern" }),
    "bay" : ({ "clear", "water", "sunlight", "moonlight", "calm" }),
    "beach" : ({ "sandy" }),
    "forest" : ({ "crescent", "shaped" }),
  ]) );
  SetInventory( ([
    DAL_VEH "krakn" : 1,
    DAL_NPC "kobold_captain" : 1,
    // lobsters, fish, crabs
  ]) );
  SetListen( ([
    "default" : "Water flows down from the falls splashing into the lagoon.",
  ]) );
  SetSmell( ([
    "default" : "The air is wet and full of life.",
  ]) );
  SetExits( ([
    "east" : DAL_ROOM "-1,3.c",
  ]) ); 
  SetEnters( ([
  ]) );
}

void heart_beat() {
  string wave;
  ::heart_beat();
  switch(random(4)) {
    case 0:
      wave = "%^CYAN%^Water flows down from the falls splashing into the lagoon.%^RESET%^";
    break;
    case 1:
      wave = "%^CYAN%^Water flows down from the falls splashing into the lagoon.%^RESET%^";
    break;
    case 2:
      wave = "%^CYAN%^Water flows down from the falls splashing into the lagoon.%^RESET%^";
    break;
    case 3:
      wave = "%^CYAN%^The soft churn of the waves echoes across the beach.%^";
    break;
    }
  eventPrint(wave);
  }
