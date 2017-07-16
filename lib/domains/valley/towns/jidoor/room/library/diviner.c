/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: diviner.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: November 2nd, 1998
// Abstract: This is the diviner section of the tower of the Great Library 
//           of Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

string CheckTime();

static void create() {
   room::create();
   SetAmbientLight(60);
   SetClimate("indoors");
   SetShort("the Diviner's Section of the Great Library of Jidoor");
   SetLong("The ceiling of the Diviner's Section of the Great Library "
           "is made from some unique substance allowing the caster to "
           "gaze out at the sky overhead.  There are various shelves of "
           "books lining the walls, as well as a very shelves placed in "
           "and about the center of the room. Tables, chairs and couches "
           "are also "
           "set up for those wishing to study and relax in the peaceful "
           "library.  A marble staircase leads down into the enchanter's "
           "section."
          );
   SetItems( ([
      ({ "building", "library", "library of jidoor","section","tower"}) : 
         (: GetLong :),
      ({ "ceiling" }) : "The ceiling of the tower is made of some glossy "
         "material, making it possible to hold out nature's elements, but "
         "allow sight to pass through.",
      ({ "sky" }) : (: CheckTime :),
      ({"paintings","painting"}) : "One could spend hours here enjoying "
         "wonderous paintings of the library.  Several are abstract "
         "paintings and others depict landscapes, and still others are "
         "portraits of people.",
      ({"shelves","shelf","shelves of books"}) : "The shelves of this "
          "section match those of the rest of the library and are placed "
          "along the walls. A few added shelves rest in the center of "
          "the room.",
      ({"book","books"}) : "The books lining the shelves are all "
          "concerned with the study of divination, the most invasive"
          "and mentally challenging of the magical arts.",
      ({"chairs", "chair","table","tables","couches","couch"}) : "The "
          "various tables, chairs and couches are comfortable looking "
          "and suit the "
          "needs of anyone wishing to research the lore of the various"
          "books on the art of enchantment.",
      ({"walls","wall" }) : "The circular walls of the tower are lined "
          "with shelves of books.",
      ({"floor"}) : "The floor and ceiling are both made from "
          "a green marble that casts an eerie glow around the room.",
      ({"staircase","stairs"}) : "The staircase is literally huge and "
          "reflects the light in the room casting an erie but pleasant "
          "radiance.  It leads down into the enchanter's section.",
          ]) );
   SetItemAdjectives( ([
      "building" : ({ "beautiful" }),
      "library" : ({"beautiful","great" }),
      "staircase" : ({"large","marble"}),
      "shelves" : ({"various"}),
   ]) );
   SetExits( ([ 
      "down" : JID_ROOM "/library/planar",
   ]) );
  SetInventory( ([ JID_NPC "/valora" : 1,
                   JID_NPC "/parcil" : 1,
              ]) );
  SetListen( ([ "default" : "The library is quiet except for the "
                  "occasional sound of someone else working downstairs."
            ]) );
  SetSmell( ([ "default" : "The smell of old books is heavy in the air."
          ] ));
}


string CheckTime() {

  if( query_night() ) 
    {
    return "The stars are beatiful and apparently magnified by the "
           "material the ceiling is made from.";
    }
  else
    {
    return "The clouds are rolling across the daytime sky.";
    }
}
