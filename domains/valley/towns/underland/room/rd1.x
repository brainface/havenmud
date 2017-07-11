/* A template room.  If you don't know why you'd need this
 * don't ask.
 */

// Torak 2013

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
  ::create();
  SetDomain("Valley");
  SetShort("foothill of Mount Trog");
  SetExits( ([
    "east" : UNDER_ROOM "road02",
    ]) );
  AddExit("west", UNDER_ROOM "gate", (: PreExit :) );
  SetSmell("An aroma of cooked food permeates the area.");
  SetListen("A cacophony of clamor emanates from the building to the south.");
  SetLong(
    "A large wall, slightly taller than ogre-height, lies to the west. "
    "The grassland of the valley is interupted here in the foothills of Mount Trog. "
    "There is a large stone building on the south side of the road. "
    "The road itself ends here, leading east to a little wooden door "
    "secured to the side of Mount Trog. The mountain is immense, rising "
    "up from the valley to scrape the sky. "
    );
  SetItems( ([
    ({ "wall" }) :
      "The wall is a stone beast that would be difficult to bash down.",
    ({ "mountain", "mount", "trog", "rock", "rocks", "surface" }) : 
      "Mount Trog rises up from the foothills and the valley to scrape the sky. "
      "The surface of the mountain is rocky and grey. ",
    ({ "grassland", "valley" }) : 
      "The valley lies to the west, beyond the wall.",
    ({ "building", "entrance", "sign", "clock", "hand", "hands", "face", 
                   "mug", "mugs", "beer", "beers", "post" }) : 
      "The large stone building to the south can be entered from here. "
      "A sign depicting a clock face with frosty mugs of beer at the ends "
      "of the minute and hour hands swings from a post stuck in the ground. ",
    ({ "door", "wood", "side", "knob" }) :
      "The road from the valley ends at a little wooden door secured tightly "
      "to the side of the mountain. The door has been painted a delightful green "
      "in contrast to the grey rocky surface of the mountain. A knob in the center "
      "appears to <open> it. The door is circular and leads into the mountain.",
    ({ "rocky" }) : "You try your best to look like a rock.",
    ({ "ground", "dirt" }) : "The ground is made of dirt.",
    ({ "foothill", "foothills", "road", }) :
      (: GetLong :)
    ]) );
  SetItemAdjectives( ([
    "wall" : ({ "large", "ogre-height", "stone" }),
    "mountain" : ({ "immense", "rocky", "grey", "mount" }),
    "building" : ({ "large", "stone" }),
    "road" : ({ "valley" }),
    "mug" : ({ "frosty" }),
    "door" : ({ "little", "wooden", "green", "circular" }),
    "knob" : ({ "door" }),
  ]) );
  SetEnters( ([
    "building" : UNDER_ROOM "tavern",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : 2,
    ]) );
}

int PreExit() {
  if (!userp(this_player())) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}
