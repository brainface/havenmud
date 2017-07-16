/* An arctic expedition at the north pole
 *
 * before healer's igloo
 *
 *
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
  SetShort("before a flag-decorated igloo");
  SetLong(
    "A small, lonely igloo sits here on the ice, uncomfortably far "
    "from the smoking fire to the south. To the north, the ice wall "
    "stands, mute barrier against whatever it is the camp fears outside. "
    "To the east there appears to be some form of gate."
  );

  SetListen( ([
    "default" : "Loose flags flap slowly in the wind.",
  ]) );

  SetSmell( ([
    "default" : "The faint scent of incense escapes from the igloo.",
  ]) );

  SetItems( ([
    ({"flags","flag"}) : "Ragged green and white flags, showing the "
      "manastar of the Magildan faith, flap futily from poles stuck "
      "at odd angles from the igloo.",
    ({"ice","ground"}) : "More snow and ice coats the ground here, "
      "with very few markings of passage.",
    ({"wall","ice wall"}) : "The ice wall stands giant high to the "
      "north. Torches set along the top provide a low light.",
    ({"igloo","igloos"}) : "The igloo seems barely large enough for "
      "one person.",
  ]) );

  SetExits( ([
    "east" : CAMP_ROOM "camp20",
    "west" : CAMP_ROOM "camp00",

    "southwest" : CAMP_ROOM "camp01",
    "south" : CAMP_ROOM "camp11",
    "southeast" : CAMP_ROOM "camp21",

  ]) );

  SetInventory( ([
    CAMP_NPC "guard" : random(2)+1,
  ]) );

  SetEnters( ([
    "igloo" : CAMP_ROOM "igloo_healer",
  ]) );
}

