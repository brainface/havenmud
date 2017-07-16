#include <lib.h>
#include "path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a bloody battlefield");
    SetLong("All previous notions of this being a peaceful place are "
          "shattered as it instantly becomes a violent, bloody battlefield.  "
          "Corpses of orcs and men are strewn about."
          "  To the south, a huge stone building can be seen.");
    SetItems( ([
          ({ "huge stone building", "huge building", "stone building",
          "building" }) :
          "The huge building looms over the fields, as if it were watching "
          "the battle below.",
          ({ "corpses", "corpse", "dead orcs", "dead men", "orcs", "men" }) :
          "There are many more dead humans than orcs on the field.",
          ({ "violent battlefield", "bloody battlefield", "battlefield",
          "field" }) :
          "The field is stained with the blood of hundreds of soldiers.",
           ]) );
    SetExits( ([
          "north" : BEORN_ROOM + "field1.c",
          "south" : BEORN_ROOM + "field3.c",
           ]) );
    SetObviousExits("north, south");
    SetInventory( ([
          BEORN_NPC + "osoldier.c" : 2,
          ]) );
    SetSmell( ([
          "default" : "The smell of death is in the air.",
          "corpses" : "The smells of sweat, blood, and rotting meat mix "
          "and enter your nostrils.",
]) );
    SetListen( ([
          "default" : "The clanging sounds of steel upon steel can be heard.",
]) );
}

