/* An arctic expedition at the north pole
 *
 * a very crappy bank
 *
 * should really have "the thing" references in here.
 */
#include <lib.h>

// mikes includes dir
#include "../camp.h"

// must be in all rooms
inherit LIB_ROOM;

static void create() {
  // get it started
  ::create();

  SetClimate("indoors");
  SetAmbientLight(10); // I hope this is dark?
  SetShort("a dimly-lit igloo");
  SetLong(
    "It's miserable, cold, and dark in this small igloo. No chimney "
    "allows sunlight through, and the air is stagnant and stifled "
    "from the lack of breeze. A pile of rags and furs lies on the far "
    "side of the door, and the ice in the center is mushy and disturbed."
  );

  SetListen( ([
    "default" : "It's eerily silent in here.",
  ]) );

  SetSmell( ([
    "default" : "A faint metallic scent wafts about.",
  ]) );

  SetItems( ([
    ({"ground","ice","marks"}) : "Shovel marks in the ice make it look "
      "like someone is storing something under the floor.",
    ({"igloo"}) : (: GetLong :),
    ({"pile","rags","furs"}) : "This miserable pile of stinking furs "
      "looks like it'd make a terrible bed, so that's probably exactly "
      "what it is.",
    ({"door", "hole"}) : "It's more of a hole. Arctic air is slowly "
      "seeping through.",
  ]) );

  SetInventory( ([
    CAMP_NPC "banker" : 1,
  ]) );

  SetExits( ([
    "out" : CAMP_ROOM "camp12",
  ]) );

}

