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
  SetDomain("Estergrym");
  SetTown("Targoviste");
  SetShort("within the outer bailey of Targoviste");
  SetLong(
    "The obsidian outer wall of Targoviste stands to the north, "
    "rising far into the air and blocking out what little light "
    "managed to pass the heights of the Estergrym Mountains. "
    "Crenulations occur at regular intervals, carved out of the "
    "black stone which forms the battlement atop the wall. Of a "
    "similar design is the inner wall of the stronghold, which "
    "rises to the south. The space between these two walls is "
    "the outer bailey, and is designed to give Targoviste a "
    "second line of defense, if the outer wall were ever breached. "
  );
  SetListen( ([ 
    "default" : "A faint clatter drifts from the west.",
  ]) );
  SetSmell( ([
    "default" : "Damp air moves swiftly across the stone of "
    "the outer bailey.",
  ]) );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "north_wall4",
    "west" : TARG_ROOM "north_wall2",

  ]) );
}
