#include <lib.h>
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("blah");
   SetLong("blah blah");
   SetExits( ([
                "west" : "/realms/amelia/room/th",
           ]) );
}
