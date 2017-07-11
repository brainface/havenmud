#include <lib.h>
#include "../avb.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside a large burrow");
   SetDomain("Averath");
   SetLong("The opening of the burrow lets in all the light "
           "available here. The walls are dirty brown and have "
           "some sort of residue smeared on them. They are "
           "all made up of compressed dirt and sand that has "
           "been formed, amazingly, into an even circular "
           "shape. The exit has sand tornados swirling about "
           "causing a slight whistling sound. Small remnants "
           "of animal carcasses lay about the room. Travelling "
           "east leads further into the burrow. ");
SetItems( ([
            ({ "opening" }) :
                 "The opening has bright light shining through "
                 "from outside. There are several small sand "
                 "tornadoes swirling about. ",
            ({ "debris" }) :
                 "The debris is made up of sand and dirt.",
            ({ "residue", "slime" }) :
                 "The residue is a green slime and is smeared "
                 "along the walls.",
            ({ "burrow" }) : 
      (:GetLong:),
            ({ "wall","walls" }) :
                 "The walls are dirty brown and have "
                 "some sort of residue smeared on them. They are "
                 "all made up of compressed dirt and sand that has "
                 "has been formed amazingly into an even circular "
                 "shape.",
            ({ "animal carcasses", "carcass", "remnants", "shell", 
               "shells", "bug shells" }) :
                   "The remnants look like old pieces of bug shells. ",
            ({ "tornado", "sand tornado" }) :
                   "The small tornadoes are made up of sand debris "
                   "swirling around in the air.",
            ({ "dirt", "sand" }) : 
                 "The dirt and sand are compressed together making "
                 "walls of the burrow. They both are brown in "
                 "color and very rough to the touch.",
            ]) );
SetItemAdjectives( ([
          "slime" : ({ "green", "smeared" }),
          "wall" : ({ "dirty", "brown", "circular"}),
          "tornado" : ({ "small" }),         
          "dirt" : ({ "brown", "compressed", "rough"}),
                 ] ) );
SetExits( ([ "out" : AVB_FIELD + "field7", 
             "east" : AVB_BURROW + "burrow2",
        ]) );
SetListen( (["default" : "The sounds of swirling winds can be heard. ",
         ]) );
SetSmell( (["default" : "The air smells very moist here.",
        ]) );
SetInventory( ([ AVB_NPC + "centipede" : 1+random(2),
                 AVB_NPC + "water_beetle" : 1,
                 AVB_NPC + "caterpillar" : 2+random(2),
            ]) );
}
