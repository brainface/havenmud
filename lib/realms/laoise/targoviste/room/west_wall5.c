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
  SetShort("the outer bailey of Targoviste");
  SetLong(
    "To the west looms the outer wall of Targoviste. Formed "
    "of jet stone, it mirrors the inner wall which stands to "
    "the east. The space between the two walls is the outer "
    "bailey, which is paved with polished black granite. "
    "Immediately to the east is the exterior wall of a large "
    "building, above which the inner wall rises. To the south "
    "lies the main entrance to the city, while to the north "
    "the bailey curves around the inner wall. High overhead "
    "the Estergrym Mountains ascend towards the sky."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A soft murmer of voices seems to be coming from "
    "the building to the east.",
  ]) );
  SetSmell( ([
    "default" : "A faint scent of peat slips through the air.",
  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "west_wall4",
    "northeast" : TARG_ROOM "north_wall1",
  ]) );
}
