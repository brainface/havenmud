#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in the center of the Underland Market District");
  SetExits( ([
    "east" : UNDER_ROOM "shuttle",
    "west" : UNDER_ROOM "level2west",
    "north" : UNDER_ROOM "level2north",
    "south" : UNDER_ROOM "level2south",
    "up" : UNDER_ROOM "level1hub",
    "down" : UNDER_ROOM "sublvl1hub"
        ]) );
  SetSmell("The smells of sulfur and burnt oil stains the air.");
  SetListen("Blobbing lava and nearly silent clockwork fills your ears.");
  SetLong("The First Capital Bank of Floeholm stands to the south west of the square. "  
          "The walls of the cave are a solid black stone with a rippling texture. "
          "Large cogs spin in perfect time with their counterparts without "
          "so much as a click. Smoothly running bellows line the north wall with "
          "three deep rivulets of lava being channeled into the same building which "
          "does not have an apparent entrance. A large staircase of burnished bronze "
          "climbs up the lava tube to the levels above. To the east a frosty "
          "breeze tickles the sweat generated from the heat of the lava. "
    );
  SetItems( ([
    ({ "tube", "room", "stone", "basalt" }) : 
          "The walls were once a lava tube boring straight up through the crust. The "
          "tunnels in the cardinal directions have been cut meticulously "
          "into the side of the lava tube to expand the living structure that is "
          "Underland.",
    ({ "north building", "bellows", "bellow", "cogs", "cog" }) : 
          "Large bellows attached to the north building are run by a simple cog pulling "
          "the top handle and letting gravity drop it back down with it's counterweight "
          "speeding up the process and providing that bit of extra heat that is "
          "required to work the hardest of metals.",
    ({ "lava", "flow", "flows", "cascade", "channels", "channel" }) : 
          "The lava flows down long chutes from the level above seeming to create a "
          "waterfall of roiling lava that curves to a level rivulet in the floor. "
          "The lava falls into chutes at the end of each channel to an unknown "
          "location below. Huge wafts of heat ripple off the lava flows.",
    ({ "staircase", "ring", "gears", "pinion", "gear", "up" }) :
          "The staircase is a twisted mass of pinions and ring gears "
          "spinning nearly soundless as they transfer power to unknown machines. "
          "The staircase itself rises in a tight twist through the center of the ring "
          "gears, bearings and supports that silently bear the weight of the impressively "
          "large industrial center that plagues the center mass of Underland.",
    ({ "bank", "building" }) : 
            "The Underland branch of the The First Capital Bank of Floeholm "
            "It's entry way is a large Gothic arch that rises to a point "
            "where a cascade of lava flows to each side of the entrance to "
            "drop quickly into a chute on either side of the entryway. ",
    ]) );
  SetEnters( ([
    "bank" : UNDER_ROOM "bank",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : 2,
    ]) );
}
