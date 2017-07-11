/*   Portia  1-9-99
    The enchanter's study.
 */
#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an enchanter's workroom");
  SetClimate("indoors");
SetAmbientLight(20);
  SetExits( ([
    "northeast" : MAL_ROOMS3 + "hall2",
    "southwest" : MAL_ROOMS3 + "hall3",
    ]) );
  SetListen( ([
    "default" : "There is soft murmuring here.",
    ]) );
  SetSmell( ([
    "default" : "The area smells of incense.",
    ]) );
  SetInventory( ([
    MAL_NPC3 + "lead_enchant" : 1,     
    MAL_NPC3 + "teach_enchant" : 1,    
    ]) );
  SetLong("This room has an interesting aura. It seems as though "
    "it has been used for some elusive and eluding magic as there "
    "seems to be an unspoken understanding between the atmosphere and "
    "the resident of this workroom. All of the books are in order here "
    "and nothing seems to be out of place. No cobwebs line the walls and "
    "the window overlooking the courtyard is spotless. A single torch "
    "hangs on the curved obsidian wall.");
  SetItems( ([
    ({"workroom", "room"}) : (:GetLong:),
    ({"books", "book"}) : "The books are all in their proper places.",
    ({"walls", "wall"}) : "The walls are curved obsidian.",
    "torch" : "The torch is quite dim.",
    "window" : "The gleaming window overlooks the courtyard.",
    ]) );
  SetItemAdjectives( ([
    "walls" : ({"curved", "obsidian"}),
    "torch" : "dim",
    "window" : ({"spotless", "gleaming"}),
    ]) );
  }
