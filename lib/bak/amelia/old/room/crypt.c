#include <lib.h>
inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("The Crypt");
   SetLong("The room is chilling, and the walls are "
           "covered with blood.  A torch lights the "
           "room");
   SetInventory( ([ "/realms/amelia/npc/crypt.c" : 1 ]) );
}
