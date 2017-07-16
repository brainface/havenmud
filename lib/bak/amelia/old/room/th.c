#include <lib.h>
inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetShort("The Treehouse");
   SetLong("Sunlight streams in through the cracks in the rough wooden "
           "boards and the window on the north side of this old, worn "
           "tree house.  Even during the night time, the sun still "
           "seems to be shining outside, as if this play area has been "
           "enchanted and is held in a magical world or some sort of "
           "field that hangs in perpetual day.");
   SetExits( ([
                "up" : "/domains/heaven/room/sage",
                "down" : "/domains/heaven/room/olympus",
                "west" : "/domains/heaven/room/clouda",
           ]) );
   SetObviousExits("none");
}
