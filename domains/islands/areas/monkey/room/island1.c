// Island
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../island.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("in a dense jungle");
  SetLong(
    "Passage through this jungle is limited, with palm trees and other island "
    "foliage blocking most directions. There appears to be a path to the "
    "north, though it has been almost entirely overgrown with vines. The "
    "jungle extends east, while to the southeast there appears to be a sandy "
    "bay just past the trees."    
  );
  SetItems( ([
  ({ "jungle" }) : (: GetLong :),
  ({ "trees", "foliage" }) : 
    "Palm trees and other foliage make passage through this jungle very "
    "difficult.",
  ({ "path" }) : 
    "A path lies to the north, leading through the jungle. It seems almost "
    "completely overgrown with vines.",
  ({ "vines" }) : 
    "The thick green vines cover the path, making travel difficult.",
  ({ "bay" }) : 
    "The bay lies just past the trees to the southeast.",  
  ]) );
  SetItemAdjectives( ([
    "trees" : ({ "palm" }),
    "bay" : ({ "sandy" }),
    "vines" : ({ "thick", "green" }),
  ]) );
  SetInventory( ([
    ISLAND_NPC "monkey" : 1,    
    ISLAND_NPC "monkey2" : 1,    
  ]) );
  SetListen( ([
    "default" : "The sound of the ocean comes from the southeast.",
  ]) );
  SetSmell( ([
    "default" : "The air here is very warm and humid.",
  ]) );
  SetExits( ([
    "southeast" : ISLAND_ROOM "port",
    "east" : ISLAND_ROOM "island2",
    "north" : ISLAND_ROOM "path1",
  ]) );  
}
