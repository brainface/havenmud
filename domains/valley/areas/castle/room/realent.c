#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

int PreExit();

static void create() {
   room::create();
   SetShort("near Vale Castle");
   SetLong("An abandoned trail meanders off in the south, going "
           "to the east and west.  This offshoot goes to the north "
           "into a castle, where a portcullis exists to prevent "
           "people from entering.  It is not often locked, however, "
           "when there isn't a battle around.");
   SetItems( ([
                ({ "Vale Castle","castle","vale castle" }) :
                   "The Vale Castle is just to the north.  A "
                   "portcullis serves as its gate.  Much of the "
                   "castle is a little to the west of here, too.",
                ({ "abandoned trail","trail","offshoot" }) :
                   "The trail is to the south of here.  It looks like "
                   "a much more used trail than the offshoot here.",
           ]) );
   SetSmell( ([
                "default" : "The dust of the road hangs in the air.",
           ]) );
   SetListen( ([
                 "default" : "Lots of noise comes from within the castle.",
            ]) );
   SetExits( ([
                "north" : VC_ROOM + "/gate",
           ]) );
   AddExit("south","/domains/valley/virtual/valley/-20,0",(: PreExit :));
}

int PreExit() {
   if(!userp(this_player()) && this_player()->GetOwner() == "") return 0;
   return 1;
}
