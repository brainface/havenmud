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
    "The tunnel becomes slightly narrower here, compared to other parts of "
    "the sewer system. From the west, a small ammount of light partially "
    "illuminates the area, revealing small patches of moss on the tunnel "
    "walls. Passage through the sewer is possible to the east and west along "
    "the stone walkways that line the stream."    
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
  ]) );
  SetItemAdjectives( ([
    "system" : ({ "sewer" }),    
    "stream" : ({ "filthy" }),
    "walkways" : ({ "stone" }),
    "moss" : ({ "small", "patches", "of" }),
    "walls" : ({ "tunnel" }),  
  ]) );
  SetInventory( ([    
    SEWERS_NPC "rat" : 2,
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
    "west" : SEWERS_ROOM "sewer7",
    "east" : SEWERS_ROOM "sewer5",
  ]) );  
}