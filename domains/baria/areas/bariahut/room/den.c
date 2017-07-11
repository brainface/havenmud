//Alex@Haven
//2006
#include <lib.h>
#include "../area.h"
inherit LIB_ROOM;

static void create(){
  room::create();
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("a filthy den");
  SetLong(
    "The older part of the cellar seems to be someone's home. A straw "
    "mat to sleep on lies bunched in one corner that isn't occupied by "
    "pots, and the stench of a sweaty, dirty body is almost overpowering. "
    "The only escape from this unfortunate place is west."
  );
  SetItems( ([
  ({"pot", "pots"}) : "The pots are sticky, and they stink. Some "
    "hold dried sticky fruit, but almost everything is moldy.",
    ({"mat"}) : "The ancient mat smells like moldy straw and urine.",
  ]) );
  SetListen( ([
    "default" : "You hear footfalls and a slithering in the darkness.",
    ]) );
  SetSmell( ([
    "default" : "It smells like someone covered in orc dung died here.",
  ]) );
  SetInventory( ([
    AREA_OBJ + "kumquat" :2,
    AREA_NPC + "kikaramba" :1,
    AREA_NPC + "lizard" :1,
  ]) );
  SetExits( ([
    "west" : AREA_ROOM "cellar",
  ]) );
}
