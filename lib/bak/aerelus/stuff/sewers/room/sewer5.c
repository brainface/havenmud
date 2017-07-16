// Averath Sewers
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../sewers.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(35);
  SetClimate("indoors");
  SetShort("in the Averath sewer system");
  SetLong(
    "The sewer system continues north, east and west from here. However, the "
    "stream itself has been blocked to the east by rubble and some old "
    "clothes, forcing all of the waste to flow west. There is an old wooden "
    "torch fixed to the tunnel wall here, illuminating the surrounding area. "
    "What appears to be the remains of a makeshift fireplace lies just east "
    "of the blockage, though it looks like it hasn't been used in quite some "
    "time."
  );
  SetItems( ([
  ({ "sewer", "system", "tunnel" }) : (: GetLong :),  
  ({ "network", "tunnels", "tunnel" }) : "The network of tunnels that make up "
    "the sewer system seem like they were built a long time ago.",  
  ({ "stream", "center" }) : "The stream of waste flows in the center of the "
    "tunnel, surrounded by stone walkways. It appears to be blocked to the "
    "east",
  ({ "walkways" }) : "The stone walkways lie on either side of the stream, "
    "providing access to city workers, should the need arise. ",
  ({ "torch" }) : "The old wooden torch flickers, providing some light to the "
    "area.",
  ({ "wall" }) : "The stone wall of the tunnel is home to an old wooden "
    "torch.",
  ({ "fireplace" }) : "The fireplace looks like it hasn't been used in quite "
    "some time.",
  ({ "blockage", "rubble", "clothes", "clothing" }) : "Made up of rubble and "
    "old clothing, the purpose of the blockage appears to be to divert the "
    "stream to the west.",  
  ]) );
  SetItemAdjectives( ([
    "system" : ({ "sewer" }),    
    "stream" : ({ "filthy" }),
    "walkways" : ({ "stone" }),
    "torch" : ({ "old", "wooden" }),
    "wall" : ({ "stone" }),
    "fireplace" : ({ "makeshift" }),
    "clothes" : ({ "old" }),
    "clothing" : ({ "old" }),    
  ]) );
  SetInventory( ([    
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
    "north" : SEWERS_ROOM "sewer4",
    "west" : SEWERS_ROOM "sewer6",
    "east" : SEWERS_ROOM "sewer8",
  ]) );  
}