#include <lib.h>
#include "../outpost.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("on top of the watch tower");
  SetLong(
    "The panorama provided from the height of this tower provides a good "
    "view of the ruins of Durgoroth to the north, which looks quiet and "
    "dead. The view south shows the Durgoroth road leading away from the "
    "outpost. Surrounding the camp below, a tall palisade protects the "
    "outpost from the invaders of the ruins. In the floor, a trap door, "
    "which is open, leads back into the warmth and protection of the "
    "tower. The wooden battlements are tall enough to protect an average "
    "human standing on top of the tower watching for daemons to escape "
    "the ruins.");
  SetAmbientLight(5);
  SetClimate("sub-arctic");
  SetItems( ([
    "tower" : ( :GetLong: ),
    ({"ruins","ruin","Durgoroth"}) :
    "The ruins of Durgoroth can be seen in the north.",
    ({"road","roads"}):
    "Leaving the outpost, the Durgoroth road heads south.",
    ({"below","camp","outpost"}) :
    "Sitting below the watch tower, the outpost is protected by a tall "
    "wooden palisade.",
    "palisade" :
    "The outpost is surrounded and protected by a tall wooden palisade.",
    ({"floor","door","trap","trapdoor"}) :
    "The wooden floor is slick with frost and has a trap door that leads "
    "back down into the warmth and protection of the tower.",
    ({"battlement","battlements"}) :
    "The wooden battlements give ample protection to anyone standing "
    "watch.",
    ]) );
  SetItemAdjectives(( [
    "road"        : ({"durgororth"}),
    "palisade"    : ({"tall","wooden","surrounding"}),
    "door"        : ({"trap"}),
    "battlements" : ({"wooden","tall","protective"}),  
    ]) );
  SetExits( ([
    "down" : OP_ROOM + "watch_tower1",
    ]) );
  SetSmell( ([
    "default" : "The air smells clean and crisp.",
    ]) );
  SetListen( ([
    "default" : 
    "The sound of hammering can be heard in the distance."
    ]) );
  SetInventory( ([
    OP_NPC + "dwarf_worker"  : 1,
    OP_NPC + "dwarf_paladin" : 1,
    ]) );
}