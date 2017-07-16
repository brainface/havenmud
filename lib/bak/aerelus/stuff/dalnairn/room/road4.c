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
    "There is a small, unimportant-looking building here that houses the "
    "city's postal service. Steam rises through a chimney on a larger building "
    "which appears to be a forge."
  );
  SetNightLong(
    "The Emerald Way, so named due to the emerald lamp casings on the tall "
    "lampposts that line the road, leads north and south through Dalnairn. "
    "At this time of day, the entire area takes on a dark green hue, courtesy "
    "of the emerald lamps. There is a small, unimportant-looking building "
    "here that houses the city's postal service. Steam rises through a "
    "chimney on a larger building which appears to be a forge."
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
  ({ "office", "building" }) : 
    "This building appears to be the local post office.",
  ({ "forge", "building" }) : 
    "Steam rises from the chimney of this building. It is a forge, where one "
    "could presumably buy weapons and armour.",  
  ]) );
  SetItemAdjectives( ([
    "casings" : ({ "emerald", "lamp" }),
    "lampposts" : ({ "tall" }),
    "patterns" : ({ "brilliant" }),
    "light" : ({ "green" }),
    "office" : ({ "post" }),
  ]) );
  SetInventory( ([
    DAL_NPC "citizen" : 1,   
  ]) );
  SetListen( ([
    "default" : "The loud crash of a hammer beating against steel comes from "
      "the forge.",
  ]) );
  SetSmell( ([
    "default" : "The smell of burning coal fills the air.",
  ]) );
  SetExits( ([    
    "north" : DAL_ROOM "road5",
    "south" : DAL_ROOM "road2",
  ]) ); 
  SetEnters( ([
    "forge" : DAL_ROOM "forge",
    "office" : DAL_ROOM "office",
  ]) );
}
