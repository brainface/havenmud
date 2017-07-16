/*pirate galleon
  Zara 8/6/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a pirate galleon");
  SetClimate("temperate");
  SetAmbientLight(50);
  SetExits( ([
        "east" : ACOVE_ROOMS + "cove12",
        "down" : ACOVE_ROOMS + "cove15",
       "up" : ACOVE_ROOMS + "cove8",
       ]) );
  SetLong("The feeling of pure evil is palpable here. "
         "This cabin is below the main deck. "
          "Pale, swirling mists cross the deck, forming "
          "bony fingers that reach toward the unwary "
          "traveller. A mucousy substance pools on the "
          "rails, sliding downwards to collect on the deck. "
          "A trapdoor in the center is tightly closed "
          "against intruders, but from the cracks a "
          "greenish glow escapes.");
  SetItems( ([
    ({"cabin","here","ship","galleon"}) : (: GetLong:),
       ({ "mist", "mists" }) : "These mists are cold and opaque.",
      "substance" : "This substance is thick and viscous.",
     ({"trap door","trapdoor"}) : "This old wooden trapdoor has a heavy "
                   "iron ring in it's center. It is very "
                   "tightly closed.",
    ({"ring","iron ring"}) : "This ring is rusted and old.",
     ({ "small spaces", "spaces", "space", "crack", "cracks" }) : 
        "These are the small spaces between the boards "
        "on the trapdoor.",
     "glow" : "This glow is an iridescent green color.",
     "deck" : "The deck is made up of golden oak planks.",
              ]) );
  SetItemAdjectives( ([
     "mist" : ({"opaque","cold"}),
    "trapdoor" : ({"old","wooden"}),
     "planks" : "oak",
           ]) );
  SetListen ( ([
       "default" : "A cacophany of moans and wails seem "
                   "to come from deep within the bowels "
                  "of the ship.",
            ]) );
  SetInventory( ([
   ACOVE_NPC + "firstmate" : 1,
    ]) );
}
