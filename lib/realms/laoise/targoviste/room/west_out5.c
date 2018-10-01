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
  SetAmbientLight(-20);
  SetDomain("Estergrym");
  SetTown("Targoviste");
  SetShort("before the outer wall of Targoviste");
  SetLong(
    "The obsidian outer wall of Targoviste stands to the west, "
    "rising far into the air and blocking out what little light "
    "managed to pass the heights of the Estergrym Mountains. "
    "Crenulations occur at regular intervals, carved out of the "
    "black stone which forms the battlement atop the wall. To "
    "the west there is a narrow band of open flatland before "
    "the mountains rear sharply upward. To the south lie the "
    "the exterior gates and gates in the outer wall of the city. "
    "To the north a narrow band of flatland continues, tracing "
    "the exterior wall."
  );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A faint breeze stirs the air.",
  ]) );
  SetSmell( ([
    "default" : "The smoky scent of peat permiates the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "west_out6",
    "south" : TARG_ROOM "west_out4",
  ]) );
}
