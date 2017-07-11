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
  SetShort("a residential area off The Emerald Way");
  SetLong(
    "The bustle of city life lessens here through this quiet residential "
    "area. The ground here is covered in neatly-trimmed grass with an aged "
    "stone path leading through the residential area. At the side of the "
    "path there is a small house with a well-kept garden, surrounded by a "
    "short obsidian fence."    
  );
  SetItems( ([
   "cemetery" : "There is a cemetery here.",
  ({ "area" }) : (: GetLong :),
  ({ "ground", "grass" }) : 
    "The ground is covered in grass, which has been kept neatly trimmed, "
    "showing that the residents take great pride in the appearance of their "
    "property.",
  ({ "path" }) : 
    "This aged path leads through the residential area, and eventully back "
    "to The Emerald Way.",
  ({ "house" }) : 
    "This house seems smaller than the others, but unlike the others, it has "
    "a garden.",
  ({ "fence" }) :
    "The obsidian fence surrounds the garden and house.",    
  ]) );
  SetItemAdjectives( ([
    "area" : ({ "residential" }),
    "grass" : ({ "neatly-trimmed" }),
    "path" : ({ "aged", "stone" }),
    "house" : ({ "small" }),
    "garden" : ({ "well-kept" }),
    "fence" : ({ "obsidian" }),
  ]) );
  SetInventory( ([    
  ]) );
  SetListen( ([
    "default" : "The residential area is quiet, though the sounds of city "
      "life drift in from the far east.",
  ]) );
  SetSmell( ([
    "default" : "The refreshing mountain air is pleasant.",
  ]) );
  SetExits( ([    
    "east" : DAL_ROOM "road8",      
  ]) ); 
  SetEnters( ([
    "house" : DAL_ROOM "house2",
    "cemetery" : DAL_ROOM "cemetery",
  ]) );
}
