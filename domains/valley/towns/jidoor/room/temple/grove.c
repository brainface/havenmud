/* Magildan grove
 * Ranquest@Haven
 * 02/12/99
 */
#include <lib.h>
#include "../../jidoor.h"
#include <std.h>
inherit LIB_ROOM;
#define TEM JID_ROOM + "/temple/"
int goon();

static void create() {
  room::create();
  SetTown("Jidoor");
  SetClimate("temperate");
  SetDomain("Valley");
  SetAmbientLight(40);
  SetShort("a small grove");
  SetLong(
    "This grove radiates peace and tranquility, flourishing under"
    " the blessing of the Magildan gods. This is indeed a holy place; no"
    " one not of the Magildan faith should intrude here. A huge"
    " tree stands alone in the center of the clearing, proud"
    " and forlorn. To the north stands the Majestic Tower of"
    " the Magildan."
    " To the northwest, northeast, southeast, and"
    " southwest, lie the Towers of Zaxan, Lord of Elemental Energies."
    " These are the towers of fire, earth, water,"
    " and air respectively. The trees stretch overhead to"
    " form a living canopy of green.");
  SetItems( ([
    ({"grove","place","clearing","sanctuary"}) : (:GetLong:),
    ({"tree"}) :
      "The ancient tree standing in the centre of the clearing"
      " has grown to an unprecedented size. The weight of ages lie"
      " heavily upon it, giving it an air of majesty.",
    ({"trees","branches","branch","canopy","limbs","limb"}) :
      "The trees thickly surrounding the grove have stretched their"
      " limbs overhead, as if jealous that some other god might"
      " see this sanctuary.",
      ]) );
  SetItemAdjectives( ([
    "grove" : ({"small","holy"}),
    "tree" : ({"huge","ancient","proud","forlorn"}),
    "trees" : ({"of green","majestic","jealous"}),
    ]) );
  SetSmell("default","The smell of tree sap fills the air.");
  SetListen("default","The branches rustle in the wind.");
  AddExit("north", TEM + "b",(:goon:));
  AddExit("south", TEM + "f", (:goon:));
  AddExit("northeast", TEM + "c", (:goon:));
  AddExit("southwest", TEM + "e",(:goon:));
  AddExit("southeast", TEM + "g",(:goon:));
  AddExit("northwest", TEM + "a", (:goon:));
  SetInventory( ([
     JID_NPC + "/hawek" : 1,
    STD_NPC + "butterfly" : 3,
    STD_NPC + "wolf" : 1,
    STD_NPC + "robin" : 2,
    STD_NPC + "jay_blue" : 1,
    STD_NPC + "squirrel" : 1,
    ]) );
  }

int goon() {
  if( (this_player()->GetReligion() == "Magildan") ||
    (immortalp(this_player())) ) {
    message("system", "%^BOLD%^The trees seem to bow as they part"
      " to allow you to leave.%^RESET%^",this_player() );
   } else {
   message("my_action","%^MAGENTA%^BOLD%^The trees groan "
      "and creak angrily as you force your way through the "
      "grove.%^RESET%^",this_player());
  }
  return 1;
}
