#include <lib.h>
inherit LIB_ROOM;
 
static void create() {
   room::create();
   SetShort("on a platform");
   SetLong("The platform is seperate from all others, hidden high in "
           "the sky on the tallest of trees.  Other platforms "
           "are far below, barely visible from this hieght.  A "
           "wooden fence forms a barrier around the edge of the "
           "platform, preventing those who might fall "
           "off from performing such a feat.");
   SetItems( ([
                ({ "west wood","forest","wood" }) : (: GetLong :),
                ({ "wooden platform","platform","wood","solid wood" }) :
                   "Solid wood has been bound together to form "
                   "this platform.  It is suspended high, high "
                   "above the rest of the West Wood.",
                ({ "other trees","trees","tree","other tree","wood" }) :
                   "Other trees grow farther below, but the one "
                   "of this platform is by far the tallest.  They "
                   "support the other platforms.",
                ({ "tallest tree","tree","tall tree","wood" }) :
                   "The tree that is the main support of this platform "
                   "is the tallest tree of the West Wood.  It "
                   "flourishes in the slightly chill air.",
                ({ "other platforms","platform","platforms","wood" }) :
                   "The other platforms are so far below, no details "
                   "can be picked out.",
                ({ "wooden fence","fence","barrier","wood","edge",
                   "edge of platform","edge of the platform" }) :
                   "The fence glows blue around its polished surface, "
                   "shining ever so lightly in the sky.  The blue glow "
                   "encircles the platform, extending into "
                   "the air around, as well.",
                ({ "blue glow","glow" }) :
                   "The fence shines with a blue light that speaks of "
                   "magic.  The glow goes around the whole of the "
                   "platform and into the air above.",
           ]) );
   SetListen( ([
                 "default" : "The wind whistles.",
            ]) );
   SetSmell( ([
                "default" : "The cool air is clean and fresh, but has "
                   "a thinning bite to it.",
           ]) );
}

void init() {
   ::init();
   add_action("quit","quit");
}

int quit() {
   if(immortalp(this_player())) return 0;
   this_player()->eventPrint("Please wait until Amelia is done with you.  "
                             "Thanks! (:");
   return 1;
}
