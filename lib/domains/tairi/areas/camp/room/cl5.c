#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a path through the encampment");
  SetExits( ([
    "southwest" : CAMP_ROOM + "cl4",
    "south"     : CAMP_ROOM + "cl6",
    ]) );
  SetNightLight(10);
  SetDayLong("In the sunlight this patch of ground seems pleasant and "
             "could even pass for hospitable.  Off to the south there "
             "seems to be a large tent which dominates that clearing. "
             "Off to the southwest the path continues into the camp.");
  SetNightLong("In the starlight this path seems to be somewhat dark "
               "and forboding.  To the south the path leads into a large "
               "clearing which houses some kind of tent.  The path leads "
               "back into the camp to the southwest.");
  SetInventory( ([
    CAMP_NPC + "labandit" : 2,
    ]) );
 }
