#include <lib.h>
#include <std.h>
#include "../store.h"

inherit LIB_ROOM;

static void create() {
   room::create();   
   SetShort("Tornys' Leather Emporium");
   SetClimate("indoors");
   SetAmbientLight(30);
   SetExits( ([
     "out" : LSTORE_EXIT,
     "south" : LSTORE_ROOM "craft_hub"
   ]) );
   SetLong(
     "This little store belongs to Tornys, a renowned leather dealer. His "
     "products are generally well known for being of decent quality, and "
     "this store is popular especially among the inhabitants of Haven town "
     "and the surrounding area. There is a wooden counter near the door, "
     "where customers may enquire about making a purchase."     
   );   
   SetItems( ([
     ({ "building", "store" }) : (: GetLong :),
     ({ "counter" }) : "This wooden counter is bare, and acts as point of "
     	"sale for the store.",     
   ]) );
   SetItemAdjectives( ([
     "store" : ({ "little" }),
     "counter" : ({ "wooden" }),      
   ]) );   
   SetInventory( ([ 
      LSTORE_NPC + "tornys" : 1,
      LSTORE_NPC + "odele" : 1,
      STD_OBJ "lootchest" : 1,
   ]) );
   SetProperties( ([
      "natural working" : 1,
      "wood working" : 1,
      "leather working" : 1,
      "textile working" : 1,
   ]) );
   SetSmell( ([
     "default" : "The smell of freshly cured leather hangs in the air.",
  ]) );
}
