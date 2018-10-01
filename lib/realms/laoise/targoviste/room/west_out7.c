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
    "To east stands the outer wall of Targoviste. Formed "
    "of black stone the wall is a massive edifice protecting "
    "the city it encloses. The wall curves here, running "
    "to the northwest and curving around the city. Just north "
    "of here the outer wall meets the Estergrym Mountains, "
    "forming a joining through which nothing can pass. To "
    "the south lies the main entrance to the city, as well "
    "as Targoviste Road."
  );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The wind shrieks through the craigs of the "
    "Estergrym Mountains.",
  ]) );
  SetSmell( ([
    "default" : "A faint smells of peat is whipped past on the "
    "swift-moving air.",
  ]) );
  SetExits( ([ 
    "southwest" : TARG_ROOM "west_out6",
  ]) );
}
