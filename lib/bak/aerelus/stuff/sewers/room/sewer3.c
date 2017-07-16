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
    "The sewer system continues north and south from here. Most of the the "
    "waste here flows down a slope in the tunnels to reach this part of the "
    "sewer, however the same bronze piping as in other parts of the sewer "
    "connects some of the remaining buildings in Averath to the system. The "
    "walkways to the north have decayed beyond repair, making passage in that "
    "direction impossible."    
  );
  SetItems( ([
  ({ "sewer", "system", "tunnel" }) : (: GetLong :),
  ({ "city", "averath" }) : "Since not many have the stomach to handle the "
    "smell of the sewer system, this part of the city seems under disrepair.",
  ({ "network", "tunnels", "tunnel" }) : "The network of tunnels that make up "
    "the sewer system seem like they were built a long time ago.",
  ({ "pipes", "piping" }) : "Bronze piping, while far from elegant, does an "
    "adequate job of directing the waste from the city to the stream in the "
    "center of the tunnel.",
  ({ "buildings" }) : "The waste from most of the residences, "
    "and other public buildings, makes it's way here through bronze piping.",
  ({ "stream", "center" }) : "The stream of waste flows in the center of the "
    "tunnel, surrounded by stone walkways.",
  ({ "walkways" }) : "The stone walkways lie on either side of the stream, "
    "providing access to city workers, should the need arise. The walkways to "
    "the north have worn away and decayed, making passage in that direction "
    "impossible.",    
  ({ "slope" }) : "A shallow slope directs the stream down towards this part "
    "of the sewer system.",    
  ]) );
  SetItemAdjectives( ([
    "system" : ({ "sewer" }),
    "piping" : ({ "bronze" }),
    "pipes" : ({ "bronze" }),    
    "slope" : ({ "shallow", "slight" }),    
    "buildings" : ({ "publiv" }),
    "stream" : ({ "filthy" }),
    "walkways" : ({ "stone" }),    
  ]) );
  SetInventory( ([
    SEWERS_NPC "rat" : 4,
    SEWERS_NPC "bandit" : 1,
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
    "up" : SEWERS_ROOM "sewer2",
    "south" : SEWERS_ROOM "sewer4",
  ]) );  
}
