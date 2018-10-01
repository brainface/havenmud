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
  SetShort("the inner keep of Targoviste");
  SetLong(
    "Several buildings are nearby to this area, within the "
    "keep of Targoviste. The building to the north has a "
    "plaque with a balanced set of scale above its door. "
    "It is built of the same black stone as the rest of the "
    "city and is set flush against the wall of the keep. "
    "A second building sits to the northwest, extending off "
    "to the west, running the length of the north wall of "
    "the keep. Decorating a plaque over the door is the emblem "
    "of an open book with a globe of fire hovering above its "
    "pages. A short distance to the south stands a small building "
    "whose small size and lack of fortifications suggest it is "
    "a place of business."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Sounds of activity can be heard on all sides.",
  ]) );
  SetSmell( ([
    "default" : "The scent of cooking wafts in from the northeast.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "town_hall",
    "south" : TARG_ROOM "east_inner3",
    "east" : TARG_ROOM "keep_e",
    "northwest" : TARG_ROOM "library5",
  ]) );
}
