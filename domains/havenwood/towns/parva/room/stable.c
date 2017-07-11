#include <lib.h>
#include <domains.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetExits( ([
    "out" : PARVA_ROOM "path5",
    ]) );
  SetShort("a smelly stable in Parva");
  SetLong(
    "This building is old and decrepid. The walls have huge"
    " holes and cracks in the wood, most of which have been"
    " stuffed with straw to keep the cool air out at night time."
    " Stalls line the wall in the back, the housing for the"
    " donkeys and other pack animals stored here."
  );
  SetItems( ([
    ({ "walls", "straw" }) : "The walls are old and decrepid and the holes and"
                             " cracks have been filed with straw to help fight"
                             " off the cool night air..",
    ({ "stall", "housing" }) : "The back of the stable is lined with stalls"
                               " that provide housing for the donkeys and other"
                               " pack animals.",
    ]) );
  SetSmell("The overpowering stench of donkey dung lingers.");
  SetInventory( ([
      PARVA_NPC "donkey_seller" : 1,
    ]) );
}
