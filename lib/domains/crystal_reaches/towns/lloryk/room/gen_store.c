#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Shire Commissary");
  SetClimate("indoors");
  SetExits( ([ 
    "out" : LLORYK + "room/uh3",
     ]) );
  SetAmbientLight(50);
  SetInventory( ([
    LLORYK + "npc/norscha" : 1,
    LLORYK + "npc/helper"  : 1,
    ]) );
  SetLong("The Commissary is a small warehouse fairly bursting with the "
          "goods of the village. When a product is finished, the residents "
          "transport it here for distribution to the other residents of the "
          "town. Around the hall are various counters, shelves, and storage "
          "areas for all types of products.  The floor is dirty and dusty "
          "from the amount of traffic this hall receives."
          );
  SetSmell( ([
    "default" : "Smells of various forms of farm product hang heavy in the air.",
    ]) );
  SetListen( ([
    "default" : "The hall always seems to have the echo of a recent citizen.",
    ]) );
  SetItems( ([ 
    ({ "goods", "product", "products" }) : 
    "The goods of the village are set aside in various piles.",
    ({ "pile", "piles" }) : "The piles are sorted according to product type.",
    ({ "counter", "counters", "shelf", "shelves", "area", "areas" }) : 
              "The counters, shelves, and storage areas fairly burst with products.",
    ({ "floor", }) : "The floor is covered in tracked dirt and dust.",
    ({ "dirt", "dust" }) : "The dust and dirt lightly cover the floor.",
    ]) );            
  SetItemAdjectives( ([
    "area" : ({ "storage" }),
    "dirt" : ({ "tracked", }),
    ]) );
}

