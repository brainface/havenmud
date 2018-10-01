#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("blood River road");
  SetLong(
    "Blood River road continues to the north and south. "
    "The Blood River flows down the center of the two lane "
    "Blood River road from north to south. Looming up in the "
    "darkness to the south the huge gothic style cathedral "
    "of Saahagoth can be seen. To the west is the Grymxoria "
    "cemetery."
  );
  SetItems( ([
    ({ "river", "blood river", "Blood river" }) : "The blood river "
    "flows down the center of the divided two lane road. "
    "It gets its name from the reddish color of the water from "
    "the large amounts of iron and copper in it.",
    ({ "cathedral", "church" }) : "The cathedral looms up to "
    "the south. Its tallest spire nearly touching the roof of "
    "the cavern. Colored patches of light can be seen shining "
    "eerily through the stained glass windows of the cathedral.",
    "cemetery" : "The Grymxoria cemetery, in the darkness, "
    "only the faint outline of large tombs can be seen."
  ]) );
  SetListen( ([
    "default" : "The river swishes and gurgles eerily."
  ]) );
  SetExits( ([ 
    "north" : G_ROOM + "road6",
    "south" : G_ROOM + "road11"
  ]) );
  SetEnters( ([
    "cemetery" : G_ROOM + "cemetery"
  ]) );
}

