#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../starfire.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(15);
  SetShort("the narthex of a temple");
  SetLong(
 	"This appears to be a narthex in a house of worship. To the west a large mural has been painted on"
        " the stone walls. A similar mural can be seen on the eastern wall as well. The floor is mostly cleared"
        " of sand so that distinct blocks can be made out. The northern exit appears to narrow slightly before"
        " opening into a much larger chamber. The southern exit opens up into a hallway."
      );
  SetItems( ([
	({ "mural", "murals", "painting", "paintings" }) :
	"The murals depict a large reptile that has fallen in battle. The beast is seeping"
	" blood everywhere. Around the reptile a group of black robed individuals appear to be praying."
	" The western mural depicts what appears to be the same beast slowly rising while shrouded by a"
        " dark miasma. The hooded figures surrounding the beast appear to be channeling dark energy"
	" towards the miasma, feeding it.",
	({ "narthex", "room", "around" }) :
	(: GetLong :),
	({ "hallway" }) :
	"The southern exit appears to open up into a hallway. It is too dark to see very far.",
	({ "brick", "block", "bricks", "blocks", "wall", "walls", "mortar" }) :
	"The walls are composed of a series of yellow blocks held together by"
        " yellow mortar. The yellow color suggests both the blocks and mortar"
        " were made of sand.",
	({ "floor" }) :
	"The floor appears to be made of the same materials as the wall, only worn smooth by years"
        " of traffic. There is a thin layer of sand covering it.",
	]) );
  SetItemAdjectives( ([
	"mural" : ({ "large", "painted", "western", "eastern" }),
	"brick" : ({ "yellow", "sand", "stone" }),
	"floor" : ({ "sandy", "cleared" }),
	]) );
  SetExits( ([
      "south" : SF_ROOM "room01",
      "north" : SF_ROOM "room03",
      ]) );
  }
