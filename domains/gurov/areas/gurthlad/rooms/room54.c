#include <lib.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  
  SetShort("a dead plain");
  SetLong("A endless, dead, dry plain. There is not much of interest here. "
           "Nothing can be seen  but the dead land rolling away over the "
           "horizon. A road can be seen to the north. There are brown leafed "
           "plants all around.");
  SetObviousExits("east, west");
  SetExits( ([
           "west" : G_ROOMS + "/room53",
           "east" : G_ROOMS + "/room55"]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
           ({ "plain", "land" }) : "The dead land stretches away in every "
           "direction. Nothing can be seen but dead grass and dirt as far as "
           "the eye can see.",
           "road" : "A dusty road running from east to west can be seen to "
           "the north.",
           ({ "plants", "brown plants", "field" }) : "A large field of short dirty "
           "brown leafed plants red stemmed tuber plants of the type squealers "
           "like to eat."]) );
  SetSmell( ([
           "default" :  "A light wind brings a faint smell of death."]) );
  SetListen( ([
           "default" : "A squealing sound can be heard nearby."]) );
  }
