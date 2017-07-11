//2006
#include <lib.h>
#include "../../lisht.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("Lisht Barracks");
  SetExits( ([
    "out" : LISHT_ROOM "gnoll/wr4",
    "up" : LISHT_ROOM "gnoll/barracks2",
  ]) );
  SetLong(
    "The Lisht Barracks is a large building where the worthy "
    "come to train their physical skill. This room serves as "
    "a training area, and the walls are lined with many weapons "
    "and shields, as well as trophies brought back from victorious "
    "battles long past. There is a staircase at one end of the room.");
  SetInventory( ([
    LISHT_NPC + "general_sefet" : 1,
    LISHT_NPC + "captain_neith" :1,
  ]) );
  SetItems( ([
    ({ "weapons", "shields", "walls", "weapon", "wall" }) :
        "The walls are covered with swords, axes, shields, and "
        "other implements of destruction and war.",
    ({ "trophy", "trophies" }) :
        "Scalps, ears, and sometimes whole heads. It isn't the "
        "prettiest collection.",
   ]) );
  SetListen("The sounds of training ring through the air.");
  SetSmell("It smells of sweat, blood, and steel.");
}
