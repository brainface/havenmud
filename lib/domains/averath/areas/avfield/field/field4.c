/* Averath Field 4
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
           "and mixed with a tall stringy, brown straw. There "
           "is a triangular pattern here that looks to have been "
           "pressed into the dead grass. The rest of the field "
           "is very plain and appears to be abandoned. Heading "
           "back north would guide you from the sundried fields. "
           "One could also travel east further into the dreaded "
           "barren fields or northeast towards what appears to "
           "be a large opening.");
   SetItems( ([
                ({ "field","sundried fields", "sundried field", 
                   "small field", "barren field", "barren fields" }) :
                  "The small field is covered in sun burnt grass and "
                  "mixed with a tall stringy, brown straw.",
                ({ "opening", "large opening" }) :
                   "The large opening appears to be a hole in the "
                   "ground. ",
                ({ "straw" }) :
                   "The straw is about three feet tall and very "
                   "stringy. Most of it is folded over and appears "
                   "to be dried out and rotting away. ",
                ({ "pattern", "triangular pattern" }) :
                   "The triangular pattern is formed from some "
                   "sort of object that must have been pressed "
                   "on it hard enough or long enough to to flatten "
                   "all that is left of the grass.",
                ({ "grass", "sun burnt grass", "burnt grass" }) :
                   "The grass is about eight inches in height. Its very "
                   "brown and appears to be quite sun burnt. Mixed "
                   "all through it is tall straw.",]) );
SetItemAdjectives( ([
          "field" : ({ "small", "barren", "sundried" }),
          "grass" : ({ "sun burnt", "burnt"}),
          "straw" : ({ "tall", "stringy", "brown", "very dried" }),
          "pattern" : ({ "triangular" }),
          "opening" : ({ "large" }),
]) );
SetExits( ([ "north" : AVB_FIELD + "field3", 
             "east" : AVB_FIELD + "field8",
             "northeast" : AVB_FIELD + "field7",
        ]) );
SetSmell( ([ "default" : "The stale air has a foul burnt grass smell to it.",
        ]) );
SetListen( ([ "default" : "The sound of crows echo through the air.", ]) );
SetInventory( ([ AVB_NPC + "crow" : 2+random(2),
                 AVB_NPC + "moth" : 2+random(2),
            ]) );
}
