#include <lib.h>
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("a cutesy room");
   SetLong("Pretty flowers decorate this adorable room, but other than "
           "that, there is little of importance.");
   SetItems( ([
                ({ "adorable room","room","cutesy room" }) :
                   (: GetLong :),
                ({ "pretty flowers","pretty flower","flower","flowers",
                   "trapdoor","door","trap door","trap" }) :
                   "The flowers are of all different colors, some blue "
                   "and some red and some purple and some all three and "
                   "some of even more colors.  They are all mixed "
                   "together, except some which hang above, all "
                   "of a pure white color in one spot.",
           ]) );
   SetSmell( ([
                "default" : "A sweet smell floats through the room.",
                "flower" : "Scents of all kinds come from the flowers.",
           ]) );
   SetSearch( ([
                 "flower" : "Bugs which quickly scurry away pop up "
                   "as the flowers are ruffled through, but the main "
                   "object found is a trapdoor, up in flowers that "
                   "are of pure white.",
            ]) );
   SetEnters( ([
                 "trapdoor" : "/realms/amelia/workroom",
            ]) );
   SetExits( ([
                "up" : "/realms/amelia/workroom",
           ]) );
}
