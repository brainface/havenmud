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
  SetShort("the outer bailey of Targoviste");
  SetLong(
    "To the east stands an arched doorway, opening in to "
    "a building which stretches to the southeast. A sign "
    "above the door seems to indicate what services can "
    "be found here. Formed of bricks of black stone this "
    "edifice has large iron rings set in to its walls just "
    "north of the open doorway. Thick chains lead from these "
    "rings, up the inner wall of the fortress and in to a "
    "gatehouse set atop the battlements. To the north lies "
    "the main gates of the inner keep, while the outer bailey "
    "continues to the south."
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
    "default" : "A low rumble of sound comes from the east.",
  ]) );
  SetSmell( ([
    "default" : "Moisture thickens the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "west_wall3",
    "south" : TARG_ROOM "west_wall1",
    "east" : TARG_ROOM "shop1",
  ]) );
}
