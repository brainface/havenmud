
#include <lib.h>
#include "../path.h"
#include <domains.h>

#define LLORYK_ROAD "/domains/crystal_reaches/towns/lloryk/room/hb3"



inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("Bilgan's Emporium");
  SetLong(
          "The square room has been painted with a brown theme. "
          "A plush bronze-colored carpet lines the floor which "
          "a wooden counter and a few shelves rest on. A bright "
          "white orb resting on the auburn painted ceiling glows "
          "brightly. An oak doorway leads to the lounge where "
          "customers can discuss their products. An open doorway "
          "leads back out back into the village. Boxes lining the "
          "shelves are filled with tobacco products. A simple "
          "lounge is through the doorway to the west.");

  SetExits( ([
    "out"  : LLORYK_ROAD,
    "west" : LLORYK "room/smokeshop02",   
    ]) );
  SetAmbientLight(30);
  SetSmell( ([
    "default" : "It smells strong of raw tobacco.",
     ]) );
  SetListen( ([
    "default" : "The village bustles outside.",
     ]) );
  SetInventory(([ 
    LLORYK "npc/bilgan" : 1,
    ]));
  SetItems( ([
     "shop"    : "The shop has one generic theme, brown. Everything "
                 "has either been a painted brown color, or it is "
                 "wooden.",
     "room"    : "It is square room with an auburn painted ceiling, "
                 "a bronze carpet with a few shelves on it, a "
                 "counter and two doorways.",
     "shelf"   : "It is freshly stocked with fresh boxes of different "
                 "types of cigars.",
     "shelves" : "The shelves hold boxes of tobacco products on them "
                 "displaying them slightly at an angle.",
    ({ "walls","wall" })    : "The walls are painted the same "
                 "an auburn to match "
                 "the ceiling and bronze to match the carpet.",
     "tobacco" : "Tobacco products line the shelves.",
     "products": "Boxes of tobacco products line the shelves.",
    ({ "carpet", "bronze carpet" }) : "A bronze carpet lines this "
                  "shop wall to wall.",
    ({ "orb","bright orb","bright white orb" }) : "A bright orb "
                  "rests on the ceiling, it illuminates the shop "
                  "to see anytime of the day.",
    ({ "ceiling", "painted ceiling" }) : "The ceiling is flat and "
                  "plain. It has been painted an auburn color.",
    ({ "doorway", "open doorway" }) : "There are two open doorways, "
                  "one to the south and another to the west.",
    ({ "doorways", "open doorways" }) : "The doorway to the west "
                  "leads into a lounge where customers can rest. "
                  "The south doorway leads back into Lloryk.",
    ({ "boxes", "cigar boxes" }) : "Cigar boxes line the three "
                  "shelves completely without a bare space on them. "
                  "They vary in brand on the sizes of the box and "
                  "quality.",
    ({ "counter", "wooden counter" }) : "A counter built entirely of "
                  "oak wood has been placed near the north wall to "
                  "display many goods.",
    ]) );
}
