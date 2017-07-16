/* An arctic expedition at the north pole
 *
 * longship entrance
 */
#include <lib.h>

// mikes includes dir
#include "../camp.h"

// must be in all rooms
inherit LIB_ROOM;

static void create() {
  // get it started
  ::create();

  SetClimate("arctic");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("before a beached longship");
  SetLong(
    "An immense goden longship, likely the pride of the fleet, sits "
    "beached piteosly on the ice here. The base of the ship looks to "
    "have collapsed and flattened under its own weight, and holes "
    "here and there indicate a steady loss of mass to salvagers. The "
    "sails have found new use as a tarp, forming a covered entrance over "
    "a doorway carved into the interior of the ship."
  );

  SetListen( ([
    "default" : "Arctic winds whistle past the abandoned deck.",
  ]) );

  SetSmell( ([
    "default" : "A thin fog of sawdust fights with ashes blown from the east.",
  ]) );

  SetItems( ([
    "longship" : (:GetLong:),
    ({"ice","base"}) : "It seems as if the ice formed around the longship when "
      "winter set in, freezing it in place and crushing the lower hull.",
    ({"sails","tarp"}) : "A black sail stretched overhead keeps drifting "
      "snow and scorching sun away from the doorway, providing some "
      "memory of comfort.",
    ({"doorway","interior"}) : "A simple rectangular doorway has been cut from the base "
      "of the ship, providing entrance to the not yet ruined interior."
  ]) );

    //"Claw marks along the ground and wall show "
    //"where the hounds have futily attempted to escape their cramped "
    //"quarters.

  SetExits( ([
    "north" : CAMP_ROOM "camp00",
    "east" : CAMP_ROOM "camp11",
    "south" : CAMP_ROOM "camp02",
    "northeast" : CAMP_ROOM "camp10",
    "southeast" : CAMP_ROOM "camp12",
  ]) );

  SetEnters( ([
    "longship" : CAMP_ROOM "longship",
  ]) );

}

