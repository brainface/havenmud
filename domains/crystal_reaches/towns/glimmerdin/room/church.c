#include <lib.h>
#include <vendor_types.h>
#include "../path.h"

inherit LIB_CHAPEL;

static void create() {
	chapel::create();
	SetClimate("indoors");
	SetAmbientLight(55);
  SetShort("the Grand Cathedral of Kylin");
  SetLong(
    "The inside of the Cathedral of Kylin is nearly as impressive "
    "as the exterior.  High, vaulted ceilings fade away into the "
    "darkness, and the shadows seem to engulf the ceiling which is "
    "completely hidden from the ground.  Ornately carved pews line "
    "the sanctuary, their massive stone girth and worn seating "
    "shining from a high polish. Stained glass images line the walls, "
    "set in stone recesses built to look like windows.  Behind each "
    "glass is a glowing globe of light, making the Cathedral have a "
    "brilliant multi colored tint."
    );
  SetTown("Glimmerdin");
  SetProperty("no teleport",1);
  SetProperty("no conjuring",1);
  SetItems( ([
	 ({ "ceiling", "ceilings" }) :
	     "The ceiling is lost in the heights above the floor.",
	 ({ "pew", "pews" }) :
	     "The pews are ornately carved stone that are polished to a "
	     "very high gloss.  The actual seating is smoothly worn from "
	     "ages of dwarven supplicants.",
	 ({ "image", "glass", "window", "windows" }) :
	     "The stained glass images depict the dwarven saints and the "
	     "history of the Kylin religion in Glimmerdin. They are made of "
	     "stained glass and have a glowing globe of light behind them, "
	     "giving the room a multi-colored tint of brilliant light.",
	  ]) );
	SetItemAdjectives( ([
	  "ceiling" : ({ "high", "vaulted", }),
	  "pew"     : ({ "stone", "polished", "ornately", "carved", "ornate", 
	                 "massive", "stone", }),
	  "image"   : ({ "stained", "glass", }),
	  ]) );
  SetExits( ([
    "out" : G_ROOM "gh_north",
    ]) );
  SetSmell( ([
    "default" : "A faint scent of incense hangs in the cathedral.",
    ]) );
  SetListen( ([
    "default" : "A whisper of faint prayers echoes into the heights.",
    ]) );
  SetReligion("Kylin");
  SetInventory( ([
    G_NPC + "torun" : 1,
    G_NPC + "healer" : 1,
    G_NPC + "trainer" : 1,
    ]) );
}
      
