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
  SetShort("the northern end of The Emerald Way");
  SetDayLong(
    "The Emerald Way, so named due to the emerald lamp casings on the tall "
    "lampposts that line the road, leads north and south through Dalnairn. "
    "During the day, the sunlight shines through the lamp casings, casting "
    "brilliant patterns of green light on the road and surrounding buildings. "
    "A large obsidian fence to the north marks the end of the city bounds, "
    "while still allowing citizens to appreciate the stunning view from this "
    "altitude. The Bank of Dalnairn is here, and looks very official."
  );
  SetNightLong(
    "The Emerald Way, so named due to the emerald lamp casings on the tall "
    "lampposts that line the road, leads north and south through Dalnairn. "
    "At this time of day, the entire area takes on a dark green hue, courtesy "
    "of the emerald lamps. A large obsidian fence to the north marks the end "
    "of the city bounds, while still allowing citizens to appreciate the "
    "stunning view from this altitude. The Bank of Dalnairn is here, and "
    "looks very official."
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
  ({ "bank" }) : 
    "The bank of Dalnairn looks very official and important. Duergar enter "
    "and leave it frequently, showing the importance of money here.",  
  ]) );
  SetItemAdjectives( ([
    "casings" : ({ "emerald", "lamp" }),
    "lampposts" : ({ "tall" }),
    "patterns" : ({ "brilliant" }),
    "light" : ({ "green" }),    
    "bank" : ({ "official", "important" }),
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
    "south" : DAL_ROOM "road4",    
  ]) ); 
  SetEnters( ([
    "bank" : DAL_ROOM "bank",    
  ]) );
}
