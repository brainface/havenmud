#include <lib.h>
#include <domains.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the northern gate of the Shire");
  SetLong("An opening in a short wooden fence is all that marks the gate to "
          "the Shire. Off to the south, the road leads into the heart of "
          "the village. The road continues to the north, becoming the "
          "Glimmerdin Road that travels off to the Dwarven homeland. "
          "Off to the southwest, the rolling hills of the Shire display "
          "a warmth that exudes friendliness.");
  SetItems( ([ 
    "gate"  : "The 'gate' is not much more than a few wooden planks "
              "swinging in the opening in the short wooden fence.",
    "fence" : "The fence looks to have been built more to keep "
              "small children and animals in than anything else out.",
    "road" : "The road is of excellent workmanship, in contrast to the "
             "rough appearance of most of the region. However, grass and "
             "small weeds are starting to grow over parts of it.",
    ({"grass","weeds"}) : "Small tufts of grass and weeds poke "
                          "their way through the surface of the road.",
    ({ "hill", "hills" }) : "The rolling hills of the Shire make excellent "
                            "farmland.",
    ]) );
  SetItemAdjectives( ([
    "fence" : ({ "short", "wooden", }),
    "hill"  : ({ "rolling" }),
    ]) );
  SetSmell( ([
    "default" : "The smells of farm fertilizers eminate from the village.",
    ]) );
  SetListen( ([
    "default" : "Off in the distance, the sounds of village life can be heard.",
    ]) );
  SetInventory( ([
    LLORYK + "npc/guard": 2,
    ]) );
  SetExits( ([
    "south" : LLORYK + "room/uh1",
    "north" : CRYSTAL_REACHES_VIRTUAL "glimmerdinroad/0,1",
     ]) );
}

