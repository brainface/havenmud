#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
  SetShort("in front of the Kylin Temple");
  SetLong("The road curves here, making an extended \"U\" shape which meets the "
          "Via Imperialis to the west and the Sanctum Bazaar to the north. "
          "Directly to the east is a white stone building with marble columns. "
          "The flag of the Kylin religion drapes effortlessly from the high "
          "archway that leads into the temple.");
	SetExits( ([
          "west" : ROME_ROOM "vi07",
          "north" : ROME_ROOM "bazaar",
	  ]) );
	SetItems( ([
    "flag" : "The flag of the Kylin faith is a dragon wrapped around a "
             "set of scales.",
    ({ "temple", "building", }) : "The Kylin Temple is a white stone building "
             "with a high archway leading into it.",
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the east and west.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    "temple" : ({ "kylin", }),
    ]) );
  SetEnters( ([
    "temple" : ROME_ROOM "kylin_temple",
    ]) );
  SetInventory( ([
    ]) );
  SetSmell( ([
    "default" : "The smells of urban life taint the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city are alive and vibrant.",
    ]) );
}	           
