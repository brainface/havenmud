// Targoviste
// Laoise
// August 2004
// Evoker Trainer

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
    "A long aisle of open wooden floor runs from here to the "
    "east. Blood red carpet borders each side of the length of "
    "black wood. Inlaid symbols in gold are laid out across it, "
    "contrasting sharply with the jet color of the smooth wood. "
    "From the arrangement of the markings, this appears to be "
    "an area used for practicing magical combat. Along each wall "
    "run shelves that reach the ceiling, filled with neatly "
    "arranged tomes. Many strange languages and symbols are "
    "visible on the thick bindings. Other parts of the library "
    "sit to the east and south."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The crackle and zap of magic echos through "
    "the air.",
  ]) );
  SetSmell( ([
    "default" : "Incense perfumes the air, cut by the sharp "
    "whiff of sulphur.",
  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "library1",
    "east" : TARG_ROOM "library3",
  ]) );
}
