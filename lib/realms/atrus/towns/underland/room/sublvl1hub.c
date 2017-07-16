#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in the center of the Underland structural supports");
  SetExits( ([
    "up" : UNDER_ROOM "level2hub",
    "down" : UNDER_ROOM "sublvl2hub"
        ]) );
  SetSmell("The powerful stench of sulfur curls your nostril hairs.");
  SetListen("Loud steam release jets make your ears ring.");
  SetLong("The glossy walls are rough un-cut stone to which is bolted large iron "
          "supports that spiderwebs into the raising structure that is Underland. "
          "Grand pipes thrust through the framework and pierce the large bronze "
          "plate that doubles "
          "as pan that holds the stonework above and as a heat shield. Steel walkways "
          "and steep staircases offer the only route through this unwelcoming "
          "environment. At the bottom of this large circular chamber is another plate "
          "made of brass. "
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
    /*"bank" : UNDER_ROOM "bank",*/
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : 2,
    ]) );
}
