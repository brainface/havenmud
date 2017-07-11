#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetClimate("indoors");
   SetAmbientLight(35);
   SetShort("inside the Parva Bank");
   SetDomain("HavenWood");
   SetLong("A large metal box with a complicated magic seal is "
           "the centerpiece of this shack.  The Parva Bank "
           "is little more than a few boards nailed together with a "
           "few more thrown across as the roof, but the money "
           "should remain secure.  An opening in the building "
           "to the south leads out.");
   SetItems( ([
                ({ "Parva Bank","bank","building","shack",
                   "boards","board","roof" }) :
                   (: GetLong :),
                ({ "large metal box","box" }) :
                   "The large metal box in the center of the room "
                   "holds all of funds of Parva Bank.  A magic "
                   "seal keeps it closed, and only the banker "
                   "knows the spell to open it.",
                ({ "magic seal","seal" }) :
                   "The magic seal glows a faint blue around the "
                   "metal box.",
           ]) );
   SetItemAdjectives( ([
                         "box" : ({ "metal","large" }),
                         "bank" : ({ "parva" }),
                    ]) );
   SetSmell( ([
                "default" : "The room smells dusty and woody.",
           ]) );
   SetListen( ([
                 "default" : "Scuffling noises come from outside.",
            ]) );
   SetExits( ([
                "out" : P_ROOM + "/path1",
           ]) );
   SetInventory( ([
                 P_NPC + "/banker" : 1,
             ]) );
}
