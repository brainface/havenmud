#include "itemsschtuff.h"
#include <lib.h>
#define THISROOM "/domains/haven/obj/town_board"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort(THISROOM);
   SetLong(THISROOM);
   SetObviousExits(implode(keys(ITEMSSCHTUFF),", "));
   SetItems(ITEMSSCHTUFF);
   SetEnters(ITEMSSCHTUFF);
   SetInventory( ([
                    THISROOM : 1,
               ]) );
}
