//Selket@Haven
//2006
#include <lib.h>
#include "../../lisht.h"

inherit LIB_ROOM;

static void create(){
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("a War Room");
  SetExits( ([
    "down" : LISHT_ROOM "gnoll/barracks",
  ]) );
  SetLong(
    "This seems to be the place that General Sefet and his council "
    "go to to plan defenses of the city as well as excursions out into "
    "Xandria and beyond. There are no windows here, only a table "
    "and a great many maps tacked onto the walls. ");
  SetInventory( ([
    LISHT_NPC + "guard" : 2,
    LISHT_NPC + "battlemage" : 1,
  ]) );
  SetItems( ([
    ({ "map", "maps" }) :
    "The maps are colorfully painted and sometimes accurate.",
    ({ "table" }) :
    "The table is large, carved from a solid piece of wood, which "
    "is hard to come by in this climate. It is strewn with maps. ",
  ]) );
  SetListen("It is quiet here.");
  SetSmell("It smells a little dusty here.");
}
