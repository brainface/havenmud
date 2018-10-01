#include <lib.h>
#include "../skicily.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("along the boardwalk in Skicily");
  SetLong(
    "The boardwalk of Skicily is an impressive sight, with well sanded and stained wooden walkways leading north and south.  "
    "Large ramps lead up to the east, where buildings are decorated with iron sconces burning a strange blue flame.  "
    "To the west, the Skicily Shore leads towards the ocean, and a gentle breeze always seems to ride in along the waves.  "
  );
  SetClimate("temperate");
  SetSmell( ([
    "default" : "The smells of cooking meat come from many of the establishments to the east.",
  ]) );
  SetListen( ([
    "default" : "At all hours of the day, conversation can be heard coming from the businesses along the boardwalk.",
  ]) );
  SetItems( ([
    "boardwalk" : "The boardwalk is made of well sanded wood, stained to maintain a \"natural\" wood color.",
    ({ "ramp", "ramps" }) : "The ramps are of the same polished wood as the boardwalk, but lead up toward the businesses.",
    ({ "building", "buildings", "business", "businesses" }) : "The businesses of Skicily seem remarkably well lit, with strange blue-flamed sconces.",
    ({ "sconce", "sconces", "flame" }) : "The iron sconces seem to burn something far different from most cities. The blue flames burn "
                                      "in a strange manner.",
  ]) );
  SetItemAdjectives( ([
    "boardwalk" : ({ "wooden" }),
    "ramp" : ({ "wooden" }),
    "sconce" : ({ "iron", "strange" }),
  ]) );
  SetExits( ([
    "north" : SKICILY_ROOM "boardwalk_02",
    "east"  : SKICILY_ROOM "boardwalk_03",
    "south" : SKICILY_ROOM "boardwalk_04",
  ]) );
}
