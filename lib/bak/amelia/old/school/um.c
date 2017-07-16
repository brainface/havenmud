#include <lib.h>
inherit LIB_ROOM;

int PreExit();

static void create() {
   room::create();
   SetShort("an examplish room");
   SetLong("This room is an example of code.");
   SetObviousExits("south");
   AddExit("south","/realms/amelia/room/th",(: PreExit :));
}

int PreExit() {
   if(!userp(this_player())) return 0;
   else return 1;
}
