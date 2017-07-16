//Selket@Haven
//2006

#include <lib.h>
#include "../mtn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetShort("on a steep path up the side of Shatadru Mountain");
  SetLong(
    "The path continues to wind further up the face of the "
    "mountain towards the northeast from here, with an abrupt "
    "drop just below. On either side of the path stand proud "
    "ancient sculptures carved out of the stone itself, but "
    "snow has blown into the details carved into their faces."
  );
  SetItems( ([
    ({ "snow", "sculpture", "sculptures", "stone", "details" }) : 
    "The sculptures seem almost like guardians of the mountain, "
    "with agelessly wise features half-hidden behind the snow.",
    ({ "path", "mountain", "face" }) : 
    "The path leads both northeast and down to the base of "
    "Shatadru Mountain.",
    ({ "drop" }) :
    "One would not want to fall from here.",
  ]) );
  SetItemAdjectives( ([
    "sculpture" : ({ "proud", "ancient" }),
    "drop" : ({ "abrupt" }),
  ]) );
  SetExits( ([
    "down" : MTN_ROOM "/mtn9",
    "northeast" : MTN_ROOM "/mtn11",
  ]) );
  SetInventory( ([
    MTN_NPC "/yeti1" : 1,
  ]) );
  SetListen("Distant bleatings can be heard.");
  SetSmell("The chilling air smells somewhat of goats.");
}
