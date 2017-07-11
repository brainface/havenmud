#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("along Heroes Lane in Lloryk");
  SetExits( ([
     "east" : LLORYK + "room/hb4",
     "west" : LLORYK + "room/hb2",
     ]) );
  SetLong("Heroes Lane continues on to the east and west from here. To "
          "the east the road meets up with a smaller path to form a \"T\" "
          "intersection. Off to the west, the road heads towards the Gwonish "
          "swamp, a land of ancient evil. The rolling hills of the Shire "
          "spread out in all directions from here, and far off to the east "
          "the Crystal Reaches rise into the sky. A small, cozy-looking building "
          "sits by the roadside here."
          );
  SetItems( ([
    ({ "hill", "hills" }) : "The rolling hills of the Shire make for excellent "
                            "farmland.",
    ({ "reaches", "mountains", "mountain" }) : "The Crystal Reaches are a large "
                            "mountain range that rises into the sky.",
    ({ "building", "emporium" }) : "This cozy building is Bilgan's Emporium.",
    ]) );
  SetItemAdjectives( ([
    "hill"    : ({ "rolling", }),
    "reaches" : ({ "crystal", }),
    "building": ({ "bilgan's", "bilgan", "small", "cozy", "looking" }),
    ]) ); 
  SetListen( ([
    "default" : "The occasional moo or bleat of a farm animal livens the quiet Shire.",
    ]) );
  SetSmell( ([
    "default" : "Often unpleasant, the smells of farm life are nonetheless calming.",
    ]) );
  SetEnters( ([
    "building" : LLORYK "room/smokeshop01",
    ]) );
}
