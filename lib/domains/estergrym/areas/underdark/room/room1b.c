#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow sloping tunnel");
  SetLong("A narrow tunnel, it goes steeply up to the south. A small "
          "stream flows through from the south, falling steeply down in a "
          "cascade from the south. A set of stairs have been cut into the living "
          "rock beside the stream, they lead steeply up. An evil darkness "
          "seems to flow up out of the depths. The tunnel seems to open "
          "up to the north.");
  SetExits( ([
          "north" : U_ROOM + "room4b",
          "up" : U_ROOM + "room16a"]) );
  SetItems( ([
          "darkness" : "Eveything seems oddly dark, even for inside a cave. "
          "Somehow, the darkness is almost touchable.",
          "tunnel" : "A small tunnel leading down. In the extreme darkness, "
          "nothing can be seen further down the tunnel.",
          "stairs" : "Crude stairs have been cut into the living rock of the "
          "floor of the tunnel they follow the stream steeply up into the "
          "darkness.",
          "rock" : "The entire cave is made out of your standard issue "
          "sedamentary rock. Looks like mabey lime stone.",
          ({ "stream", "small stream", "stream of water" }) : "A small stream "
          "of crystal clear water, barely more than a trickle, flows in from the "
          "south and goes down to the north. It cascades down from the "
          "south and flows away to the north out of sight into the darkness."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetListen( ([
          "default" : "A sound of flowing water fills the tunnel."]) );
  }
