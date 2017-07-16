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
  SetShort("before a large obsidian church on The Emerald Way");
  SetDayLong(
    "The Emerald Way, so named due to the emerald lamp casings on the tall "
    "lampposts that line the road, leads north and south through Dalnairn. "
    "During the day, the sunlight shines through the lamp casings, casting "
    "brilliant patterns of green light on the road and surrounding buildings. "
    "Directly to the south lies the Soirin Church, a stunning building "
    "by the even the standards of the most accomplished architects. To the "
    "west, the road curves, leading to a residential area."    
  );
  SetNightLong(
    "The Emerald Way, so named due to the emerald lamp casings on the tall "
    "lampposts that line the road, leads north and south through Dalnairn. "
    "At this time of day, the entire area takes on a dark green hue, courtesy "
    "of the emerald lamps. Directly to the south lies the Soirin Church, "
    "a stunning building by even the standards of the most accomplished "
    "architects. To the west, the road curves, leading to a residential area."
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
  ({ "church" }) : 
  	"This stunning building is clearly well looked after. It is the Soirin "
  	"Church, where the Duergar go to pay respects, often in the form of "
  	"financial donation, to their deity.",
  ({ "area" }) : 
    "To the west lies a quiet residential area, where most of the citizens "
    "live.",  
  ]) );
  SetItemAdjectives( ([
    "casings" : ({ "emerald", "lamp" }),
    "lampposts" : ({ "tall" }),
    "patterns" : ({ "brilliant" }),
    "light" : ({ "green" }),
    "office" : ({ "post" }),
    "library" : ({ "dalnairn" }),
    "building" : ({ "modest" }),
    "area" : ({ "residential" }),
  ]) );
  SetInventory( ([    
  ]) );
  SetListen( ([
    "default" : "Soft chanting can be heard from the church.",
  ]) );
  SetSmell( ([
    "default" : "The refreshing mountain air is pleasant.",
  ]) );
  SetExits( ([    
    "north" : DAL_ROOM "road6",
    "west" : DAL_ROOM "road8",   
  ]) ); 
  SetEnters( ([
    "church" : DAL_ROOM "church",
  ]) );
}
