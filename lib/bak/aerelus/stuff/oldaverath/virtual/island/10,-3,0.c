// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("at the edge of a well-lit forest");
   SetProperty("coastal", 1);
   SetLong("Devil's clubs flourish in large patches, their prickly "
              "stalks discouraging touch.  Scattered around this area, "
              "silver birches stretch high to the sky, joined by oak "
              "trees and white mulberry trees.  The beach runs along "
              "to the north and south.");
   SetItems( ([
                ({ "well-lit forest","forest" }) : (: GetLong:),
                ({ "devil's clubs","clubs","club","devil's club" }) :
                   "The devil's clubs grow in clumps, with prickly tan "
                   "stalks rising out of the ground like miniature "
                   "trees, terminating in a canopy of green leaves with "
                   "clusters of red berries.",
                ({ "prickly tan stalks","stalks","stalk","thorns","thorn" }) :
                   "Thorns coat the stalks of the devil's clubs, as well as "
                   "the veins of their green leaves.",
                ({ "green leaves","leaves","leaf" }) :
                   "Just about everything has green leaves here.",
                ({ "silver birches","birch","birches","trees","tree" }) :
                   "The silver birches have a delicate, sylvan quality.",
                ({ "oak trees","trees","tree","oak","oak" }) :
                   "The oaks are stout and sturdy.",
                ({ "white mulberry trees","trees","tree","mulberries","mulberry" }) :
                   "Elegant and low, hanging below the other tree types, the "
                   "white mulberries grow all over this area.",
                ({ "beach" }) : "The rocky beach runs from the north to the south.",
                ({ "ocean","water","waves","wave" }) : "The ocean is made of water. It is "
                   "to the east.",
           ]) );
   SetItemAdjectives( ([
                         "stalks" : ({ "prickly","tan" }),
                         "leaves" : ({ "green" }),
                         "birches" : ({ "silver","birch" }),
                         "mulberry" : ({ "white","mulberry" }),
                         "oak" : ({ "oak" }),
                         "beach" : ({ "rocky" }),
                    ]) );
   SetSmell( ([
                "default" : "The scent of ocean fills the air.",
                "ocean" : "The ocean has a salty scent.",
           ]) );
   SetListen( ([
                 "default" : "The ocean roars.",
                 "ocean" : "Waves crash against the rocky beach.",
            ]) );
   SetInventory( ([
                    FOREST_NPC + "hunter" : 1,
                    FOREST_NPC + "seagull" : 3,
               ]) );
   SetExits( ([
                "north" : AVERATH_ISLAND + "10,-2,0",
                "south" : AVERATH_ISLAND + "10,-4,0",
                "west" : AVERATH_ISLAND + "9,-3,0",
                "east" : INNERSEA_VIRTUAL "ocean/11,-108",
           ]) );
}
