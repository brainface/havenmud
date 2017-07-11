#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetExits( ([
    "south" : "path1",
    "north" : "path6",
    ]) );
  SetShort("along the Way of the Warrior");
  SetLong("This path, the Way of the Warrior, leads north "
          "further into the town and south back towards the "
          "mountains. To the south is the checkpoint which "
          "controls access to the town, while to the north "
          "is the town center.");
  SetItems( ([
    ({ "path", "way", "trail" }) : 
    	    "The path is a beaten dirt trail leading to the north and south.",
    ({ "mountain", "mountains", "range" }) : 
    	    "The Tai mountain range loom to the south protecting this small "
    	    "valley.",
    ({ "center", "town", "tairi" }) :
    	    "The town center of Tairi is just north along the Way of the "
    	    "Warrior.",
    ({ "checkpoint", "access" }) :
    	    "The small checkpoint is south along the Way of the Warrior.",
    ]) );
  SetItemAdjectives( ([
    "path"       : ({ "beaten", "dirt" }),
    "center"     : ({ "town", "tairi" }),
    "checkpoint" : ({ "small" }),
    ]) );
  SetSmell( ([
    "default" : "The light scent of flowers fills the air.",
    ]) );
  SetListen( ([
    "default" : "The gentle sounds of town life whistle in the air.",
    ]) );
}


