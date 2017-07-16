/*  Tunnel from Cavern to Chasm  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(0);
  SetShort("a fork in the tunnel");

  SetLong("At the end of the indistinguishable tunnel the tunnel forks off to "
          "the northeast and southeast.  The path to the northeast seems to "
          "be used more often as there pathway worn into the already semi-"
          "smooth surface.  The path to the southeast doesn't appear to be "
          "used quite as much as the other since it isn't as worn or smooth.");
  SetSmell( ([
    "default"  :  "As a breeze from the northeast blows past you the smell of "
                  "damp fresh air fills your nose.",
  ]) );

  SetListen( ([
    "default"  :  "A rumbling is quite noticeable here.",
  ]) );

  SetExits( ([
    "west"       :  ROOMLV2 + "/tunnel2b",
    "northeast"  :  ROOMLV2 + "/chasm2a",
    "southeast"  :  ROOMLV2 + "/chasm2c",
  ]) );
  SetObviousExits("northeast, southeast, west");

  SetItems( ([
    ({ "tunnel", "indistinguishable tunnel" })  :  (: GetLong :),
    ({ "path" })  :
       "Do you mean the northeast path or the southeast path?",
    ({ "northeast path", "northeastern path" })  :
       "This path looks to be used much more often as there is a trail worn "
       "into it.  From this direction you can feel a slight breeze.",
    ({ "southeast path", "southeastern path" })  :
       "This path doesn't seem to be used very often, although it is used "
       "often enough to keep it clear of cobwebs and anything else that may "
       "block the path.",
    ({ "pathway", "worn pathway" })  :
       "The pathway has been worn deep with years and years of footuse.",
    ({ "trail" })  :
       "The trail is worn into the already semi-smooth northeastern path.",
  ]) );
}
