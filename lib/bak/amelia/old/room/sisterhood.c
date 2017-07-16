#include "itemsschtuff.h"
#include <lib.h>
#define THISROOM "/realms/elasandria/areas/sisterhood_guild/obj/sisterhood_board"
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
