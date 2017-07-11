/* Averath Field 5
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
           "and mixed with a tall stringy, brown straw. Except "
           "for a dead tree stump half rotted away there the "
           "rest of the field is very plain and appears to be "
           "abandoned. Heading west would guide you from the "
           "sundried fields. One could also travel several other "
           "directions into the dreaded barren fields. ");
SetItems( ([
        ({ "field"}) :
                  "The small field is covered in sun burnt grass and "
                  "mixed with a tall stringy, brown straw.",
        ({ "straw" }) :
                  "The straw is about three feet tall and very "
                  "stringy. Most of it is folded over and appears "
                  "to be dried out and rotting away.",
        ({ "stump"}) :
                  "The tree stump is half rotted away and completely "
                  "dead. It seems to have been dried up for quite "
                  "some time now.",
        ({ "grass"}) :
                  "The grass is about eight inches in height. Its very "
                  "brown and appears to be quite sun burnt. Mixed "
                  "all through it is tall straw.",]) );
SetItemAdjectives( ([
          "field" : ({"small", "barren", "sundried"}),
          "grass" : ({"sun burnt", "burnt"}),
          "straw" : ({"tall", "stringy", "brown", "very dried"}),
          "stump" : ({"rotted", "dead", "tree"}),
]) );
SetExits( ([ "south" : AVB_FIELD + "field6", 
             "east" : AVB_FIELD + "field9",
             "west" : AVB_FIELD + "field1",
             "southeast" : AVB_FIELD + "field10",
             "southwest" : AVB_FIELD + "field3",
        ]) );
SetSmell( ([ "default" : "The air reaks of dead wood.",]) );
SetListen( ([ "default" : "The sound of crows echo through the air.", ]) );
SetInventory( ([ AVB_NPC + "crow" : 2+random(2),
                 AVB_NPC + "moth" : 1+random(2),
            ]) );
}
