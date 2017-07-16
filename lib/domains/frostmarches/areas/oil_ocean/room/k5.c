//Illura@haven
//k5
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include <domains.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("at the edge of the oil ocean");
  SetLong(
    "Just off the main road, the soil gives way to stubby "
    "bent grasses and desolate sands, speckled with "
    "inky tar and choked out vegetation. Although the "
    "foothills can be seen in the distance to the east, "
    "the western verges are clotted out with a viscous "
    "decay from horizon to horizon. A few bent trees "
    "dot the landscape here, their leaves drooping and "
    "yellow, as though no moisture can be squeezed "
    "from the clotted soil."
  );
  SetExits( ([
    "southwest" : OIL_ROOM "/j6",
      "east" : FROSTMARCHES_VIRTUAL+"frostmarchrd/0,-3",
  ]) );
  SetItems( ([
    ({"soil", "soils", "sand", "sands"}) : 
    "The soil is mainly sand here, partially composed of oily bitumen.",
    ({"tar"}) : "Black tar covers much of the ground.",
    ({"grass", "grasses", "vegetation", "decay", "land"}) : 
    "The nearby oil ocean chokes life from the land as it seeps into the soil.",
    ({"tree", "trees", "landscape"}) : 
    "A few trees struggle to grow here, inching upwards with decaying leaves.",
    ({"leaf", "leaves"}) : 
    "The leaves on the trees are slowly dying, almost as you watch.",
    ({"road"}) : "The main road is lies to the north.",
    ({"foothill", "foothills", "hill", "hills", "distance", "waste", "eastern horizon"}) :
    "The foothills of the Western Waste can been seen to the east.",
    ({"verge", "horizon","sea","ocean", "western horizon"}) :
    "On the western horizon, the Ruined Sea is clotted out by the Great Oil Ocean.",
    ({"bitumen"}) :
    "This black, sticky, oily substance is speckled over the ground."
  ]) );
  SetItemAdjectives( ([
    "road" : "main",
    "foothill" : ({ "foot", "western" }),
    "verge" : ({"great", "oil", "nearby","ruined"}),
    "grass" : ({"stubby", "bent", "viscous", "choked", "choked out"}),
    "soil" : ({"desolate", "speckled", "clotted"}),
    "tar" : "inky",
    "tree" : ({"few", "bent"}),
    "leaf" : ({"yellow", "drooping","decaying","dying"}),
    "bitumen" : ({"oily", "black", "sticky"}),
  ]) );
  SetInventory( ([
    OIL_NPC + "deer" : 2,
  ]) );
  SetListen( ([
    "default" : "You can hear the oil popping and shifting in the ground.",
  ]) );
  SetSmell( ([
    "default" : "The air is steamy and stings your nostrils.",
  ]) );
}
