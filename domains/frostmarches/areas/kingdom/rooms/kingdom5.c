
/* a room in the kingdom
   Elasandria 4/15/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a workroom");
  SetClimate("indoors");
  SetAmbientLight(45);
  SetLong(
    "A high domed ceiling makes the room seem very large. A still pool "
    "of incandescent water lies in the center of the workroom. A "
    "variety of candles litter table tops and bookshelves, casting a "
    "pleasant glow around the room."
  );
  SetItems( ([
    ({"pool","water"}) : "This pool looks to be some kind of scrying "
      "device used to peer into the future. It remains blank and empty.",
    ({"room","workroom"}) : "This workroom is quite cozy and contains "
      "many magical tools.",
    ({"candle","candles"}) : "Over a dozen candles of various colors "
      "and sizes have been carefully placed around the room.",
    ({"tables","table","top","tops","bookshelf","bookshelves"}) : 
      "The room is lined with a mutltitude of beautifully carved "
      "tables and bookshelves.",
    ({"book","books"}) : "There are many old leather bound books that "
      "appear to have seen much use.",
    "ceiling" : "The ceiling is very high and gives the room a roomy feel.",
    ({"glow","light"}) : "The warmth of the light cast by the candles "
      "is very soothing.",
    ({"tool","tools"}) : "The pool, candles and books are all magical tools.",
  ]) );
  SetSmell( ([
    "default" : "A heady perfume of candles and magic clings to the room.",
  ]) );
  SetListen( ([
    "default" : "It is quiet.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "enchanter" : 1,
  ]) );
  SetExits( ([
    "out" : KINGDOM_ROOMS + "kingdom10",
  ]) );
}
