//Illura@haven
//Room 29
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetShort("a crystal ring");
  SetLong(
    "The walkway curves in a circular manner, flanked on the "
    "outer edge by a balustrade of ice forged columns. The crystal "
    "ring is etched with ancient symbols that at one time were "
    "lain with gold filligree. Most of it has long since worn away, "
    "giving the carvings a lackluster, tired look."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "30",
    "northeast" : TAIGA_ROOM "28",
  ]) );
  SetItems( ([
    "walkway" : "The walkway is made of solid ice, but is not too slippery.",
    ({"balustrade", "columns", "edge"}) : "The balustrade of ice columns arcades the walkway, keeping you from falling over the edge.",
    "ring" : "The arcaded walkway is circular in shape, made of ice crystal.",
    ({"filigree", "carvings", "symbols"}) : "The ice is etched with strange carvings in no script you recognize, and in some places are still filled with gold foil that once made them more legible and has since eroded away.",
  ]) );
  SetItemAdjectives( ([
    "edge" : "outer",
    "columns" : "ice",
    "ring" : "crystal",
    "symbols" : "ancient",
    "filigree" : "gold"
  ]) );
  SetInventory( ([
    TAIGA_NPC + "vanguard" : 2,
    TAIGA_NPC + "chillfang" : 1,
  ]) );
  SetListen( ([
    "default" : "Sweet unearthly voices sing an unending toneless hymn.",
  ]) );
  SetSmell( ([
    "default" : "The air smells old and vibrates with ancient magic.",
  ]) );
}
