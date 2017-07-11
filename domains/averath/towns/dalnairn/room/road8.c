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
  SetShort("a residential area off Emerald Way");
  SetLong(
    "The bustle of city life lessens here through this quiet residential "
    "area. The ground here is covered in neatly-trimmed grass with an aged "
    "stone path leading through the residential area. To one side of the "
    "path there is a large, newly built house with a tall, solitary birch "
    "tree growing just outside."
  );
  SetItems( ([
  ({ "area" }) : (: GetLong :),
  ({ "ground", "grass" }) : 
    "The ground is covered in grass, which has been kept neatly trimmed, "
    "showing that the residents take great pride in the appearance of their "
    "property.",
  ({ "path" }) : 
    "This aged path leads through the residential area, and eventully back "
    "to The Emerald Way.",
  ({ "house" }) : 
    "This large house appears to be a new construction. It looks rather "
    "extravogent.",
  ({ "tree" }) : 
    "Towering above the path, this tree stands alone, creating some shade "
    "by the house.",  
  ]) );
  SetItemAdjectives( ([
    "area" : ({ "residential" }),
    "grass" : ({ "neatly-trimmed" }),
    "path" : ({ "aged", "stone" }),
    "house" : ({ "large", "extravogent" }),
    "tree" : ({ "solitary", "birch" }),    
  ]) );
  SetInventory( ([
    DAL_NPC "citizen" : 2,  
  ]) );
  SetListen( ([
    "default" : "The residential area is quiet, though the sounds of city "
      "life drift in from the east.",
  ]) );
  SetSmell( ([
    "default" : "The refreshing mountain air is pleasant.",
  ]) );
  SetExits( ([    
    "east" : DAL_ROOM "road7",
    "west" : DAL_ROOM "road9",
  ]) ); 
  SetEnters( ([
    "house" : DAL_ROOM "house1",
  ]) );
}
