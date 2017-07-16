#include <lib.h>
#include "../argoth.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(45);
  SetShort("the Argoth pub");
  SetLong(
    "The Argoth pub is a rowdy, noisy building built to serve food "
    "and drink to the citizens of the town.  On the far side of the room is "
    "a bar with several stools, some standing, some not.  There are several "
    "tables scattered about with no apparent pattern."
  );
  SetDomain("Crystal Reaches");
  SetItems( ([
    ({ "bar" }) :
    "The bar is made out of a fine dark wood",
    ({ "tables" }) :
    "The tables are small and wooden.",
    ({ "stools" }) :
    "The stools are tall and dark.  Some are stained badly from a corrosive "
    "chemical being spilled on them.",
  ]) );
  SetSmell( ([
    "default" : "The place smells of grog, vomit, and sweat.",
  ]) );
  SetListen( ([
    "default" : "Violent threats and drunken insults are thrown about the room.",
  ]) );
  SetInventory( ([
    ARGOTH_NPC + "barkeep" : 1,
    ARGOTH_NPC + "fighter_leader" : 1,
    ARGOTH_NPC + "fighter_trainer" : 1,
    ARGOTH_NPC + "citizen" : 2,
  ]) );
  SetExits( ([
    "out" : ARGOTH_ROOM + "rd7.c",
  ]) );
}
