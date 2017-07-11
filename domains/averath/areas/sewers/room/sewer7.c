// Averath Sewers
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../sewers.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("in the Averath sewer system");
  SetLong(
    "Passage through the tunnel ends here at a large iron grate. It seems too "
    "small to squeeze through, stopping anyone from entering or leaving to "
    "the west. The walls are covered in patches of moss which strive here "
    "in the damp environment, aided by a small amount of light which comes "
    "from the west, where the sewer eventually meets the sea. The only way "
    "through the sewer system is east."    
  );
  SetItems( ([
  ({ "sewer", "system", "tunnel", "area" }) : (: GetLong :),  
  ({ "network", "tunnels", "tunnel" }) : "The network of tunnels that make up "
    "the sewer system seem like they were built a long time ago.",  
  ({ "stream", "center" }) : "The stream of waste flows in the center of the "
    "tunnel, surrounded by stone walkways.",
  ({ "walkways" }) : "The stone walkways lie on either side of the stream, "
    "providing access to city workers, should the need arise. ",
  ({ "moss", "patches" }) : "The small patches of moss thrive down here in "
    "the damp atmosphere.",
  ({ "walls" }) : "The tunnel walls are home to various patches of moss.",
  ({ "sea" }) : "Eventually, the sewer curves north where it meets with the "
    "sea. ",
  ]) );
  SetItemAdjectives( ([
    "system" : ({ "sewer" }),    
    "stream" : ({ "filthy" }),
    "walkways" : ({ "stone" }),
    "moss" : ({ "small", "patches", "of" }),
    "walls" : ({ "tunnel" }),  
  ]) );
  SetInventory( ([    
    SEWERS_NPC "rat" : 9,
    SEWERS_NPC "ratlady" : 1,
  ]) );
  SetListen( ([
    "default" : "The stream makes a trickling sound as it flows through the "
      "sewer.",
  ]) );
  SetSmell( ([
    "default" : "The sewer smells horrible.",
    "stream" : "You gag as you inhale the disgusting warm air above the "
    "stream.",
  ]) );
  SetExits( ([      
    "east" : SEWERS_ROOM "sewer6",
  ]) );  
}
