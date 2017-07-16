#include <lib.h>
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Blah");
   SetDayLong("Blahday");
   SetNightLong("Blahnight");
   SetItems( ([
                ({ ({ "day" }),({ "beautiful" }) }) :
                   "Blah day items",
                ({ "night" }) :
                   ({ "Daytime desc.","Nightime desc." })
           ]) );
}
