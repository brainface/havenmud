#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30+random(5));
   SetShort("inside the chapel");
   SetLong("Old, dried flowers hang on the walls all around "
           "the chapel, which is filled with rows upon rows of "
           "wooden benches.  An aisle leads down the center, up to "
           "a small set of steps leading to the altar.  Candles are set "
           "at the edge of each of the benches, but torches are the "
           "main source of light; all are spaced at even intervals along "
           "the stone walls.  A door leads out to the north.");
   SetItems( ([
                ({ "chapel altar","altar","small set of steps","steps",
                   "set of steps","step","set","small set" }) :
                   "The altar is off to the south, up a few steps.",
                ({ "rows of wooden benches","rows of benches","rows",
                   "row of wooden benches","row of benches","row",
                   "wooden benches","wooden bench","bench","benches",
                   "aisle","center","glowing candles","glowing candle",
                   "candle","candles","center aisle" }) :
                   "The benches are made of a surprisingly soft wood, "
                   "but are still benches and are still made of wood, so "
                   "they cannot be too comfortable.  At each end of "
                   "a bench is a candle; a softly pleasant scent like "
                   "roses and vanilla comes from them, but as they "
                   "are not lit, it isn't a strong one.Each bench is "
                   "matched with one "
                   "on the other side of the center aisle, which leads "
                   "up to the altar.",
                ({ "chapel" }) :
                   (: GetLong :),
                ({ "stone walls","stone wall","torches","torch","wall",
                   "walls","old dried flowers","old flowers",
                   "dried flowers","flowers","old dried flower",
                   "old flower","dried flower","flower" }) :
                   "Light is sprayed across the walls by the torches, "
                   "set in so that all the chapel might be illuminated.  "
                   "Flowers, richly dark and dried out as so to last "
                   "for an eternity, add a touch of color to the "
                   "still, gray colors of the stone walls.",
           ]) );
   SetSmell( ([
                "default" : "Sweet smells play around the chapel, coming "
                   "from the candles.",
                "candle" : "The candles give off a pleasant smell, much "
                   "like a soft, diluted vanilla and young roses.  It "
                   "is not a strong scent.",
           ]) );
   SetExits( ([
                "south" : VC_ROOM + "/altar_at",
                "north" : VC_ROOM + "/gen_12",
           ]) );
   SetInventory( ([
                    VC_NPC + "/prayer" : 2+random(4),
                    VC_NPC + "/guard_c" : 1,
               ]) );
}
