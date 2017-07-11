/*captain's cabin
 Zara 8/7/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("captain's cabin");
  SetAmbientLight(50);
  SetClimate("temperate");
  SetExits( ([
     "up" : ACOVE_ROOMS + "cove13",

     ]) );
  SetLong("This cabin looks much as it did in its prime. "
          "Oak paneling covers the walls. The captain's "
          "desk sits on one side. On it, there is a "
          "brandy decanter and two glasses - as if the "
          "occupant is expecting guests. All normalcy "
          "ends there, however. This room is the source "
          "of the eerie green light. The air is frigid "
          "and copious amounts of slime cover every "
         "surface.");
  SetItems( ([
       ({ "cabin","room" }) : "This small cabin belongs to the "
                              "captain of the ship.",
      ({ "panel","paneling","wall","walls" }) : "The walls are "
                                                 "covered with "
                                                 "oak paneling.",
      "desk" : "The captains oak desk is in remarkable "
               "condition.",
      "decanter" : "This crystal brandy decanter is very old "
                   "and still contains brandy.",
      ({ "glass","glasses" }) : "These brandy snifters appear "
                                "to be very old.",
      "light" : "This eerie green light fills the cabin with "
               "no apparent source.",
      "slime" : "This is the same slimy substance found above "
                "on the deck.",
       ({ "ship","galleon"}) : (: GetLong :),
              ]) );
  SetItemAdjectives( ([
    "decanter" : ({"brandy","crystal","old"}),
    "desk" : "oak",
    "snifters" : ({"brandy","old"}),
         ]) );
  SetSmell( ([
     "default" : "The total lack of smell of any kind here "
                 "is unnerving.",
         ]) );
  SetListen( ([
     "default" : "Soft moans of misery fill the room.",
         ]) );
  SetInventory( ([
      ACOVE_NPC + "captain" : 1,
      ]) );
}
