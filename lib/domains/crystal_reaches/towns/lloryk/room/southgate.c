#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

int CheckGuard(string dir);

static void create() {
  room::create();
  SetShort("the Southern Entrance to Lloryk Shire");
  SetLong("An opening in a short wooden fence is all that marks the southern "
          "gate to Lloryk Shire. Although the land is a range of "
          "gentle rolling hills, the fierce Crystal Mountains border them "
          "to the north and east and a murky swamp extends into the mists to the "
          "west. A small road stretches northward into the small town and "
          "a great highway extends east from here.");
  SetSmell( ([
    "default" : "The tinge of fresh manure belies the status of Lloryk as farmland.",
    ]) );
  SetListen( ([
    "default" : "In the distance, the sounds of village life echo.",
    ]) );
  SetProperty("no bump",1);
  SetItems( ([ 
    "gate" : "The 'gate' is not much more than a "
             "few wooden planks swinging in the opening in the short "
             "wooden fence.",
    ({ "mountains" }) :
            "Light reflects off of the peaks of the giant Crystal "
            "Reaches, making them shine like gemstones.",
    ({"rolling hills","hills"}) :
             "Bright green grass covers the rolling hills where an "
             "occasional plume of smoke can be seen to waft from one or "
             "another.",
    "swamp" : "To the west as the hills flatten toward the sea "
              "broad swamp is covered in mists.",
    "fence" : "The fence looks to have been built more to keep "
              "small children and animals in than anything else "
              "out.",
    "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region.  "
                        "However, grass and small weeds are starting to "
                        "grow over parts of it.",
    ({"grass","weeds"}) : "Small tufts of grass and weeds poke "
                        "their way through the surface of the road."]));
  SetInventory( ([
    LLORYK + "npc/guard.c": 2
    ]) );
  SetExits( ([
    "north" : LLORYK + "room/sg1",
    "south" : LLORYK + "room/outside_sgate",
    ]) );
}
