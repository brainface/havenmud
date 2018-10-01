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
  SetShort("before the outer wall of Targoviste");
  SetLong(
    "The massive outer wall of Targoviste looms to the east, "
    "blocking out any random rays of sunlight which had managed "
    "to penetrate the rugged peaks of the Estergrym Mountains. "
    "Atop the wall runs a battlement, punctuated by crenulations "
    "at regular intervals. To the west lies a meager section of "
    "open ground, which ends abruptly where the mountains rear "
    "upwards. To the north lies the main entrance to the city, "
    "while to the south the outer wall continues, bending to the "
    "southeast."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The wind howls through the mountains",
  ]) );
  SetSmell( ([
    "default" : "A touch of moisture permiates the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "west_out3",
    "southeast" : TARG_ROOM "west_out1",
  ]) );
}
