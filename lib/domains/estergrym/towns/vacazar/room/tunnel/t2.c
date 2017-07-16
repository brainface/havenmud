// Coded by Zeratul
// 3-10-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("a dark tunnel");
  SetLong(
     "This tunnel has been carved out of the rock. The tunnel is rather "
     "large, leading strait into the base of the Estergrym Mountains. "
     "The floor is strewn with debris and occasional bone can be seen. "
     "A single torch lights the room providing minimal light for seeing. "
  );
  SetItems( ([
     ({"cave","cavern","tunnel"}) : (:GetLong:),
     ({"remains","bone","bones","remain"}) :
     "A bone or two can be found scattered along the tunnel. The bone remains "
     "appear to be from cave rats. ",
     ({"torch","torches"}) : "A single torch lights this section of the tunnel. "
     "It only gives minimal light to be able to see to navigate the tunnel. ",
  ]) );
  SetItemAdjectives( ([
     "tunnel" : ({"dark","long"}),
     "bones" : ({"scattered","rotting"}),
     "torch" : ({"dim"}),
  ]) );
  SetInventory( ([
  ]) );
  SetSmell( ([
     "default" : "A musty smell hangs in the air. ",
     ({"bones","bone","remain","remains"}) : "The scent of rot and "
     "mildew is obvious.",
  ]) );
  SetListen( ([
     "default" : "A faint sound of wind echo through the tunnel.",
     ({"torch","torches"}) : "A faint crackle of the flame is heard.",
  ]) );
  SetExits( ([
     "north" : V_ROOM + "tunnel/t1",
     "south" : V_ROOM + "tunnel/t3",
  ]) );
  }
