#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("beneath the lilac bush");
   SetDomain("WestWood");
   SetLong("The branches of the lilac spread out above, forming this "
           "small space beneath, with just enough room to curl up and "
           "rest.  The grass is soft and seems to have been pressed by "
           "some body for a long period of time.  It is possible to "
           "slip out of here through the branches.");
   SetItems( ([
                ({ "lilac branches","branches","branch","lilac branch" }) :
                   "The branches are thin but strong, and many of them "
                   "split off the main part of the lilac bush.",
                ({ "lilac bush","bush","lilacs","lilac" }) :
                   "The lilac bush is beautiful from beneath, just as "
                   "from above.  Its branches form this cubbyhole of "
                   "empty and refreshing space, hidden from the world.",
                ({ "small space","space","cubbyhole" }) :
                   (: GetLong :),
                ({ "soft grass","grass","dew" }) :
                   "The grass is green and soft, dampened slightly by "
                   "dew.  It is pressed down as if someone has slept "
                   "in here, or rested for a long while.",
           ]) );
   SetListen( ([
                 "default" : "The world is quiet, with no more noise "
                    "than that of dew forming on grass.",
            ]) );
   SetSmell( ([
                "default" : "The smell of lilacs is thick in the air.",
           ]) );
   SetExits( ([
                "out" : M_ROOM + "garden_d",
           ]) );
   SetInventory( ([
                    M_NPC + "unicorn" : 1,
               ]) );
}
