#include <lib.h>
#include <std.h>
#include "../averath.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west"  : AVERATH_ROOM "wharf",
    "north" : INNERSEA_VIRTUAL "ocean/1,-100",
    ]) );
  SetShort("a charter ferry wharf");
  SetProperty("coastal", 1);
  SetLong(
    "This is a wharf for a charter ferry. A large dock juts into the ocean from here. "
    "A small booth sits near the dock with small paintings of Haven, Parva, Tairi, and Averath."
    );
  SetSmell(
    "The scent of the ocean fouls the air."
    );
  SetListen(
    "Waves lap across the dock."
    );
  SetInventory( ([
    STD_OBJ "dock_sign" : 1,
    AVERATH_OBJ "charterferry" : 1,
    AVERATH_NPC "chartercaptain" : 1,
    AVERATH_NPC "ticketagent" : 1,
    ]) );
}
         
 
