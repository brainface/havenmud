// Targoviste
// Laoise
// August 2004
// Enchanter Leader

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetTown("Targoviste");
  SetShort("the library of Targoviste");
  SetLong(
    "Sturdy bookshelves line all visible wall space, conforming to the "
    "corners and curves so that every possible open area is used. Most "
    "of the items neatly arranged on these shelves are books, but "
    "small trinkets appear to occasionally be interspersed. The solid "
    "stone of the floor is covered with a sumptuous rug the color of "
    "fresh blood. The library continues to the north and northwest, "
    "while to the southeast is a door leading outwards to the keep."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Faint crackles and snaps come from the north.",
  ]) );
  SetSmell( ([
    "default" : "The air is redolent with the scent of cinnamon.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "library4",
    "east" : TARG_ROOM "east_inner1",
    "northwest" : TARG_ROOM "library3",
    "out" : TARG_ROOM "east_inner2",
  ]) );
}
