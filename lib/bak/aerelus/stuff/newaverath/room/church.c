// Aerelus
#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("in the foyer of the Church of Aetarin");
  SetLong(
    "The Grand Church of Aetarin is a huge building. This area serves as the "
    "foyer, and leads to all other parts of the church. The main worship area "
    "lies south, where citizens are free to spend time praying to their God. "
    "To the east, the Hall of the Brave serves as a home to the city guard "
    "and other warriors native to Averath. Up a flight of stairs lies the "
    "home of the Duke, the ruler of Averath."
  );
  SetItems( ([
    ({ "church", "building", "area", "foyer" }) : (: GetLong :),    
  ]) );
  SetItemAdjectives( ([
    "church" : ({ "grand" }),
    "building" : ({ "huge" }),    
  ]) );
  SetInventory( ([
    AVERATH_NPC "citizen" : 1,    
    AVERATH_NPC "guard" : 1,
    AVERATH_NPC "equipper" : 1,
  ]) );
  SetListen( ([
     "default" : "Conversation seems to come from the south.",
  ]) );
  SetSmell( ([
     "default" : "The scent of the sea drifts in from the north.",
  ]) );  
  SetExits( ([    
    "south" : AVERATH_ROOM "church2",
    "east" : AVERATH_ROOM "church3",    
    "up" : AVERATH_ROOM "church4",
    "out" : AVERATH_ROOM "road2",
  ]) );    
}