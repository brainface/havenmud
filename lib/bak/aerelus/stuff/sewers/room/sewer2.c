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
    "The sewer system continues down a slight slope here, with the majority "
    "of waste flowing from the south. There are, however, a few bronze pipes "
    "which connect the more respectable residences, along with most of the "
    "public buildings, to the filthy stream in the center of the tunnel. "
    "The stone walkways which line the stream are slightly cleaner here, as "
    "someone has attempted to clean them recently. On one side of the stream, "
    "there is a sleeping mat and a pillow, suggesting that this part of the "
    "sewer is home to someone who would prefer to remain out of public "
    "vision."    
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
  ({ "residences", "buildings" }) : "The waste from most of the residences, "
    "and other public buildings, makes it's way here through bronze piping.",
  ({ "stream", "center" }) : "The stream of waste flows in the center of the "
    "tunnel, surrounded by stone walkways.",
  ({ "walkways" }) : "The stone walkways lie on either side of the stream, "
    "providing access to city workers, should the need arise. One of the "
    "walkways has been cleaned recently, and is home to a sleeping mat and "
    "pillow.",
  ({ "mat" }) : "A fabric sleeping mat lies on one of the walkways, with an "
    "old feather pillow at the head.",
  ({ "pillow" }) : "An old feather pillow lies at the head of a fabric "
    "sleeping mat on one of the walkways.",
  ({ "slope" }) : "A shallow slope directs the stream downwards, further into "
    "the sewers.",    
  ]) );
  SetItemAdjectives( ([
    "system" : ({ "sewer" }),
    "piping" : ({ "bronze" }),
    "pipes" : ({ "bronze" }),
    "pillow" : ({ "old", "feather" }),
    "mat" : ({ "fabric", "sleeping" }),
    "slope" : ({ "shallow", "slight" }),
    "residences" : ({ "respectable" }),
    "buildings" : ({ "publiv" }),
    "stream" : ({ "filthy" }),
    "walkways" : ({ "stone" }),    
  ]) );
  SetInventory( ([
    SEWERS_NPC "rat" : 1,
    SEWERS_NPC "rogue_leader" : 1,
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
    "south" : SEWERS_ROOM "sewer1",
    "down" : SEWERS_ROOM "sewer3",
  ]) );  
}
