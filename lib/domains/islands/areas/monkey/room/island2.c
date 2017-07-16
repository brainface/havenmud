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
    "foliage blocking all directions other than east and west, where the "
    "jungle seems less thick. There is a tall, solitary rock here that "
    "provides enough shade during the daytime to allow the cultivation of a "
    "small patch of mushrooms. Beetles and other insects crawl around the "
    "ground here, searching for food."    
  );
  SetItems( ([
  ({ "jungle" }) : (: GetLong :),
  ({ "trees", "foliage" }) : 
    "Palm trees and other foliage make passage through this jungle very "
    "difficult.",
  ({ "rock" }) : 
    "This tall rock provides a little shade, allowing a patch of mushrooms "
    "to grow nearby.",    
  ({ "mushrooms", "patch" }) : 
    "Most of the mushrooms have been nibbled on by the birds and other island "
    "creatures.",
  ({ "beatles", "insects", "beetle" }) : 
    "Beetles and other insects quickly crawl around here by the rock.",
  ]) );
  SetItemAdjectives( ([
    "trees" : ({ "palm" }),
    "bay" : ({ "sandy" }),
    "rock" : ({ "tall", "solitary" }),
    "foliage" : ({ "island" }),
    "patch" : ({ "small" }),
  ]) );
  SetInventory( ([
    ISLAND_NPC "monkey" : 2,
    ISLAND_OBJ "mushroom" : 2,    
  ]) );
  SetListen( ([
    "default" : "Pleasant birdsong can be heard from the treetops.",
  ]) );
  SetSmell( ([
    "default" : "The air here is very warm and humid.",
  ]) );
  SetExits( ([
    "east" : ISLAND_ROOM "island3",
    "west" : ISLAND_ROOM "island1",    
  ]) );  
}
