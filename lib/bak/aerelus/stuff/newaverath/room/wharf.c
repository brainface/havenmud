#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_FISHING;
int CheckPC();

static void create() {
  fishing::create();
  SetAmbientLight(30);
  SetClimate("temperate");  
  SetShort("the Wharf at Averath");
  SetDayLong(
    "Sunlight shines down upon the majestic city of Averath, capital of the "
    "nation of the same name. To the north, the Southern Sea spreads out "
    "into the horizon. Off to the south, the road leads towards the center "
    "of town. The wharf leads out into the bay, a safe place to dock ships "
    "of all sizes. A large warehouse sits along the dock, home to the "
    "shipping industry."
  ); 
  SetNightLong(
    "Starlight sparkles down upon the majestic city of Averath, capital of "
    "the nation of the same name. To the north, the Southern Sea spreads "
    "out into the horizon. Off to the south, the road leads towards the "
    "center of town. The wharf leads out into the bay, a safe place to dock "
    "ships of all sizes. A large warehouse sits along the dock, home to the "
    "shipping industry."
  );
  SetItems( ([
    "warehouse" : "The warehouse is the center of the shipping trade.",
  ]) );
  SetInventory( ([
   // AVERATH_OBJ "ferry" : 1,
    AVERATH_NPC "ferrycaptain" : 1,
  ]) );
  SetListen( ([
     "default" : "The bustle of business is in the air.",
  ]) );
  SetSmell( ([
     "default" : "The smell of the sea abounds here.",
  ]) );
  SetExits( ([
    "south" : AVERATH_ROOM "road1",
  ]) );
  AddExit("north", INNERSEA_VIRTUAL "ocean/0,-100", (: CheckPC :));
  SetEnters( ([
    "warehouse" : AVERATH_ROOM "warehouse",
  ]) );  
  
  SetProperty("coastal", 1);  
  SetNoClean(1);
  SetSpeed(5);
  SetChance(25);
  SetMaxFishing(12);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 10,
  ]) );
}  

int CheckPC() {
 if(this_player()->id("averath_wander")) return 0;
 return 1;
}