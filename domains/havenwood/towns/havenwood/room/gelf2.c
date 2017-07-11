#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in the HavenWood");
  SetLong(
    "The path around the outer rim of the Havenwood continues here, leading "
    "back to the northwest and to the east. A large clearing opens to the "
    "north. The trees here, like in the rest of this area of the Wood, are "
    "large and well tended. The trunk of one of the tree seems to have been "
    "hollowed out for use as a tannery."
    );
  SetItems( ([
    ({ "trunk", "tannery" })  : "The tannery is the place in the Havenwood where leather is cured.",
    "path" : "The path continues east and northwest.",
    ]) );
  SetEnters( ([
    "trunk"    : LEATHER_DIR "/leatherstore",
    ]) );
  SetSmell("The smell of curing hides comes from the tannery.");
  SetListen("Birds chirp and the wind blows through the tree branches.");
  SetExits( ([
   "northwest" : HWD_ROOM + "/gelf1",
   "north"     : HWD_ROOM + "/gelf4",
   "east"      : HWD_ROOM + "/gelf7",
   ]) );
}
