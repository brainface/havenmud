//
// Summary: a trading hut
//     KYla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 10/21/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create(){
  room::create();
  SetShort("inside a small hut");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("This hut appears to be a shop of some sort. Many leather goods "
          "litter the shelves and the walls. There are pieces of armour "
          "and weapons carefully organized by materials stored inside "
          "display cabinets. It seems as if one could find just about "
          "anything in this shop."
         );
  SetTown("Baria");
  SetItems( ([
              ({"good", "goods"}) : "These leather goods are finely "
                                    "crafted, and look as though they "
                                    "could last a while.",
              ({"shelves","shelf"}) : "Several shelves hold many "
                                      "leather goods.",
              ({"walls","wall"}) : "Some of the shop's goods hang "
                                   "from the walls of the hut.",
              ({"pieces of armour","weapons",
                "weapon","armours","armour"}) : "Different types of "
                                                "armours and weapons "
                                                "are carefully stored "
                                                "as exhibition.",
              ({"cabinets","display cabinets","cabinet",
                "display cabinet"}) : "These crystal cabinets store "
                                      "some of the wares owned by "
                                      "the shopkeeper." 
          ]) );
  SetItemAdjectives( ([
                       "goods" : ({"leather"}),
                       "cabinets" : ({"crystals"})
                   ]) );
  SetInventory( ([
                  BARIA_NPC + "carian" : 1,
              ]) );
  SetExits( ([
              "out" : BARIA_ROOM + "path4",
          ]) );
  SetSmell( ([ "default" : "The strong scent of leather fills the "
                           "place." ]) );
  SetListen( ([ "default" : "The sound of a stone sharpening a blade "
                            "is heard." ]) );
}

