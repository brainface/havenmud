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
    "The sewer system continues north and south from here. Small pieces of "
    "trash line the stone walkways here, suggesting that the area is well "
    "travelled. Some of the blocks from the tunnel have been removed here, "
    "and placed into the sewage stream, allowing people to hop easilly from "
    "one side of the walkway to the other."
  );
  SetItems( ([
  ({ "sewer", "system", "tunnel" }) : (: GetLong :),  
  ({ "network", "tunnels", "tunnel" }) : "The network of tunnels that make up "
    "the sewer system seem like they were built a long time ago.",  
  ({ "stream", "center" }) : "The stream of waste flows in the center of the "
    "tunnel, surrounded by stone walkways.",
  ({ "walkways" }) : "The stone walkways lie on either side of the stream, "
    "providing access to city workers, should the need arise. There are small "
    "pieces of trash on the walkways here.",  
  ({ "trash" }) : "The pieces of trash, mostly empty bottles and fruit peel, "
    "line the stone walkways here.",
  ({ "blocks" }) : "Some of the tunnel blocks have been removed. They now "
    "rest in the filthy stream, allowing people to hop from one side of the "
    "walkway to the other.",
  ]) );
  SetItemAdjectives( ([
    "system" : ({ "sewer" }),    
    "stream" : ({ "filthy" }),
    "walkways" : ({ "stone" }),
    "trash" : ({ "small", "pieces", "of" }),
    "blocks" : ({ "tunnel" }),    
  ]) );
  SetInventory( ([    
    SEWERS_NPC "bandit" : 3,
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
    "south" : SEWERS_ROOM "sewer5",
    "north" : SEWERS_ROOM "sewer3",
  ]) );  
}