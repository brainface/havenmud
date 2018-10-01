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
  SetShort("a darkened cemetery");
  SetLong(
    "Long rows of headstones stretch away to the south, arranged "
    "on either side of a broad avenue of grass. The nearest headstones "
    "are large and intricate, with statuettes surmounting them. The "
    "first headstone in the western row is carved of black marble that "
    "is streaked with veins of red. Cut in to the shape of an obelisk "
    "at the base, it is topped by the statue of a nosferatu warrior in "
    "full armour, with his hands crossed over the pommel of a sword which "
    "is grounded against the headstone. The rows of graves continue to "
    "the south, while to the southwest there appears to be an open area."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "It is eerily quiet.",
  ]) );
  SetSmell( ([
    "default" : "The smell of fresh-churned earth fills the cemetery.",
  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "cemetery2", 
    "southwest" : TARG_ROOM "cemetery3",
    "out" : TARG_ROOM "east_wall4",
  ]) );
}
