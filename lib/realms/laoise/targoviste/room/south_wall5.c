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
    "An open area between the outer and inner walls of "
    "Targoviste, this area is designed to give the stronghold "
    "a second line of defense, should the outer wall ever "
    "be overrun. Battlements overlook the bailey from both "
    "sides, rising high overhead. Smoothed to a faint gloss, "
    "the black granite that paves the outer bailey has flecks "
    "of blood red scattered across it. To the east and west "
    "the bailey continues, forming a ring around the inner "
    "wall."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A breeze buffets the air.",
  ]) );
  SetSmell( ([
    "default" : "The slight moisture of the air is detectable as "
    "it slides quickly by.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "south_wall4",
    "west" : TARG_ROOM "south_wall6",
  ]) );
}
