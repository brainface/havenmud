#include <lib.h>
#include "../../parva.h"
inherit LIB_CHAPEL;

static void create() {
   chapel::create();
   SetTown("Parva");
   SetDomain("HavenWood");
   SetReligion("Eclat","Eclat");
   SetClimate("indoors");
   SetAmbientLight(40);
   SetShort("an Eclatish Temple");
   SetLong("Murals of spruce and pine trees growing in an "
           "abundant forest decorate the walls of this "
           "Eclatish Temple.  Green candles burn steadily, "
           "letting of smoke which is tunneled out through "
           "small smoke holes.  Still, a haze fills the area.  "
           "Benches and tables have been rearranged to make "
           "this place serve as a hospital of sorts.  A doorway "
           "leads out to the east.");
   SetItems( ([
                ({ "eastern doorway","doorway" }) :
                   "The doorway to the east leads out onto the "
                   "wharf.", 
                ({ "wall murals","murals","mural","walls","wall",
                   "trees","tree","forest" }) :
                   "A talented artist spent many hours painting "
                   "the details onto this wall.  The murals are "
                   "gorgeous and precise.  A forest full of spruce "
                   "and pine trees appears to grow right before "
                   "one's eyes.",
                ({ "Eclatish Temple","temple","hospital" }) :
                   (: GetLong :),
                ({ "burning candles","candles","candle" }) :
                   "Candles lines the walls, filling the room with "
                   "light.  They burn in a slighty green color, "
                   "and are green themselves.",
                ({ "smoke holes","holes","hole" }) :
                   "Small holes near the ceiling let the smoke "
                   "escape into the outside world.  The area around "
                   "them has a green-black tinge.",
                ({ "rearranged benches and tables","tables","table",
                   "benches","bench" }) :
                   "The benches and tables are set up to be used "
                   "as a make-shift hospital.  In their attempts to "
                   "bring Parva to the true faith, they have taken "
                   "on the sick citizens and worked at healing them.",
           ]) );
   SetItemAdjectives( ([
                         "doorway" : ({ "east" }),
                         "murals" : ({ "spruce","pine","tree",
                                       "trees","forest","abundant" }),
                         "temple" : ({ "clean","eclatish","eclat" }),
                         "candles" : ({ "green","burning",
                                        "smoking" }),
                         "holes" : ({ "small","smoke" }),
                         "benches" : ({ "rearranged","hospital" }),
                    ]) );
   SetListen( ([
                 "default" : "The hollaring and screaming outside "
                    "constrasts with the quiet murmur here.",
            ]) );
   SetSmell( ([
                "default" : "A pine scent fills the temple.",
                ({ "smoke","candles" }) : "They smell like spruce "
                   "and pine needles.",
           ]) );
   SetExits( ([
                "out" : P_ROOM + "/wharf0",
           ]) );
   SetInventory( ([
                    PS_NPC + "/eclatpriest" : 1,
                    PS_NPC + "/hurtcit" : 1,
               ]) );
}
