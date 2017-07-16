// Targoviste
// Laoise
// August 2004

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetClimate("indoors");
  SetAmbientLight(30);
  SetTown("Targoviste");
  SetShort("the Heart's Blood tavern");
  SetLong(
    "Chairs are set in groupings around several tables "
    "in the main area of this building. To the north "
    "is a long counter with stools arrayed along it. "
    "The southwest wall appears to follow the line of "
    "the inner keep, forming a somewhat triangular building. "
    "Centered along the southwest wall is a large fireplace, "
    "covered completely by a metal fireguard with no visible "
    "openings. The fireguard appears designed to allow the "
    "fire to warm the room without any of its light escaping "
    "to illuminate the tavern. Spanning a large section of "
    "the wall, the fireplace is carved from red marble, which "
    "has veins of black swirled through it."
  );
  SetItems( ([ 
    "fireguard" : "Closer inspection reveals two long, thin "
    "horizontal slits along the top of the fireguard, near "
    "where it meets the mantlepiece of the fireplace. This "
    "part of the fireguard is angle down, meaning these slits "
    "point towards the fireplace and away from the main room. "
    "The purpose of this device appears to be allowing the "
    "warmth of a fire to fill the room without permitting "
    "any of the fire's light to be seen.",


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A rumble of voices fills the tavern.",
  ]) );
  SetSmell( ([
    "default" : "The scent of cooking fills the room.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "bar2",
    "northwest" : TARG_ROOM "bar3",
    "out" : TARG_ROOM "east_wall2",
  ]) );
}
