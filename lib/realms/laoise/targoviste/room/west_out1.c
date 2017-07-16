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
    "To the southeast the obsidian stone wall of Targoviste "
    "continues to bend until it meets with the Estergrym "
    "Mountains, forming an impenetrable barrier. To the "
    "west and south lies a small rim of flat land which "
    "ends where the mountains rise upwards. To the north "
    "lies the entrance to the city of Targoviste."
 
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A light breeze whisks across the plain.",
  ]) );
  SetSmell( ([
    "default" : "The air is filled with a damp smell.",
  ]) );
  SetExits( ([ 
    "northwest" : TARG_ROOM "west_out2",

  ]) );
}
