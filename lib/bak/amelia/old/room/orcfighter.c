#include "itemsschtuff.h"
#include <lib.h>
#define THISROOM "/realms/balishae/of_guild/obj/fighter_guild_board"
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
