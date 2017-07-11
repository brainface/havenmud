// Amelia@Haven
#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetShort("on Parva's Wharf");
   SetDomain("HavenWood");
   SetLong("The water is spread out in front of the wharf, to the east "
           "where the floating docks are.  There are buildings to "
           "the west and the wharf continues to the south. "
           "There is a small building lying here that looks nearly "
           "ready to collapse."
           " The water looks rather dirty here.");
   SetItems( ([
                ({ "Parvas Wharf","wharf" }) :
                   (: GetLong :),
                ({ "floating docks","docks","dock" }) :
                   "The docks float serenely on the wave-filled "
                   "ocean.",
                ({ "dirty water","water","ocean" }) :
                   "The ocean is a simple green color, but "
                   "it looks dirty.",
                ({ "ramshackle buildings","buildings","building" }) :
                   "All of "
                   "the buildings in Parva are fairly shoddy "
                   "and temporary.  The building lying here is no "
                    "exception to that rule.",
                ({ "steep ramp","ramp" }) :
                   "The ramp leads down to the docks.  A number "
                   "of grooves on one side of it allow one "
                   "better purchase on the steep slope.",
           ]) );
   SetItemAdjectives( ([
                         "wharf" : ({ "parvas","parva" }),
                         "docks" : ({ "floating" }),
                         "water" : ({ "dirty","wave-filled" }),
                         "building" : ({ "ramshackle" }),
                    ]) );
   SetListen( ([
                 "default" : "The water crashes loudly against "
                    "the shore.",
            ]) );
   SetSmell( ([
                "default" : "The smells of the ocean fill the "
                   "air.",
           ]) );
   SetExits( ([
                "south" : P_ROOM + "/wharfz",
           ]) );
  SetEnters( ([
      "building" : P_ROOM + "/sagehut",
    ]) );
}
