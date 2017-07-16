/* Averath Field 8
 * Created By: Ohtar
*/

#include <lib.h>
#include "../avb.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("a barren field");
   SetDomain("Averath");
   SetLong("The small barren field is covered in sun burnt grass "
           "and mixed with a tall stringy, brown straw. Standing "
           "in the middle of this area is a old abandoned hut that "
           "could be entered from here. The small hut is very run "
           "down. It has a broken door hanging open by one hinge "
           "and one small window framed into the front of it. It "
           "is grey in color; although in some areas the paint has "
           "completely been peeled away from the searing winds. "
           "Heading east would guide you from the sundried fields. "
           "One could also travel several other directions into "
           "the dreaded barren fields. However, there seems to be "
           "a large opening to the north.");
SetItems( ([
        ({ "field"}) :
                  "The small field is covered in sun burnt grass and "
                  "mixed with a tall stringy, brown straw.",
        ({ "straw" }) :
                  "The straw is about three feet tall and very "
                  "stringy. Most of it is folded over and appears "
                  "to be dried out and rotting away. ",
        ({ "hut"}) :
                  "The small hut here is very run down. It has a broken "
                  "door hanging open by one hinge. There is a small window "
                  "framed into the front wall. It is grey in color; "
                  "although in areas the paint has completely been peeled "
                  "away from the searing winds. ",
        ({ "opening"}) :
                   "The large opening appears to be a hole in the "
                   "ground. ",
        ({ "grass"}) :
                  "The grass is about eight inches in height. Its very "
                  "brown and appears to be quite sun burnt. Mixed "
                  "all through it is tall straw.",
        ({ "door" }) :
                   "The door is barely hanging open by a single hinge.",
        ({ "window" }) :
                   "The small window is framed into the front of the "
                   "house.",
        ]) );
SetItemAdjectives( ([
          "field" : ({"small", "barren", "sundried"}),
          "grass" : ({"sun burnt", "burnt"}),
          "straw" : ({"tall", "stringy", "brown", "very dried"}),
          "opening" : ({"large"}),
          "hut" : ({"abandoned", "old", "small", "run down"}),
          "door" : ({"broken", "hanging"}),
          "window" : ({"small"}),
]) );
SetExits( ([ "north" : AVB_FIELD + "field7", 
             "east" : AVB_FIELD + "field12",
             "west" : AVB_FIELD + "field4",
             "northeast" : AVB_FIELD + "field11",
             "northwest" : AVB_FIELD + "field3",
        ]) );
SetEnters( ([ "hut" : AVB_FIELD + "hut",
        ]) );
SetSmell( ([ "default" : "The air reaks of dead wood.",]) );
SetListen( ([ "default" : "The sound of crows echo through the air.", ]) );
SetInventory( ([ AVB_NPC + "moth" : 1+random(2),
                 AVB_NPC + "crow" : 2+random(2),
            ]) );
}
