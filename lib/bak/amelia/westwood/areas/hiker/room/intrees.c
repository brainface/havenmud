#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("inside the West Wood");
   SetDomain("WestWood");
   SetLong("The West Wood crowds around this small pocket of space "
           "left open for travel.  Branches spin around each other, "
           "many low, close to the ground, waiting to trip the "
           "unwary traveller.  Roots burst out of the ground at "
           "all sorts of angles and in all sorts of sizes, dancing "
           "across the dirt.  The only clear way out seems to be "
           "to the northwest.");
   SetItems( ([
                ({ "west wood","wood","woods" }) :
                   (: GetLong :),
                ({ "low branches","low branch","branches","branch" }) :
                   "The branches are thick and wily, but somehow "
                   "escape notice until one is right on top of "
                   "them, falling flat onto one's face.",
                ({ "dirty roots","root","dirty root","roots" }) :
                   "The roots are dark and dirty, twisting and "
                   "turning in and out of the ground like serpents "
                   "in an ocean.",
                ({ "dark ground","ground","dirt" }) :
                   "The dirt is solid and dark, with roots coming up "
                   "out of it and branches brushing near to it.  "
                   "The pattering footsteps of time have pushed it "
                   "down, making it stiff and almost smooth.",
           ]) );
   SetListen( ([
                 "default" : "The wind brushes against the branches, "
                    "clattering them together.",
            ]) );
   SetSmell( ([
                "default" : "The air smells musty and deep.",
           ]) );
   SetExits( ([
                "northwest" : H_ROOM + "meadow_9",
           ]) );
   SetInventory( ([
                    H_NPC + "babyb2"   : 1,
                    H_NPC + "bear_mom" : 1,
                    H_NPC + "grub" : 3+random(7),
               ]) );
}
