#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(20);
    SetClimate("underground");
    SetShort("an ogre's chamber");
    SetLong("This is a relatively dry twenty by twenty chamber.  There is "
            "a stone "
            "cove cut out of the wall, it is filled with straw, "
            "apparently some sort of bedding.  A small fire lights "
            "the majority of this room, as well a providing a little "
            "heat.  There is assorted trash all throughout this chamber. "
            "There is a passage leading off to the east.");
    SetItems( ([
      ({"dry", "chamber", "room", "dry cave", "warm cave"}) :
        "This chamber is relativly dry and somewhat warmer than the rest "
          "of the cave.",
      ({"cove", "wall", "stone cove"}) :
        "This is a small cove cut into a wall with poorly made bedding on "
        "it.",
      ({"straw", "bedding"}) :
        "The bedding is composed of dry straw.",
      ({"trash", "articles", "floor"}) :
        "There are useless and broken articles on the floor.",
      ({"stone"}) :
        "This is a soft grey stone, easily worn by chisel or "
        "water.",
      ({"fire", "lights", "heat", "small smoldering fire", "small fire",
        "smoldering fire"}) :
        "There is a small, smoldering fire in this room, providing a "
        "little heat and light.",
      "passage" :
        "There is a small passage that leads east.",
            ]) );
    SetListen( ([
      "default" :
        "The sound of dripping water can be heard in the distance, as "
        "well as the occasional pop from the nearby fire.",
             ]) );
    SetSmell( ([
      "default" :
        "An ogrish stench fills this room.",
            ]) );
    SetExits( ([
      "east" : CAVES_ROOM + "cavet",
            ]) );
    SetInventory( ([
      CAVES_NPC + "ogre" : 1,
                ]) );
}
