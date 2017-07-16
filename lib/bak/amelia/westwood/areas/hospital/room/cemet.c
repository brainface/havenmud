#include <lib.h>
inherit LIB_ROOM;
#include "../hospital.h"

static void create() {
   room::create();
   SetShort("hospital cemetery");
   SetDomain("WestWood");
   SetLong("Even the best of doctors sometimes loses a patient, and "
           "in this cemetery, there are many unnamed gravestones "
           "marking the results of such unavoidable failures.  "
           "Some of them have races or names or even religions of "
           "the occupants below, under the ground, written on them.  "
           "A door leads back inside the hopsital.");
   SetItems( ([
                ({ "hospital cemetery","cemetery" }) :
                   (: GetLong :),
                ({ "eclat hospital","hospital" }) :
                   "The hospital is off to the east, not far away.  "
                   "A plain white door leads back inside the hospital "
                   "that can be reached from here.",
                ({ "unnamed gravestones","stone","stones",
                   "gravestones","gravestone","grave","graves" }) :
                   "The gravestones are plain, just marking the "
                   "presence of something below, and not identifying "

                   "them.  A few are listed as of a certain race or "
                   "religion, and some patients even gave them names "
                   "before passing on, but most are blank.",
           ]) );
   SetItemAdjectives( ([
                         "unnamed gravestones" : ({ "unnamed","plain" }),
                    ]) );
   SetSmell( ([
                "default" : "The air is fresh and clean.",
           ]) );
   SetListen( ([
                 "default" : "Some animal noises come from the distance, "
                    "but some cries from the sick come from the "
                    "hospital.",
            ]) );
   SetEnters( ([
                 "hospital" : H_ROOM + "r1",
            ]) );
   SetDoor("hospital",H_ROOM + "door");
   SetObviousExits("enter hospital");
}
