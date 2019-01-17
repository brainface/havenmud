#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("on top of a rock pile");
  SetLong( "Several large boulders, projecting from the earth form the "
           "equivalent of a large hill.  From the top a large swamp can be "
           "seen extending a short distance to the north and east where it "
           "meets up with a series of tall cliffs.  The swamp extends far to "
           "the south as well.  The view to the west is that of a huge body "
           "of water with waves rolling in and crashing against the base of "
           "this pile of rocks.  In fact, water surrounds the entire hill, "
           "excepting the northern edge." );

  SetItems( ([ "mud" : "The only mud here is that that was tracked up by "
                       "foot.",
               "water" : "In addition to the sea and the swamp, water pools "
                         "in cavities worn into the rock.",
               "trail" : "A trail, chiseled up through the rocks, leads down "
                         "to the northwest where it curves out of sight.  "
                         "Occasionally muddy "
                         "footprints can be seen along the path.",
               "swamp" : "The swamp extends for several miles to the south, "
                         "although it only looks traversable on foot for a "
                         "short distance due to the greater depth of water "
                         "to the south.",
               "cliffs" : "The cliffs surround much of the region and "
                          "stretch to heights of two hundred feet or more.",
               ({"sea","body of water"}) :  "The sea extends beyond sight to "
                          "the west and stretches for miles up and down the "
                          "coast.",
               ({"hill","pile"}) : "The boulder pile forms a small hill on "
                          "a point that extends out into the sea. It is "
                          "bordered by the swamp to the east and by the sea "
                          "on the west and south.",
               "footprints" : "The humanoid looking footprints are longer "
                              "and skinnier than most humanoids and there "
                              "are scratches along the toes as well.",
               ({"rocks","boulders"}) :
                         "Many of the boulders are near the size of small "
                         "houses.  It looks possible to descend the south "
                         "side."]) );

  SetExits( ([ "northwest" : GWONISH + "room/swamp23",
               "down" : GWONISH + "room/swamp25"]) );

  SetSmell( ([ "default" : "A thick briny smell fills your nose."]) );
  SetListen( ([ "default" : "The endless roar of the surf vibrates the "
                   "rocks around you." ]) );
  SetObviousExits("northwest");
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

