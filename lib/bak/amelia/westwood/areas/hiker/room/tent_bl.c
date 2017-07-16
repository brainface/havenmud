#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("inside a blue tent");
   SetDomain("WestWood");
   SetLong("Sleeping bags have been tossed everywhere inside this tent, "
           "scrunched up into every little corner.  It was probably "
           "made so six men could sleep comfortably in it, but "
           "it looks like many more have squeezed in.  The tent is "
           "open, letting people go out.");
   SetItems( ([
                ({ "blue tent","tent" }) :
                   (: GetLong :),
                ({ "sleeping bags","bags","bag",
                   "corner","little corner" }) :
                   "The sleeping bags are all tinged blue by the blue "
                   "tent canvas, but most appear to be in all different "
                   "colors.  They are basically blankets that were "
                   "sewn into tubes, then closed at one end to keep "
                   "feet warm.  A number have found lumps in the "
                   "floor.",
                ({ "icky lumps","icky lump","lump","lump","rocks",
                   "rock","roots","root","odd lumps","odd lump" }) :
                   "Roots and rocks have found their ways under the "
                   "tent floor, making icky lumps in it that are "
                   "uncomfortable to sleep on.  Despite this, there "
                   "are many sleeping bags sprawled on top of them.", 
                ({ "blue floor","floor" }) :
                   "The floor is made of the same blue material the "
                   "rest of the tent is.  It seems like a number of "
                   "odd lumps have developed in it, but other than "
                   "that noticable bit, little else can be seen because "
                   "of the sleeping bags.",
                ({ "blue material","material","walls","wall" }) :
                   "The 'walls' of the tent are all blue, as well as the "
                   "floor.  They are all of the same tough material that "
                   "seems slightly soft, too.",
           ]) );
   SetItemAdjectives( ([
                         "material" : ({ "blue","tough","soft" }),
                         "lump" : ({ "icky","odd" }),
                         "bags" : ({ "sleeping" }),
                    ]) );
   SetListen( ([
                 "default" : "A lot of noise comes from outside.",
            ]) );
   SetSmell( ([
                "default" : "The tent smells like a bunch of people "
                   "have been using it to sleep in.",
           ]) );
   SetExits( ([
                "out" : H_ROOM + "campfire",
           ]) );
   SetInventory( ([
                    H_NPC + "camp_sl" : 6+random(4),
               ]) );
}
