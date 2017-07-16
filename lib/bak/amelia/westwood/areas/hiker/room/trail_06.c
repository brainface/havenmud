#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   SetDomain("WestWood");
   SetLong("The trail widens to the north as the ground gets flatter "
           "and more grass and flowers start to appear in the thinning "
           "underbrush.  The trees move back from the wooden planks, "
           "one of which is tilted down on its western side, making it "
           "difficult to stand on.  The planks lead north and southeast.");
   SetItems( ([
                ({ "narrow trail","trail" }) :
                   (: GetLong :),
                ({ "flattening ground","ground" }) :
                   "The ground is covered with grass, and some flowers "
                   "are beginning to appear on it.  One prominent flower "
                   "has four white petals and a brown, bristly center.  "
                   "Its leaves are pale green.",
                ({ "small dogwood","dogwood","flowers","petals","flower"
                   "petal","center","leaves","leaf" }) :
                   "The flower showing most often here is small and "
                   "white with a brown center and pale leaves.  A few "
                   "other flowers grow, as well, but not as many live "
                   "here.",
                ({ "green grass","grass" }) :
                   "Grass shows more often here, and not just under and "
                   "near the planks.",
                ({ "thinning underbrush","underbrush","brush" }) :
                   "The brush clogging up the area under the trees is "
                   "thinning, making way for grass and flowers.",
                ({ "west wood","tree","trees","woods","wood","forest" }) :
                   "Trees grow all over, making up the West Wood.",
                ({ "wooden planks","plank","planks","board",
                   "boards","wood" }) :
                   "The planks are longer here than to the southeast, "
                   "where they grow very short despite the lack of "
                   "incline.  One of the ones here has a sharp tilt to "
                   "it, making it difficult to stand on.",
           ]) );
   SetItemAdjectives( ([
                         "boards" : ({ "wooden","wood","board of",
                                       "boards of","planks of",
                                       "plank of" }),
                         "brush" : ({ "thinning","under" }),
                         "trail" : ({ "narrow","widening" }),
                         "dogwood" : ({ "small","white","prominent",
                                        "brown","bristly","green",
                                        "pale" }),
                    ]) );
   SetListen( ([
                 "default" : "Some chatter is brought on the wind from "
                    "the north.",
            ]) );
   SetSmell( ([
                "default" : "Smells of food and flowers drift in elusive "
                   "gusts from the north.",
           ]) );
   SetExits( ([
                "north" : H_ROOM + "trail_07",
                "southeast" : H_ROOM + "trail_05",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : random(2),
               ]) );
}
