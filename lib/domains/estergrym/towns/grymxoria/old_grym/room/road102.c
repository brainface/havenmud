#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetAmbientLight(40);
  SetClimate("temperate");
  SetDomain("Estergrym");
  SetShort("A road inside a tunnel");
  SetLong("This small cobblestone road is going deep into the "
    "tunnel inside the Estergrym Mountains. It is pretty "
    "cold in here because a lot of air runs through here. "
    "Small lanterns hanging here provide small amounts of "
    "light.");
  SetListen( ([ "default" : "The air is quickly whipping through "
    "here." ]) );
  SetItems( ([ ({ "road", "cobblestone road" }) : "This nicely made "
      "cobblestone road heads west and up.",
    ({ "lantern", "lanterns" }) : "These lanterns provide "
      "small amounts of light inside the tunnel.",
    ({ "mountains", "estergrym mountains" }) : "This "
      "mountain completely surrounds the tunnel",
  ]));
  SetObviousExits("west, east");
  SetExits( ([ "west" : G_ROOM "road103",
    "east" : G_ROOM "road101",
  ]) );
}
