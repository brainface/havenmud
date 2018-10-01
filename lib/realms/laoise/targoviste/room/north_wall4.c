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
    "The obsidian outer wall of Targoviste curves here, extending "
    "towards the east and southwest. Reaching high in to the air, "
    "it manages to obscure what little light slipped past the "
    "darkened sky overhead. Southeast of here runs the rear wall "
    "of a building set up against the inner wall of the stronghold. "
    "The black granite of the outer bailey has been polished "
    "smooth, highlighting the blood red flecks that are scattered "
    "across the paving stones. Battlements on both the inner and "
    "outer walls loom above."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A faint whuffling sound comes from the air moving "
    "through the battlements.",
  ]) );
  SetSmell( ([
    "default" : "The air is almost foggy with moisture.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "north_wall5",
    "west" : TARG_ROOM "north_wall3",
  ]) );
}
