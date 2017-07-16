#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("center of Grymxoria");
  SetLong(
    "Blood River road and Abyss lane intersect here in "
    "the central courtyard of the cathedral - town hall complex. "
    "The huge cathedral looms up to the north, and the town "
    "hall to the south. Both straddle the road with huge arches "
    "and are connected to each other with two skywalks. "
    "In the center of the huge courtyard is the Abyss. "
    "A huge pit, rumored to be bottomless. The Blood River "
    "flows in from the north and cascades over a waterfall "
    "down in to the Abyss. No sound of water hitting the "
    "bottom can be heard."
  );
  SetItems( ([
    ({ "hall", "town hall" }) : "A large stone block building "
    "similar in architecture to the church, but not quite as "
    "large.",
    ({ "cathedral", "church" }) : "The cathedral looms up "
    "above. Its tallest spire nearly touching the roof of "
    "the cavern. Colored patches of light can be seen "
    "shining eerily through the stained glass windows of "
    "the cathedral. Large stone gargoyles sit on ledges "
    "looking down on the road.",
    ({ "gargoyles" }) : "Large black stone gargoyles, their faces "
    "carved in grotesque and frightening expressions, watch "
    "over the cathedral. In the darkness it looks almost as "
    "if their eyes move to watch people passing beneath the "
    "arch.",
    ({ "river", "blood river", "Blood river" }) : "The blood river "
    "flows down the center of the divided two lane road. "
    "It gets its name from the reddish color of the water from "
    "the large amounts of iron and copper in it.",
    ({ "abyss", "pit", "bottomless pit" }) : "The abyss is a huge "
    "pit at the center of the courtyard of the cathedral of "
    "Aberach, which was built around the pit. The pure and "
    "holy Blood River flows into the pit, and although the "
    "usual sounds of water going over the waterfall can be "
    "heard, there is no sound of the water hitting bottom."
  ]) );
  SetListen( ([
    "default" : "There is a loud sound of rushing water"
  ]) );
  SetInventory( ([
    G_NPC + "citizen" : 2, 
    G_NPC + "equipper" : 1,
  ]) );
  SetExits( ([ 
    "north" : G_ROOM + "road11",
    "south" :  G_ROOM + "road21",
    "east" : G_ROOM + "road17",
    "west" : G_ROOM + "road15" 
  ]) );
}

