#include "../wood.h"
#include <lib.h>
#include <std.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : HWD_ROOM "/gelf7",
  ]) );
  SetShort("a quiet clearing in the Havenwood");
  SetLong(
    "This quiet clearing has the burn marks and ash remains of "
    "many pyres, obviously making it place where the wild-elves "
    "go to celebrate their dead. The trees have been cleared back "
    "to give the pyres the room they need to burn hottest. A black "
    "soot-covered path leads to the north."
    );
  SetSmell("A faint odor of soot and ash tinges the air.");
  SetListen("Even the birds respect the somberness of the pyres.");
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
    HWD_NPC "/healer" : 1,
    ]) );
}
