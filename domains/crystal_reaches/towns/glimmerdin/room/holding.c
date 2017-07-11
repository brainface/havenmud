#include <lib.h>
#include <domains.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground"); SetWarmth(45);
  SetAmbientLight(30);
  SetShort("a checkpoint in the tunnel");
  SetLong(
    "The tunnel bends here, heading deeper into the mountain. "
    "Off to the south, the tunnel heads back to the surface, away "
    "and out from the mountain. Built into the wall of the curve "
    "is a checkpoint that guards use to watch the traffic heading "
    "into and out of Glimmerdin. Carved into the walls are murals "
    "depicting the glory of the dwarven race. Guarding the entrance "
    "to the east is a large stone gate, hewn from the mountain itself."
    );
  SetProperty("no bump",1);
  SetItems( ([ 
    ({ "wall", "walls" }) : 
        "The walls are formed from the natural stone of the mountain. "
        "Their structure is immense and carved with murals.",
    ({ "mural", "murals" }) :
        "The murals are carved directly into the walls, and depict "
        "scenes from the history of both Glimmerdin and the dwarven "
        "heroes of old.",
    ({ "checkpoint", "outpost", }) :
        "The checkpoint is little more than a small stone outpost built "
        "into the walls to prevent access to the city if needed.",
    ({ "gate", }) :
        "The massive stone gate that guards Glimmerdin appears to weigh "
        "several tons and would be impossible to move when closed.",
    ]) );
  SetItemAdjectives( ([
    "wall"    : ({ "stone" }),
    "outpost" : ({ "small", "stone", }),
    "gate"    : ({ "large", "stone", }),
    ]) );
  SetExits( ([ 
    "south" : G_ROOM "greatgate",
    "east"  : G_ROOM "tunnel1",
    "west"  : CRYSTAL_REACHES_VIRTUAL "glimmerdintunnel/30,10",
    ]) ); 
  SetInventory( ([ 
    G_NPC "gate_sentry" : 2,
    ]) );
  SetSmell( ([
    "default" : "An earthy smell mixes with a breeze from the surface.",
    ]) );
  SetListen( ([
    "default" : "Faint sounds of an active civilization echo "
                "down the hallway from the east.",
    ]) );
}

	
