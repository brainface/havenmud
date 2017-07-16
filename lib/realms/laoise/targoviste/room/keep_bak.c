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
  SetShort("before the cathedral of Aberach");
  SetLong(
    "To the east looms the main cathedral of Aberach. The central "
    "aspect of this edifice is a square front, topped by a triangular "
    "arch with spires rising from all its apices. To either side of "
    "the central structure are long arms which connect to a pair of "
    "towers. These arms form a transept running from north to south "
    "and are supported by flying buttresses. Elaborate pinnacles rise "
    "from all aspects of the cathedral, soaring high in to the darkened "
    "sky. Intricate windows are visible on all parts of the cathedral, "
    "decorated with complex tracery, including cinquefoil motifs at the "
    "top. The cathedral faces east, towards the outer keep, exterior wall "
    "and eventually the Targoviste Road."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Wind buffets the spires of the cathedral, creating "
    "an eerie whistling sound.",
  ]) );
  SetSmell( ([
    "default" : "The air moves by too swiftly for any scents to "
    "linger here",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "church2",
    "west" : TARG_ROOM "west_inner2",
  ]) );
}
