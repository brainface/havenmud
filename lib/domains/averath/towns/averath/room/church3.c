// Aerelus
#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("in the Hall of the Brave");
  SetLong(
    "This part of the church has been allocated to the town guard, showing "
    "the close relationship between the guard and the church. It is here "
    "where the warriors of the city come to train and discuss military "
    "matters. Since relations between the city and the Duergar, a dwarf-like "
    "people who inhabit the mountain on the island, are always tense, there "
    "are a few wooden Duergar-like figurines placed throughout for weapons "
    "training."
  );
  SetItems( ([
    ({ "church", "hall" }) : (: GetLong :),
    ({ "figurines" }) : "These wooden figurines are made to look like average "
      "male Duergar. They are chipped and battered, after intense weapons "
      "training.",    	
  ]) );
  SetItemAdjectives( ([
    "figurines" : ({ "wooden", }),    
  ]) );
  SetInventory( ([
    AVERATH_NPC "guard" : 3,
    AVERATH_NPC "porthos" : 1,
    AVERATH_NPC "fighter_leader" : 1,
  ]) );
  SetListen( ([
     "default" : "Discussions relating to military operations can be heard.",
  ]) );
  SetSmell( ([
     "default" : "The hall smells strongly of sweat.",
  ]) );  
  SetExits( ([    
    "west" : AVERATH_ROOM "church",    
  ]) );    
}
