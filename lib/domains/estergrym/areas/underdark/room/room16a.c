#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow sloping tunnel");
  SetLong("A narrow tunnel, it goes steeply down to the north. A small "
          "stream flows through from the south, going steeply down in a "
          "cascade to the north. A set of stairs have been cut into the living "
          "rock beside the stream, they lead steeply down. An evil darkness "
          "seems to flow up out of the depths. ");
  SetExits( ([
          "south" : U_ROOM + "room15a",
          "down" : U_ROOM + "room1b"]) );
  SetItems( ([
          "darkness" : "Eveything seems oddly dark, even for inside a cave. "
          "Somehow, the darkness is almost touchable.",
          "tunnel" : "A small tunnel leading from the large chamber "
          "down. In the extreme darkness, nothing can be seen further "
          "down the tunnel.",
          "stairs" : "Crude stairs have been cut into the living rock of the "
          "floor of the tunnel they follow the stream steeply down into the "
          "darkness.",
          "rock" : "The entire cave is made out of your standard issue "
          "sedamentary rock. Looks like mabey lime stone.",
          ({ "stream", "small stream", "stream of water" }) : "A small stream "
          "of crystal clear water, barely more than a trickle, flows in from the "
          "south and goes steeply down to the north. It cascades down the "
          "tunnel out of sight into the darkness."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetListen( ([
          "default" : "A sound of flowing water fills the tunnel."]) );
  SetInventory( ([
          U_NPC + "dwarf_soldier" : 4 ]) );
  }
