#include "itemsschtuff.h"
#include <lib.h>
#define THISROOM "/domains/soleil/obj/cl_board"
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
