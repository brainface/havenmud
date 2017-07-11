/* Averath Field Room 1
*  Created BY: Ohtar
*/

#include <lib.h>
#include <domains.h>
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
           "could travel south, east or southeast further into "
           "the barren fields. One could also head back north "
           "out of this dreaded place. ");
   SetItems( ([
                ({ "field"}) :
                  "The small field is covered in sun burnt grass and "
                  "mixed with a tall stringy, brown straw.",
                ({ "straw" }) :
                   "The straw is about three feet tall and very "
                   "stringy. Most of it is folded over and appears "
                   "to be dried out and rotting away. ",
                ({ "tree","decrepit tree" }) :
                   "The tree looks very old and decrepit. Its roots "
                   "erupt through the ground however they are "
                   "very dried out and broken in several places. ",
                ({ "roots"}) :
                   "The roots erupt through the ground; however, "
                   "they are very dried out and broken in several "
                   "places. ",
                ({ "grass"}) :
                   "The grass is about eight inches in height. Its very "
                   "brown and appears to be quite sun burnt. Mixed "
                   "all through it is tall straw.",]) );
SetItemAdjectives( ([
          "field" : ({ "small", "barren", "sundried" }),
          "grass" : ({ "sun burnt", "burnt"}),
          "straw" : ({ "tall", "stringy", "brown", "very dried" }),         
          "tree" : ({ "decrepit", "old" }),
          "roots" : ({"broken", "dried" }),
]) );
SetExits( ([ "north" : AVERATH_VIRTUAL "averathroad/-15,0",
             "south" : AVB_FIELD + "field2",
             "east" : AVB_FIELD + "field5",
             "southeast" : AVB_FIELD + "field6",
        ]) );
SetSmell( ([ "default" : "The stale air has a foul burnt grass smell to it.", ])
 );
SetListen( ([ "default" : "The sound of crows echo through the air.", ]) );
SetInventory( ([ AVB_NPC + "moth" : 3+random(2),
                   AVB_NPC + "crow" : 3+random(2),
            ]) );
}
