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
  SetAmbientLight(30);
  SetClimate("indoors");
  SetTown("Targoviste");
  SetShort("inside the cathedral of Aberach");
  SetLong(
    "To the east stands the main altar of the cathedral of Aberach. "
    "Set upon a square pedestal, the altar consists of a carved "
    "statue which appears to be slightly taller than the average "
    "nosferatu. Draped in a black robe, the statue's arm are held "
    "forward, revealing hands with long thin fingers and clawlike "
    "nails. Something from the shape suggests that the figure is "
    "female. Her left hand rests upon the pommel of an elaborate "
    "sword which is grounded upon the top of the pedestal. Above "
    "her right hand the figure balances a globe of dark blue fire "
    "which seethes as it hovers in the air. Before the statue's "
    "pedestal sits a large bowl, set upon the floor. The center "
    "of the cathedral lies to west."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Faint hissing comes from the globe of magical "
    "fire.",
  ]) );
  SetSmell( ([
    "default" : "The scent of brimstone curls throughout the chapel.",
  ]) );
  SetExits( ([ 
    "west" : TARG_ROOM "church3",
  ]) );
}
