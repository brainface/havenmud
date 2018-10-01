#include <lib.h>
#include "../defs.h"
#include "/domains/averath/towns/averath/averath.h"
#include <domains.h>

inherit LIB_ROOM;


static void create() {
  room::create();
  SetClimate("indoors");
  SetObviousExits("out");
  SetShort("the averath tobacco emporium");
  SetLong(
          "The room welcomes all who enter with a dark-green carpet which "
          "is the exact size of the doorway. A barrel full of pipes rests "
          "in the northeast corner next to a sink with utensils resting on the "
          "rim. A wooden counter wraps around the west and north walls full "
          "of cigar boxes. A sign against the north wall displays a list "
          "of goods for sale. This shop is neat and orderly with everything "
          "in its place. A simple clock hangs from the "
          "north wall displaying the time for any who wish to see it.");

  SetExits( ([
            "out"  : AVERATH_ROOM "market",
           ]) );
  SetRadiantLight(60);
  SetSmell( ([
            "default" : "a soft smell of raw and smoked tobacco lingers.",
           ]) );
  SetListen( ([
            "default" : "The sounds of the city can still be heard.",
           ]) );
  SetInventory(([ 
                  SHOP_NPC "frederick" : 1,
                  SHOP_OBJ "clock"     : 1,
              ]));
  SetItems( ([
     "barrel"    : "A barrel rests in the emporium filled to the "
                   "brim with used pipes. It is next to a sink which "
                   "has utensils resting on the rim of it.",
     "sink"      : "A simple sink has been mounted to the east wall "
                   "with a rather plain drain which leads back into "
                   "the wall.",
     "drain"     : "The drain is a plain ring with a silver metal banding "
                   "which leads back into the wall.",
     "utensils"  : "Two utensils rest on the rim of the sink. They "
                   "are a brush and a filter.",
     "brush"     : "A wire brush rests on the sink, with tobacco "
                   "pipe residue caked on it.",
     "filter"    : "A filter rests on the rim of the sink, and "
                   "is made of a red cedar wood. It is a simple "
                   "pipe filter.",
     "ceiling"   : "The ceiling has been painted white.",
     "tobacco"   : "Tobacco products line the counter to the west.",
     "products"  : "The products rest on the west counter.",
     "sign"      : "A wooden sign resting underneath the clock has "
                   "a listing burned into the wood. It is possible to "
                   "read it.",
     ({ "walls", "wall" }) :
                   "The walls have been painted white, and the north "
                   "wall has a clock hanging on it.",
    ({ "carpet", "green carpet", "dark green carpet" }) : "This "
                   "carpet has been cut into a small square. It "
                   "currently lines the south doorway.",
    ({ "pipes","used pipes" }) : "Used pipes rest in a barrel "
                   "in the northeast corner. "
                   "It appears customers return the used pipes "
                   "for cleaning.",
    ({ "ground","floor" }) : "The ground is a glossy "
                   "hardwood floor.",
    ({ "doorway", "open doorway" }) : "An open doorway rests in the "
                   "wall to the south and leads back into Averath.",
    ({ "boxes", "cigar boxes" }) : "Cigar boxes rest on the west side "
                   "of the counter. Quite a selection is displayed.",
    ({ "counter", "wooden counter" }) : "The wooden counter forms the "
                   "shape of a carpenter's ruler. It borders the west "
                   "wall, and wraps eastward to where the merchant is "
                   "supposed to stand.",
              ]) );
  
   SetRead( ([
      "sign" : "    The sign lists all of the Tobacco Emporium's Wares...\n\n"
               "     |------------------------------------------------|\n"
               "     |                  -=CIGARS=-                    |\n"
               "     | The \"Averan\" :                                 |\n"
               "     |   Made and founded here at the Emporium. A     |\n"
               "     |   mild blend of tobacco for any to enjoy. Our  |\n"
               "     |   finest cigar.                                |\n"
               "     |                            - 30 Ducats         |\n"
               "     | Our special blended cigar :                    |\n"
               "     |   Another fine creation by Frederick, said     |\n"
               "     |   to even please the Duke of Averath himself   |\n"
               "     |   on occasion! Our second best seller.         |\n"
               "     |                            - 25 Ducats         |\n"
               "     | A fine cigar :                                 |\n"
               "     |   An instant classic for first time buyers.    |\n"
               "     |                            -  4 Ducats         |\n"
               "     |                  -=PIPES=-                     |\n"
               "     | A hand made wooden pipe :                      |\n"
               "     |   Hand carved by the craftsmen inside the      |\n"
               "     |   Emporium, this is a fine pipe to smoke from! |\n"
               "     |                            -100 Ducats         |\n"
               "     | A cheap corn cob pipe :                        |\n"
               "     |   A quick disposable pipe which is a perfect   |\n"
               "     |   gift for any sailor!                         |\n"
               "     |                            - 80 Ducats         |\n"
               "     |                  -=COFFEE=-                    |\n"
               "     | Averan coffee :                                |\n"
               "     |   A fine cup of coffee to drink while you      |\n"
               "     |   make your selection.                         |\n"
               "     |                            - 14 Ducats         |\n"
               "     |                                                |\n"
               "     |         -Frederick, owner of the Emporium      |\n"
               "     |________________________________________________|",
           ]) );

  }
