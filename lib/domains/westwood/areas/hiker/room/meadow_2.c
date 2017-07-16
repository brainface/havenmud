#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("in a meadow");
   
   SetLong("Blueberry bushes grow profusely on the west side of the "
           "meadow, melding with the West Wood there.  The ground "
           "here is slightly damp and a little soft, but the area where "
           "the bushes are growing, the ground has risen up some and "
           "is dry and solid.  To the east, there seems to be some sort "
           "of trail, while the meadow continues to the north and south.");
   SetItems( ([
                ({ "narrow trail","trail" }) :
                   "The trail is off to the east.  It appears to go in "
                   "a general north-south direction.",
                ({ "slight damp ground","ground","damp ground" }) :
                   "The ground is not much to the look at, and it is "
                   "difficult to see through the masses of grass that "
                   "grow upon it.  It seems to get more soft and wet to "
                   "the south as it slants down, and more dry and solid "
                   "to the north as it slants up.",
                ({ "green grass","grass" }) :
                   "Grass simply covers the ground, almost hiding it from "
                   "sight.  It grows everywhere, and continues to grow "
                   "to the north, east, and south.",
                ({ "west wood","wood","woods","tree","trees" }) :
                   "The trees of the West Wood grow behind the "
                   "blueberry bushes here, off to the west.  More "
                   "trees grow around the meadow, but there aren't "
                   "many out there and all of those are quite young.  "
                   "The West Wood seems to pick up again to the south "
                   "and north, however.",
                ({ "wide meadow","meadow" }) :
                   (: GetLong :),
                ({ "blueberry bushes","blueberry bush","bushes",
                   "bush" }) :
                   "The bushes have thin branches that go every which "
                   "way, and small, almost circular, leaves that cover "
                   "it with blue-greenness.  Deep blue spheres called "
                   "blueberries hide behind the leaves and beneath "
                   "the branches, but they are large and they are "
                   "everywhere.",
                ({ "thin branches","thin branch","branches","branch" }) :
                   "The branches of the blueberry bushes are reddish "
                   "brown, and are pretty thin and crooked.  "
                   "They bend in all directions and twist everywhere, "
                   "forming the general shape of the bush.",
                ({ "blue-green leaves","leaves","leaf","blue-green leaf",
                   "blue green leaves","blue green leaf","circular leaves",
                   "circular leaf","small leaves","small leaf" }) :
                   "The leaves have a blueish tinge to them, though "
                   "they are mostly green.  They are circular and "
                   "small, though thick, and they cover the bushes "
                   "completely.",
                ({ "deep blue spheres","deep blue sphere","spheres",
                   "sphere","blue spheres","blue sphere","blueberries",
                   "blueberry","berries","berry","blue berry",
                   "blue berries" }) :
                   "The blueberries are huge and juicy, and even though "
                   "they cover the bushes just as much as the leaves do, "
                   "they manage to hide fairly well.  Most are tucked "
                   "behind leaves and hidden behind branches.",
           ]) );
   SetItemAdjectives( ([
                         "ground" : ({ "dry","solid","soft","wet" }),
                         "branches" : ({ "reddish","brown","thin",
                                         "crooked" }),
                    ]) );
   SetListen( ([
                 "default" : "It is mostly quiet here, with only the "
                    "occasional wind-stirred noise.",
            ]) );
   SetSmell( ([
                "default" : "One can almost smell the blueberries "
                   "waiting to be picked and eaten.",
           ]) );
   SetExits( ([
                "north" : H_ROOM + "meadow_1",
                "south" : H_ROOM + "meadow_3",
                "east"  : H_ROOM + "trail_08",
           ]) );
   SetInventory( ([
                    H_NPC + "pickgirl" : 2,
                    H_NPC + "pickboy" : random(2),
                    H_NPC + "picker" : 3,
                    H_OBJ + "blueberries" : 2 + random(4),
                    H_OBJ + "blueleaf" : 2 + random(8),
               ]) );
}
