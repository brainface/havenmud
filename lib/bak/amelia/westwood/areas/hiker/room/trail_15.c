#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   SetDomain("WestWood");
   SetLong("The trail seems to be rather steep here as it climbs uphill, "
           "heading who-knows-where.  It is mucky and the dirt "
           "below has turned to mud.  The West Wood grows so close to the "
           "trail that one cannot avoid stepping in it, unless one "
           "wants to try flying.  The trail goes southwest and east.");
   SetItems( ([
                ({ "muddy trail","mucky trail","trail" }) :
                   (: GetLong :),
                ({ "muddy ground","muck","mud","dirt","ground",
                   "mud pubble","puddle" }) :
                   "The ground has been tramped on and stirred up and " 
                   "rained on so much, it has become a regular mud "
                   "puddle, only instead of being muddy water on "
                   "rather firm dirt, it is mud on mud on mud, "
                   "all mixed up and icky.  It is impossible to avoid "
                   "without flying, since trees grow so close.",
                ({ "west wood","wood","woods","tree","trees" }) :
                   "The trees don't seem to mind the extra water "
                   "in the ground here, as they grow quite close and "
                   "almost seem to want to move into the nice damp "
                   "bliss.  A couple plants have tried, but they "
                   "have been trampled to bits.",
                ({ "trampled plants","trampled plant","plants","plant",
                   "weak uprooted green things","weak things","things",
                   "weak uprooted green thing","green things","thing",
                   "weak thing","green thing","uprooted thing",
                   "uprooted things","weak uprooted things",
                   "weak uprooted thing","uprooted green things",
                   "uprooted green thing","weak green things",
                   "weak green thing" }) :
                   "Some plants have tried to get a hold in the muddy "
                   "ground of the trail, but they have failed due to the "
                   "number of people regularly crossing through here.  "
                   "They are trampled and now look like weak, uprooted "
                   "green things that don't deserve much notice.",
           ]) );
   SetListen( ([
                 "default" : "The trees shake some in the wind, rattling.",
            ]) );
   SetSmell( ([
                "default" : "The mud spreads some smells in the air.",
                "mud" : "It is not a particularly bad smell the mud "
                   "brings, but it is not an overly pleasant one either.  "
                   "It is a weak, strange smell like that of dirt after "
                   "a rain, but twisted so its not so nice and wholesome.",
           ]) );
   SetExits( ([
                "east" : H_ROOM + "trail_16",
                "southwest" : H_ROOM + "trail_14",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : 2,
               ]) );
}
