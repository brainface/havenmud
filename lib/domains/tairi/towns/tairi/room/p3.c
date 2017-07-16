#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a dimly lit room");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetExits( ([
    "north" : "p2",
    ]) );
  SetLong("This dimly lit room is just south of the central hallway "
          "of the Grand Palace. The room is filled with arcane symbols and "
          "devices, and is obviously the palatial residence of the "
          "seer of Clan Minamoto.");
  SetItems( ([
    ({ "room", "residence" }) :
    	 (: GetLong :),
    ({ "hallway", "hall", "palace" }) :
    	 "The central hallway of the Grand Palace is just north of this room.",
    ({ "symbol", "symbols", "devices", "device" }) :
    	 "The arcane symbols and devices are scattered throughout the room.",
    ]) );
  SetItemAdjectives( ([
    "room"    : ({ "dimly", "lit", "palatial" }),
    "symbol"  : ({ "arcane" }),
    "hallway" : ({ "central" }),
    "palace"  : ({ "grand", "daimyo" }),
    ]) );
  SetSmell( ([
    "default" : "An odd bittersweet smell hangs in the air.",
    ]) );
  SetListen( ([
    "default" : "It is unusually quiet here.",
    ]) );
  SetInventory( ([
    TAI_RI_NPC "evoker" : 1,
    ]) );
}
