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
    "Below the city, this network of tunnels acts as a sewer system for "
    "Averath. Bronze piping connects the more respectable residences, "
    "along with most of the public buildings, to the filthy stream in "
    "the center of the tunnel. Stone walkways lie on either side, providing "
    "access to workers and other, less innocent people. Both the stream and "
    "the walkways lead north further into the sewer system. A rusty ladder "
    "on the southern wall leads up to a heavy iron grate, which seems big "
    "enough to enter."    
  );
  SetItems( ([
  ({ "sewer", "system", "tunnel" }) : (: GetLong :),
  ({ "city", "averath" }) : "Since not many have the stomach to handle the "
    "smell of the sewer system, this part of the city seems under disrepair.",
  ({ "network", "tunnels", "tunnel" }) : "The network of tunnels that make up "
    "the sewer system seem like they were built a long time ago.",
  ({ "piping" }) : "Bronze piping, while far from elegant, does an adequate "
    "job of directing the waste from the city to the stream in the center of "
    "the tunnel.",
  ({ "residences", "buildings" }) : "The waste from most of the residences, "
    "and other public buildings, makes it's way here through bronze piping.",
  ({ "stream", "center" }) : "The stream of waste flows in the center of the "
    "tunnel, surrounded by stone walkways.",
  ({ "walkways" }) : "The stone walkways lie on either side of the stream, "
    "providing access to city workers, should the need arise.",
  ({ "ladder" }) : "A rusty ladder, fixed to the southern wall, provides "
    "a way out of the sewer through a heavy iron grate located above.",
  ({ "wall" }) : "There is a ladder fixed to the southern wall.",
  ({ "grate" }) : "The heavy iron grate leads up to the city.",  
  ]) );
  SetItemAdjectives( ([
    "system" : ({ "sewer" }),
    "piping" : ({ "bronze" }),
    "residences" : ({ "respectable" }),
    "buildings" : ({ "publiv" }),
    "stream" : ({ "filthy" }),
    "walkways" : ({ "stone" }),
    "ladder" : ({ "rusty" }),
    "wall" : ({ "southern" }),
    "grate" : ({ "heavy", "iron" }),    
  ]) );
  SetInventory( ([
    SEWERS_NPC "rat" : 3,    
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
    "north" : SEWERS_ROOM "sewer2",
  ]) );
  SetEnters( ([
    "grate" : SEWERS_DIR "../newaverath/room/road3",
  ]) );
}
