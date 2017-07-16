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
  SetTown("Targoviste");
  SetShort("the bank of Targoviste");
  SetLong(
    "This is a square room, its north wall dominated by a large door "
    "which is held in place by huge iron bolts. Holding the door closed "
    "is a bar, which is locked in place by a padlock. A low counter sits "
    "before this door, and behind it the bank teller usually stands, "
    "ready to help customers. The east and west walls of this square room "
    "are covered with intricate murals, carved in relief upon their black "
    "stone. To the south is the arched entrance to the bank, which leads "
    "back to the inner keep. Tucked in the northwest corner of the bank is "
    "a small altar, with several sticks of incense set before it."
  );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The bank is quiet and organized.",
  ]) );
  SetSmell( ([
    "default" : "A light smell of incense perfumes the air.",
    "incense" : "The incense smells musky, with the faint coppery scent "
    "of blood beneath it.",
  ]) );
  SetExits( ([ 
    "out" : TARG_ROOM "south_inner1",
  ]) );
}
