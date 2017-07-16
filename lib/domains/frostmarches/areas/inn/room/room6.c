#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an empty room");
  SetAmbientLight(35);
  SetLong("This place is bare and very clean except for a puddle of vomit in "
          "the exact center of the room, which has soaked itself into the "
          "wood and will probably cause rotting in the near future.  A sign "
          "on the wall proclaims the room to be for future expansion.");
  SetSmell( ([
             "default" : "The room has a highly unpleasant odor to it.",
             ({ "puddle of vomit", "puddle", "vomit" }) : "The smell of this "
                "vomit is enough to cause pain in almost anyone's sinuses."
             ]) );
  SetListen( ([
              "default" : "Strangely, unintelligible whispers can be heard."
              ]) );
  SetItems( ([ 
             ({ "sign" }) : "The sign reads:\n"
                            "For future expansion.\n"
                            "Please exit the room.\n"
                            "Thank you",
             ({ "floor", "wood" }) : "The floor is soaked with vomit.",
             ({ "puddle of vomit", "puddle", "vomit" }) :
                "The vomit appears to have been put here recently.  Some "
                "drunkard probably stumbled in here earlier and left it."
             ]) );
  SetRead( ([
            ({ "sign" }) :
               "For future expansion.\n"
               "Please exit the room.\n"
               "Thank you"
            ]) );
  SetObviousExits("east");
  SetExits( ([ "east" : I_ROOM + "/hall3" ]) );
  SetClimate("indoors");
}
