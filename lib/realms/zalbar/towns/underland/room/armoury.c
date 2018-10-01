#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : "level2north",
    "south" : "innerforge",
    "east" : "tinkers",
    "north" : "crafters",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(60);
  SetShort("inside the Underland Weapons Forge");
  SetLong("The gnomish forge is a grand hall with three large rivulets of "
          "lava feeding a gaping maw of the mithril forge to the south. "
          "Each workstation is touch by rivulets of lava run along the walls. "
          "A small counter with a moneybox is carved out of stone "
          "near the north side of the building. The workspaces around each "
          "anvil are well kept and the anvils glean with newness. There is "
          "ample room for most sized creatures to work in the cavernous "
          "hall. The banded and arched ceiling is well tended to avoid "
          "discoloration. Large pillars are in each corner of the room."
          );
  SetItems( ([
    ({ "forge" }) :
          "It is a small room filled with molten lava that is heating metal. ",
    ({ "walls", "wall" }) : 
          "The walls are carved out of the rock of the mountain above. They "
          "are basalt black and brightly polished. The torchlight flickers "
          "brightly off the polished walls.",
    ({ "pillar", "pillars", "bands", "brass", "tools", "tools of trade" }) :
          "The pillars are brightly polished marble of white and grey giving "
          "a stark contrast to the basalt walls. Each pillar is rounded at the "
          "bottom, middle and top by large brass bands. On each band hangs "
          "tools of the various trades.",
    ({ "ceiling", "buttresses", "buttress" }) :
          "The ceiling is buttressed with large iron bands that anchor "
          "into the pillars at each corner of the room.",
    ({ "rivulets", "rivulet", "lava", "workstations", "workstation",
       "pools", "pool", }) : 
          "The rivulets of lava run along the walls in troughs deep enough "
          "to submerge the pieces being worked on from the large to the "
          "small. Large pools of water are constantly fed by pipes "
          "running in along each wall which help to cool the working "
          "environment.",
    ({ "anvil", "anvils" }) :
          "Each anvil is sized according to what kind of armour is being "
          "forged, small for the small, through the large for the large.",
    ({ "counter", "moneybox" }) :
          "A small counter has been carved out of solid basalt with a large "
          "brass locking mechanism that looks like it could be picked.", 
          ]) );

  SetInventory( ([
   /* UNDER_NPC "smith" : 1,
    UNDER_NPC "cra_skills" : 1,
    UNDER_NPC "beginner_rec" : 1,
    UNDER_NPC "novice_rec" : 1, */
    UNDER_NPC "armourer" : 1,
    ]) );
}
