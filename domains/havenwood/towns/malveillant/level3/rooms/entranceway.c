/*   Portia  1-19-99
    The entranceway to the ring of Magic.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("The Ring of Magic");
  SetAmbientLight(20);
  SetClimate("indoors");
  SetExits( ([
    "south" : MAL_ROOMS3 + "center3",
    "southeast" : MAL_ROOMS3 + "necromancer",
    "southwest" : MAL_ROOMS3 + "study2",
    ]) );
  SetListen( ([
    "default" : "Slight murmurings come from the southwest.",
    ]) );
  SetSmell( ([
    "default" : "The foyer smells of odd potions.",
    ]) );
  SetInventory( ([
    MAL_NPC3 + "student1" : 1,
    ]) );
  SetLong("This is the entrance to the Ring of "
    "Magic. This huge library houses all of the "
    "knowledge of magic available to the town of "
    "Malveillant. Its circular structure signifies "
    "the continuity of magic on Kailie. The huge "
    "obsidian walls curve southward here and shimmer "
    "in the light of the torches that hang near the door.");
  SetItems( ([
    ({"library", "entrance", "ring", "ring of magic"}) :
        (:GetLong:),
    ({"walls", "wall"}) : "The walls shimmer softly.",
    ({"torches", "torch"}) : "The torches hang near the large "
        "door.",
    ({"door"}) : "The large door leads to the courtyard.",
    ({"light"}) : "The torches produce an soft glow.",
    ]) );
  SetItemAdjectives( ([
    "library" : ({"huge", "circular"}),
    "walls" : ({"huge", "obsidian", "curved"}),
    "door" : "large",
    ]) );
  }
