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
    "This the outer bailey, an area which sits between "
    "the exterior wall of the stronghold, to the east, and "
    "the inner keep, to the west. Above the wall of the "
    "inner keep protrudes the spires of cathedral of Aberach. "
    "Framing the east and west of this area are matched pairs "
    "of enormous gates, used to defend the inner and outer "
    "walls of Targoviste in the event of an attack. Off to the "
    "north is a building with smoke rising from its chimney, "
    "while further south sits a low wall with iron spikes running "
    "along the top. "
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Various city sounds come from all sides.",
  ]) );
  SetSmell( ([
    "default" : "A light smell of smoke fills the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "east_wall2",
    "south" : TARG_ROOM "east_wall4",
    "west" : TARG_ROOM "keep_e",
/*
    "east" : TARG_ROOM "east_out4",
*/
  ]) );
}
