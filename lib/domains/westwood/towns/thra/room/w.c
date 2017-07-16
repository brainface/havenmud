/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../thra.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "east" : THRA_ROOM "center",
    ]) );
  SetShort("on the western platform of Thra");
  SetLong(
    "The western platform of the village of Thra is arranged in a much more "
    "organized fashion than most of the village. A large wooden counter is built "
    "among the tree itself, with what appears to be stone doors securely fastened "
    "into the tree. The platform extends back to the east, where it meets up "
    "with the main platform of the village."
    );
  SetItems( ([
    "counter" : "The counter is a large, wooden affair designed for dealing best "
                "with customers.",
    ({ "door", "doors" }) : "The stone doors seem to be safes of some kind.",
    ]) );
  SetInventory( ([
    THRA_NPC "bank" : 1,
    ]) );                    
}