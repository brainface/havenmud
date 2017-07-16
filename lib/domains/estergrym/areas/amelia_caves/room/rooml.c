// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a chilly passage");
   SetLong("The air is even colder here than in the nearby cavern, but "
           "the tunnel ends here.  The ground is dusty, but there is a trail "
           "leading through the dust from a a small hole in the "
           "southwestern corner of the room.");
   SetItems( ([
                ({ "tunnel end","tunnel" }) :
                   "The tunnel ends here, but opens up to the north.",
                ({ "nearby cavern","cavern" })  :
                   "The cavern is to the north.",
                ({ "dusty ground","ground" }) :
                   "A fine, powder-like dust covers the ground, except "
                   "in the southwestern corner.",
                ({ "cavern dust","dust" }) :
                   "The fine, powdery dust covers most of the tunnel.",
                ({ "southwestern corner","corner" }) :
                   "This dust-less corner has a hole heading downward.",
                ({ "southwest hole","hole" }) :
                   "The hole is fairly small, with rough, jagged "
                   "edges.",
                ({ "jagged edges","edges","edge","jagged edge","hole edge" }) :
                   "The edges of the hole are made of the same "
                   "dark rock that makes up the rest of the caves around "
                   "here.",
                ({ "cavern rock","dark rock","rock" }) :
                   "The rock is very solid."
           ]) );
   SetExits( ([
                "north" : C_ROOM + "roomk",
           ]) );
   SetEnters( ([
                 "hole" : C_ROOM + "roomq",
            ]) );
   SetInventory( ([
                    C_NPC + "spider" : 1,
                    C_NPC + "mouse" : 1,
               ]) );
}
