/* Averath Field Room 10
*  Created BY: Ohtar
*/

#include <lib.h>
#include "../avb.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("a barren field");
   SetDomain("Averath");
   SetLong("The small barren field is covered in sun burnt grass "
           "and mixed with a tall stringy, brown straw. In the "
           "middle of the field seems to be a tree that looks "
           "very old and decrepit. The roots are partially "
           "erupting from the ground. They also appear to be "
           "very dried out and broken in many places. There "
           "is nothing that seems to be living in site. One "
           "could travel in several directions from here. "
           "However there seems to be a large opening to the "
           "southwest. ");
   SetItems( ([
                ({ "field"}) :
                  "The small field is covered in sun burnt grass and "
                  "mixed with a tall stringy, brown straw.",
                ({ "straw" }) :
                   "The straw is about three feet tall and very "
                   "stringy. Most of it is folded over and appears "
                   "to be dried out and rotting away. ",
                ({ "tree"}) :
                   "The tree looks very old and decrepit. Its roots "
                   "erupt through the ground however they are "
                   "very dried out and broken in several places. ",
                ({ "roots"}) :
                   "The roots erupt through the ground however "
                   "they are very dried out and broken in several "
                   "places. ",
                ({ "grass"}) :
                   "The grass is about eight inches in height. Its very "
                   "brown and appears to be quite sun burnt. Mixed "
                   "all through it is tall straw.",
                ({ "opening"}) :
                   "The large opening appears to be a hole in the "
                   "ground. ",
           ]) );
SetItemAdjectives( ([
          "field" : ({"small", "barren", "sundried"}),
          "grass" : ({"sun burnt", "burnt"}),
          "straw" : ({"tall", "stringy", "brown", "very dried"}),
          "tree" : ({"decrepit"}),
          "roots" : ({"dried", "broken"}),
]) );
SetExits( ([ "south" : AVB_FIELD + "field11",
             "southwest" : AVB_FIELD + "field7",
             "west" : AVB_FIELD + "field6",             
             "north" : AVB_FIELD + "field9",
             "northwest" : AVB_FIELD + "field5",
        ]) );
SetSmell( ([ "default" : "The stale air reeks of dead wood.",]) );
SetListen( ([ "default" : "The sound of crows echo through the air.", ]) );
SetInventory( ([ AVB_NPC + "moth" : 2+random(2),
                 AVB_NPC + "crow" : 1+random(2),
            ]) );
}
