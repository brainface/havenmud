#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   SetDomain("WestWood");
   SetLong("The trail splits here, heading to the northeast most "
           "of all.  That is where the trail is most trampled, at "
           "least.  To the west, a thin, wandering path heads into "
           "the forest tentatively, the other off-shoot from the trail "
           "coming from the southeast.  The trees crowd around the "
           "thin path, trying to close in on it, while the ground on "
           "the path is solid, compared to the mucky ground of the " 
           "mail trail.");
   SetItems( ([
                ({ "main trail","trail" }) :
                   (: GetLong :),
                ({ "thin wandering path","thin path","wandering path",
                   "path","trail" }) :
                   "The path proceeds with meekness through the forest, "
                   "like a little mouse, only chopping through the "
                   "lower part and leaving much behind.",
                ({ "west wood","forest","woods","wood","trees","tree" }) :
                   "The West Wood surrounds the trail and path, hiding "
                   "them carefully from much distant sight.  They "
                   "circle around the trail warily, careful not to "
                   "encroach too much, but some trees grow quite close, "
                   "though they are all small.",
                ({ "varied ground","ground","dirt","solid ground",
                   "mucky ground","muck","mud" }) :
                   "The path to the west has solid ground, dirt that "
                   "isn't spoiled like that on the rest of the trail, "
                   "to the southeast and northwest.  On that trail, the main "
                   "trail, the ground has dissolved into mud and muck.",
           ]) );
   SetItemAdjectives( ([
                         "trail" : ({ "trampled","main" }),
                    ]) );
   SetListen( ([
                 "default" : "Talk comes from the west.",
            ]) );
   SetSmell( ([
                "default" : "Some faint odors come from the west, like a "
                   "fire or some smoke.",
           ]) );
   SetExits( ([
                "northeast" : H_ROOM + "trail_15",
                "southeast" : H_ROOM + "trail_13",
                "west"      : H_ROOM + "campfire",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : 1+random(2),
               ]) );
}
