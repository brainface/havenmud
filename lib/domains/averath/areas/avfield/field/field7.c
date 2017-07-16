/* AV FIELD 7
*  Created By Ohtar
*/

#include <lib.h>
#include "../avb.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("outside a large burrow");
   SetDomain("Averath");
   SetLong("The small field is covered in sun burnt grass and "
           "mixed with a tall stringy, brown straw. The few "
           "green plants alive here surround what appears to "
           "be a large ascending hole that cuts downward into "
           "the soil. The mouth of the hole is gritty yet smooth "
           "and perfectly round. It leads into a sandy, damp and "
           "dark burrow. One could also travel in all directions "
           "from here. ");
SetItems( ([
                ({ "field" }) :
                  "The small field is covered in sun burnt grass and "
                  "mixed with a tall stringy, brown straw.",
               ({ "hole", "burrow"}) :
                  "The large ascending hole cuts downward into "
                  "the soil. Its mouth is gritty yet smooth "
                  "and perfectly round. It leads into a sandy, "
                  "damp and dark burrow.",
                ({ "straw" }) :
                   "The straw is about three feet tall and very "
                   "stringy. Most of it is folded over and appears "
                   "to be dried out and rotting away. ",
                ({ "grass"}) :
                   "The grass is about eight inches in height. Its very "
                   "brown and appears to be quite sun burnt. Mixed "
                   "all through it is tall straw.",
                ({ "plants", "green plants" }) :
                   "The green plants are rather small. They have "
                   "several leaves and no flowers. There are only a "
                   "few of them here.",]) );
SetItemAdjectives( ([
          "field" : ({"small", "barren", "sundried"}),
          "grass" : ({"sun burnt", "burnt"}),
          "straw" : ({"tall", "stringy", "brown", "very dried"}),
          "plants" : ({"green"}),
          "hole" : ({"large"}),
          "burrow" : ({"sandy","dark", "damp"}),
]) );
SetExits( ([ "north" : AVB_FIELD + "field6", 
             "south" : AVB_FIELD + "field8",
             "west" : AVB_FIELD + "field3",
             "east" : AVB_FIELD + "field11",
             "northeast" : AVB_FIELD + "field10",
             "southeast" : AVB_FIELD + "field12",
             "northwest" : AVB_FIELD + "field2",
             "southwest" : AVB_FIELD + "field4",
        ]) );
SetEnters( ([ 
      "hole" : AVB_BURROW + "burrow1",
        ]) );
SetInventory( ([ AVB_NPC + "moth" : 1+random(2),
                 AVB_NPC + "centipede" : 2+random(2),
            ]) );
}
