
/* A room in the kingdom
   Elasandria 4/13/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the grand hall");
  SetClimate("indoors");
  SetAmbientLight(45);
  SetLong(
    "This room is quite spacious and plushly decorated. A large "
    "chandelier of incandescent drops of dew and small glowing orbs "
    "hangs from the center of the high, domed ceiling. The floor is "
    "covered by smooth stone, which is perfect for dancing on."
  );
  SetItems( ([
    ({"high ceiling","ceiling"}) : "The ceiling is grandly arched "
      "high above the cool stone floor, adding to the majestic feel of "
      "the room.",
    ({"large room","room","hall"}) : "This room is obviously the main "
      "gathering place for dancing and revelry.",
    ({"large chandelier","chandelier"}) : "It is stunning as it "
      "reflects the light of the orbs.",
    ({"glowing orbs","orbs","orb","light","lights"}) : "These lights "
      "cast a warm light around the room.",
    ({"stone floor","floor","stone","stones"}) : "The floor is "
      "created from many smooth stones all tightly locked together.",
    ({"dew","bead","beads"}) : "The little beads of dew glow with the "
      "warmth of the light cast by the orbs.",
  ]) );
  SetItemAdjectives( ([
    "glowing orbs" : "small",
    "high ceiling" : ({"domed","arched"}),
    "stone floor" : ({"smooth","cool"}),
  ]) );
  SetSmell( ([
    "default" : "A faint earthy smell is carried on the wind.",
  ]) );
  SetListen( ([
    "default" : "Music and bubbling laughter mingle together harmoniously.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "reveler" : 5,
  ]) );
  SetExits( ([
    "out" : KINGDOM_ROOMS + "kingdom13",
    "west" : KINGDOM_ROOMS + "kingdom11",
  ]) );
}
