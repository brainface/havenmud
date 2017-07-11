#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground"); SetWarmth(45);
  SetAmbientLight(35);
  SetShort("a tunnel entrance");
  SetDayLong(
    "A small amount of light filters in from outside and mixes with "
    "light provided by small globes of light that glow from the tunnel "
    "entrance. Deeper in to the north, the tunnel seems to drop down "
    "quickly into the mountain, while directly to the south the tunnel "
    "ends and leads back to the surface. The entrance to the tunnel "
    "is supported by massive stoneworking that supports the welcoming "
    "arms of the dwarven city."
    );
  SetNightLong(
    "The starlight filters into the tunnel and mixes with the soft glow "
    "of several magical globes of light recessed into the walls of the "
    "tunnel entrance here. Further north, the tunnel drops rapidly into "
    "the side of the mountain, heading off towards the dwarven city of "
    "Glimmerdin, while to the south the tunnel ends and leads back to the "
    "Glimmerdin Road. The entrance to the tunnel is supported by massive "
    "stoneworking that supports the welcoming arms of Glimmerdin."
    );
  SetSmell( ([
    "default" : "A deep earthy smell comes from the tunnel.",
    ]) );
  SetListen( ([
    "default" : "A faint echo of noise comes from deep in the mountain.",
    ]) );
  SetItems( ([ 
    ({ "globe", "globes", "light", }) :
        "The magical globes of light provide enough of a glow for most races "
        "to be able to see comfortably here.",
    ({ "tunnel", "opening", }) :
        "The tunnel leads deep into the mountain city of Glimmerdin.",
    ({ "entrance" }) : 
        "The entrance to the tunnel is a massive opening supported by "
        "impressive stoneworking which only a dwarf could accomplish.",
    ({ "stoneworking" }) :
        "The stoneworking is solid stone, hewn and formed into supports "
        "to prevent any damage or possibility of cave in to the tunnel.",
    ]) );
  SetItemAdjectives( ([
    "globe"        : ({ "magical", "of", "light", "globe", "globes", }),
    "tunnel"       : ({ "massive", }),
    "stoneworking" : ({ "massive", }),
    ]) );
  SetExits( ([ 
    "south" : G_ROOM "outside_gate",
    "north" : G_ROOM "holding",
    ]) );
  SetInventory( ([ 
    G_OBJ + "gate_sign" : 1,
    ]) );  
}
