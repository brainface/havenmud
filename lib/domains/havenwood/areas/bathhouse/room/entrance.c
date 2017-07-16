#include <lib.h>
#include "../bathhouse.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
 room::create();
 SetTown("Parva");
 SetClimate("indoors");
 SetAmbientLight(30);
 SetShort("wadlow's bathhouse and lounge");
 SetLong(
    "Dirt and grime is everywhere in this wooden building. "
    "The walls are covered in a thick grease like substance "
    "which gives the wood a nice soggy appearance. Off to the "
    "left is a small wooden counter and a picture of a woman "
    "in the nude. Directly west of the exit is a door which "
    "appears to lead into the changing room of this establishment."); 
 SetSmell( ([
    "default" : "Some awful rotten fish odor has been poorly "
    "masked by the smell of burning herbs."
  ]) );
 SetListen( ([
    "default" : "Through the door, other guests can be heard "
    "enjoying themselves."
  ]) );
 SetItems( ([
    ({ "picture", "woman" }) :
    "This picture looks as if it once would have been classy. The frame "
    "was painted a nice golden color, but has faded overtime to leave "
    "a slightly urine-stain hue on the wood. The picture itself is "
    "a painting of a beautiful woman lounging in the crystal clear "
    "water of a hotspring somewhere.",
    ({ "walls", "wall" }) :
    "The walls are a sordid affair which have been caked with layers "
    "of dirt and grim from years of use.",
    ({ "dirt", "grime" }) :
    "Perhaps an orc would consider collecting such a wealth of dirt "
    "and grime to use as a bath, but the more civilized people of "
    "Kailie would find this abundance of earth inside of a building "
    "rather revolting.",
    ({ "door" }) :
    "This door is the cleanest part of the establishment, made of a "
    "weak looking pine, the door seems like it would be easy to break "
    "if one was so inclined to such acts of vandalism.",
    ({ "counter" }) :
    "The wooden counter is off to the left and is far enough away "
    "from the wall for a large man to move comfortably behind it.",
  ]) );
 SetItemAdjectives( ([
    "counter" : ({ "wooden", "wood" }),
    "floor" : ({ "covered" }),
    "door" : ({ "west", "western", "pine", "weak" }),
    "walls" : ({ "greasy", "grease covered" }),
  ]) );
 SetInventory( ([
    BH_NPC + "wadlow" :1,
  ]) );
 SetExits( ([
    "out" : 	HAVENWOOD_TOWNS "parva/room/path5",
    "west" : BH_ROOM + "changingroom.c",
  ]) );
 }
