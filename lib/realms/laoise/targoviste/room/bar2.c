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
  SetClimate("indoors");
  SetAmbientLight(30);
  SetTown("Targoviste");
  SetShort("the Heart's Blood tavern");
  SetLong(
    "The north and east walls of the tavern meet here, "
    "forming a right angle. A counter runs between the two "
    "walls, stools lined up before it. Behind the counter "
    "a shelf is bolted in to the wall, holding an array of "
    "bottles. Above the bottles is a set of hooks which hold "
    "a row of beer steins. Scattered throughout the room "
    "are tables with groupings of chairs around them. Against "
    "the southwest wall is a fireplace that appears to provide "
    "warmth for the tavern."
  );
  SetItems( ([ 
    "counter" : "This counter is formed of dark wood. Near "
    "the edge there is a small lip, appearing intended to keep "
    "any liquids from spilling over. Along the bottom of the "
    "counter, a hand span from the floor, runs a metal rod. It "
    "appears intended as a place for patrons to rest their "
    "feet while seated at the counter.",


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A rumble of voices fills the tavern.",
  ]) );
  SetSmell( ([
    "default" : "The scent of cooking fills the room.",
  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "bar1",
    "west" : TARG_ROOM "bar3",

  ]) );
}
