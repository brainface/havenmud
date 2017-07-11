//Alex@Haven
//2006
#include <lib.h>
#include "../area.h"
inherit LIB_ROOM;

static void create(){
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("inside a small hut");
  SetLong(
    "This hut has a shallow roof thatched with jungle vines and "
    "a neatly swept dirt floor. The windows and door are open "
    "to let the breeze through the home. This room seems to be "
    "a common area, where a famliy might come together for "
    "eating or talking, but it is mostly bare excepting a small "
    "cooking fire and a crudely drawn painting on one wall. There "
    "is another room to the north and a small exit downward."
  );
  SetItems( ([
    ({ "painting" }) : "A crude sketch of a large jungle "
    "feline. It seems hardly worth gawking at.",
    ({ "fire" }) : "A smoky fire.",
    ({"roof", "vines"}) : "The vines are very sturdily strung together.",
  ]) );
  SetItemAdjectives( ([
    "painting" : ({ "crude"}),
    "fire" : ({ "cooking"}),
  ]) );
  SetListen( ([
    "default" : "The chirruping of birds coming from outside is drowned by "
    "raucous laughter from the north.",
    "fire" : "The embers crackle softly.",
  ]) );
  SetSmell( ([
    "default" : "It smells of smoke and unwashed bodies.",
  ]) );
  SetInventory( ([
    AREA_NPC + "kuchoka" :1,
    AREA_NPC + "mlima" :1,
  ]) );
  SetExits( ([
    "north" : AREA_ROOM "bedroom",
    "down" : AREA_ROOM "cellar",
    "out" : "/domains/baria/virtual/jungle/-6,-6",
  ]) );
}
