// Targoviste
// Laoise
// August 2004

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetDayLight(-20);
  SetTown("Targoviste");
  SetShort("within the outer bailey of Targoviste");
  SetLong(
    "Directly north is the arched entrance to a building "
    "formed of jet-colored stone. Above this doorway is a "
    "sign which appears to indicate the types of services "
    "offered within. Directly to the east of this entrance "
    "are several large iron rings which are bolted in to "
    "the structure. Chains run from these rings up to a "
    "gatehouse set in the battlements above. East of here "
    "the bailey continues, circling the inner keep. To the "
    "northwest is the main throughfare of Targoviste."
  );
  SetItems( ([ 
    "sign" : "A sign above the door displays the anvil "
    "of the smith, the suit of chainmail indicating an "
    "armourer and a basket filled with general merchandise.",


  ]));
  SetItemAdjectives( ([
    "sign" : ({ "building", "door", "above", "east" }),

  ]) );
  SetListen( ([ 
    "default" : "A low rumble of sound comes from the north.",
  ]) );
  SetSmell( ([
    "default" : "Mist tinges the air.",
  ]) );

  SetExits( ([ 
    "north" : TARG_ROOM "shop3",
    "east" : TARG_ROOM "south_wall5",
    "west" : TARG_ROOM "south_wall7",
  ]) );
}
