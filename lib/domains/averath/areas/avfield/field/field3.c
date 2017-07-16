/* Averath Field 3
 * Created BY: Ohtar
*/

#include <lib.h>
#include "../avb.h"

inherit LIB_ROOM;

varargs mixed eventDig(string what, object who);
int BeenDug;

static void create() {
   room::create();
   BeenDug = 0;
   SetShort("a barren field");
   SetDomain("Averath");
   SetLong("The small barren field is covered in sun burnt grass "
           "and mixed with a tall stringy, brown straw. There "
           "is a square pattern here that looks to have been "
           "pressed into the dead grass. The rest of the field "
           "is very plain and appears to be abandoned. Heading "
           "back north would guide you from the sundried fields. "
           "One could also travel south, southeast or northeast "

           "further into the dreaded barren fields. However "
           "they could also travel east towards what "
           "appears to be a large opening.");
   SetItems( ([
                ({ "field"}) :
                  "The small field is covered in sun burnt grass and "
                  "mixed with a tall stringy, brown straw.",
                ({ "opening"}) :
                   "The large opening appears to be a hole in the "
                   "ground. ",
                ({ "straw" }) :
                   "The straw is about three feet tall and very "
                   "stringy. Most of it is folded over and appears "
                   "to be dried out and rotting away. ",
                ({ "pattern",}) :
                   "The square pattern is formed from some "
                   "sort of object that must have been pressed "
                   "on it hard enough or long enough to flatten "
                   "all that is left of the grass.",
                ({ "grass"}) :
                   "The grass is about eight inches in height. Its very "
                   "brown and appears to be quite sun burnt. Mixed "
                   "all through it is tall straw.",]) );
SetItemAdjectives( ([
          "field" : ({ "small", "barren", "sundried" }),
          "grass" : ({ "sun burnt", "burnt"}),
          "straw" : ({ "tall", "stringy", "brown", "very dried" }),         
          "opening" : ({"large"}),
          "pattern" : ({"square"}),
]) );
SetExits( ([ "north" : AVB_FIELD + "field2", 
             "south" : AVB_FIELD + "field4",
             "east" : AVB_FIELD + "field7",
             "southeast" : AVB_FIELD + "field8",
             "northeast" : AVB_FIELD + "field6",
        ]) );
SetSmell( ([ "default" : "The stale air has a foul burnt grass smell to it.", ])

 );
SetListen( ([ "default" : "The sound of crows echo through the air.", ]) );
SetInventory( ([ AVB_NPC + "moth" : 2+random(2),
           ]) );

}


varargs mixed eventDig(object who, string what) {
  object key = new(AVB_OBJ "square_key");

  if (!key) return "Digging doesn't reveal anything.";
  if (BeenDug) {
   who->eventPrint("The ground has recently been dug here. ");
   return 1;
   }
  send_messages( ({ "dig", "bend" }),
    "$agent_name $agent_verb into the dry dirt and then suddenly "
    "stop to $agent_verb over and pick something up.",
    who, 0, environment(who) );
  key->eventMove(who);
  message("action", "You uncover a key pressed deep into the dried "
                    "up dirt.",
      this_player() );
  BeenDug += 1;
  return 1;
}
