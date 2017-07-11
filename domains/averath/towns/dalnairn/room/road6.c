// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("The Emerald Way");
  SetDayLong(
    "The Emerald Way, so named due to the emerald lamp casings on the tall "
    "lampposts that line the road, leads north and south through Dalnairn. "
    "During the day, the sunlight shines through the lamp casings, casting "
    "brilliant patterns of green light on the road and surrounding buildings. "
    "To the east of the road stands the Dalnairn Library, a modest building "
    "that appears to receive little attention from the dark-dwarf population."
  );
  SetNightLong(
    "The Emerald Way, so named due to the emerald lamp casings on the tall "
    "lampposts that line the road, leads north and south through Dalnairn. "
    "At this time of day, the entire area takes on a dark green hue, courtesy "
    "of the emerald lamps. To the east of the road stands the Dalnairn "
    "Library, a modest building that appears to receive little attention from "
    "the dark-dwarf population."
  );
  SetItems( ([
  ({ "casings" }) :
    "The emerald lamp casings cause the light from the lamps to appear green, "
    "illuminating the entire area.",
  ({ "lampposts" }) : 
    "These tall lampposts provide a source of light to the area.",
  ({ "dalnairn", "city" }) : 
  	"The city of Dalnairn, home of the Duergar, is a beautiful place, almost "
    "entirely created from obsidian.",
  ({ "patterns", "light" }) : 
    "During the day, the sun casts patterns of green light through the "
    "emerald lamp casings. At night, the entire area takes on a green hue.",
  ({ "library", "building" }) : 
    "The library serves as a place for the inhabitant Duergar to learn about "
    "other cultures as well as how to increase their magical abilities. "
    "However, since most of the people here are more interested in making "
    "money, it receives little interest.",    
  ]) );
  SetItemAdjectives( ([
    "casings" : ({ "emerald", "lamp" }),
    "lampposts" : ({ "tall" }),
    "patterns" : ({ "brilliant" }),
    "light" : ({ "green" }),    
    "library" : ({ "dalnairn" }),
    "building" : ({ "modest" }),
  ]) );
  SetInventory( ([    
  ]) );
  SetListen( ([
    "default" : "The sounds of city life are all around.",
  ]) );
  SetSmell( ([
    "default" : "The refreshing mountain air is pleasant.",
  ]) );
  SetExits( ([    
    "north" : DAL_ROOM "road2",
    "south" : DAL_ROOM "road7",
  ]) ); 
  SetEnters( ([
    "library" : DAL_ROOM "library",
  ]) );
}
