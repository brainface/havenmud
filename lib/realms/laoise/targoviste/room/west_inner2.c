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
    "To the east looms the main cathedral of Aberach. Elaborate "
    "pinnacles rise from all aspects of the cathedral, soaring "
    "high in to the darkened sky. Intricate windows are visible "
    "on all parts of the cathedral, decorated with complex tracery, "
    "including cinquefoil motifs at the top. The cathedral entrance "
    "faces east, towards the outer keep, exterior wall and eventually "
    "the Targoviste Road. Buildings to the north and south cradle "
    "this open area."
  );
  SetItems( ([ 
    ({ "church", "cathedral" }) :
    "The central "
    "aspect of this edifice is a square front, topped by a triangular "
    "arch with spires rising from all its apices. To either side of "
    "the central structure are long arms which connect to a pair of "
    "towers. These arms form a transept running from north to south "
    "and are supported by flying buttresses.",
    ({ "buildings", "building" }) :
    "Buildings to the north and south surround this open area, but "
    "only their exterior walls are visible. The north building appears "
    "to have an entrance west and north of here, while the south "
    "building has no visible entrance.",

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
    "north" : TARG_ROOM "west_inner3",
    "south" : TARG_ROOM "west_inner1",
    "east" : TARG_ROOM "church1",
    "west" : TARG_ROOM "keep_w",
  ]) );
}
