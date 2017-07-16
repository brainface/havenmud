#include <lib.h>
inherit LIB_POST_OFFICE;
#include "ditmar.h"

static void create() {
   post_office::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(20);
   SetShort("in the Ditmar Post Office");
   SetLong("This bland room is curiously unlike the rest of Ditmar; "
           "while the general set of polished stone to form walls "
           "remains the same, the furniture has not been carved from "
           "the stone and the products of wood are set about.  The "
           "room itself looks like an add-on to the rest of the "
           "town.");
   SetItems( ([
                 ({ "Ditmar Post Office","ditmar post office",
                    "post office","office","room","ditmar" }) :
                    (: GetLong :),
                 ({ "polished stone","stone","walls","wall" }) :
                    "The post office has walls made of polished stone, "
                    "free of stalagmites and stalactites, which aren't "
                    "even allowed as decorations on the edges of the "
                    "room.  The stone isn't even used to make the "
                    "furniture, as is usual in Ditmar.",
                 ({ "wood furniture","furniture","products","product",
                    "products of wood","product of wood","wood" }) :
                    "The furniture is plain and uninteresting, but it "
                    "is a change from the stone furniture found "
                    "in the rest of Ditmar.",
            ]) );
   SetItemAdjectives( ([
                         "post office" : ({ "bland","add-on" }),
                         "stone" : ({ "polished" }),
                         "furniture" : ({ "wooden","wood" }),
                    ]) );
   SetSmell( ([
                "default" : "The smell of the wood hangs heavy in the "
                   "air.",
           ]) );
   SetListen( ([
                 "default" : "The post office makes noises that its "
                    "trade alone makes as it sends mail out and takes "
                    "it in, waiting for the town citizens to recieve.",
            ]) );
   SetExits( ([
                "down" : D_ROOM + "/townhall",
           ]) );
}