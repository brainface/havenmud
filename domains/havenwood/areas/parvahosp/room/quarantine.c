#include <lib.h>
#include "../ph.h"
inherit LIB_ROOM;

static void create() {
   ::create();
   SetDomain("Havenwood");
   SetClimate("indoors");
   SetAmbientLight(40);
   SetTown("Parva");
   SetShort("a quarantined area");
   SetLong("Signs clearly designate this as one of the quarantined areas of "
           "the hospital, harboring the diseases and contagious.  The furnishings "
           "and treatment of the area remains identical to upstairs, but "
           "staff and patients are only allowed to leave after a careful "
           "examination.  A ramp leads up to the rest of the hospital, "
           "while the quarantine continues to the west.");
   SetItems( ([
                ({ "quarantined area","area","quarantine","hospital" }) : (: GetLong :),
                ({ "quarantine signs","sign","signs" }) :
                   "Red paint was used to form pictures representing the "
                   "infectious nature of this area.",
                ({ "furnishings","furnishing","cots","cot" }) :
                   "The main furniture in this room is the cots, lined up in "
                   "rows, maintained in acceptable condition for the patients.",
                ({ "ramp" }) :
                   "The ramp is the only exit into the rest of the hospital.",
           ]) );
   SetItemAdjectives( ([
                         "sign" : ({ "red","quarantine" }),
                    ]) );
   SetListen( ([
                 "default" : "At all times, at least one patient is moaning for comfort.",
            ]) );
   SetSmell( ([
                "default" : "The stench of sick bodies and attempts at cleaning fills "
                            "the air.",
           ]) );
   SetExits( ([
                "up" : PR + "/room2",
                "west" : PR + "/quar2",
           ]) );
   SetInventory( ([
                    PN + "/doctor" : 2,
                    PN + "/diseased" : 6,
                    PN + "/janitor" : 1,
                    PN + "/sickdoc" : 1,
               ]) );
}
