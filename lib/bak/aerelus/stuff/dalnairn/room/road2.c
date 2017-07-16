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
  SetShort("Intersection of Obsidian Road and Emerald Way");
  SetLong(
    "Here in the middle of Dalnairn the two main roads meet at a "
    "crossroads. In the center stands a tall, stunning fountain carved "
    "entirely from obsidian. This place seems to be the focal point of day "
    "to day social interactions between the duergar inhabitants, with stone "
    "benches placed around the area. The Obsidian Road leads east and west "
    "through the city, while The Emerald Way extends north and south."
  );
  SetItems( ([
  ({ "roads" }) :
    "The Obsidian Road leads east and west, while The Emerald Way extends "
    "north and south through the city.",
  ({ "city", "dalnairn" }) : 
    "The city of Dalnairn, home of the Duergar, is a beautiful place, almost "
    "entirely created from obsidian.",  
  ({ "benches" }) : 
    "The stone benches are placed around the fountain, providing a place for "
    "the Duergar to relax and socialize.",        
  ({ "crossroads" }) : (: GetLong :),
  ({ "obsidian", "mineraloid" }) : 
    "Obsidian is present almost everywhere here, in the buildings and the "
    "road itself.",  
  ]) );
  SetItemAdjectives( ([
    "roads" : ({ "main" }),    
    "benches" : ({ "stone" }),    
  ]) );
  SetInventory( ([
    DAL_OBJ "fountain" : 1,
    DAL_NPC "citizen" : 3,
  ]) );
  SetListen( ([
    "default" : "The sounds of city life are all around.",
  ]) );
  SetSmell( ([
    "default" : "The refreshing mountain air is pleasant.",
  ]) );
  SetExits( ([    
    "east" : DAL_ROOM "road1",
    "west" : DAL_ROOM "road3",
    "north" : DAL_ROOM "road4",
    "south" : DAL_ROOM "road6",
  ]) );  
}
