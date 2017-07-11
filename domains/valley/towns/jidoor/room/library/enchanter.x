/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: enchanter.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Oct 23rd, 1998
// Abstract: This is the enchanter section of the tower of the Great Library 
//           of Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetAmbientLight(60);
   SetClimate("indoors");
   SetShort("the Enchanter's Section of the Great Library of Jidoor");
   SetLong("This section of the tower is obviously for the study of the art "
           "of enchantment. A large marble staircase leads up into the "
           "tower and down to the evoker's section of the library. "
           "Paintings line the walls to decorate the area. Various tables, "
           "chairs and couches are placed about randomly for people to sit "
           "and study books lining various shelves in the room.");
   SetItems( ([
      ({ "building", "library", "library of jidoor","section","tower"}) : 
         (: GetLong :),
      ({"paintings","painting"}) : "One could spend hours here enjoying "
         "wonderous paintings of the library.  Several are abstract "
         "paintings and others depict landscapes, and still others are "
         "portraits of people.",
      ({"shelves","shelf","shelves of books"}) : "The shelves of this "
          "section match those of the rest of the library and are placed "
          "along the walls. A few added shelves rest in the center of "
          "the room.",
      ({"book","books"}) : "The books lining the shelves are all "
          "concerned with the study of enchantment, the most manipulative"
          "of the magical arts.",
      ({"chairs", "chair","table","tables","couches","couch"}) : "The "
          "various tables, chairs and couches are comfortable looking "
          "and suit the "
          "needs of anyone wishing to research the lore of the various"
          "books on the art of enchantment.",
      ({"walls","wall" }) : "The circular walls of the tower are lined "
          "with shelves of books.",
      ({"floor","ceiling" }) : "The floor and ceiling are both made from "
          "a green marble that casts an eerie glow around the room.",
      ({"staircase","stairs"}) : "The staircase is literally huge and "
          "reflects the light in the room casting an erie but pleasant "
          "radiance.  It leads up into the tower as well down into the "
          "evoker's section.",
          ]) );
   SetItemAdjectives( ([
      "building" : ({ "beautiful" }),
      "library" : ({"beautiful","great" }),
      "staircase" : ({"large","marble"}),
      "shelves" : ({"various"}),
   ]) );
   SetExits( ([ 
      "down" : JID_ROOM "/library/evoker",
/*
      "up" : JID_ROOM "/library/planar",
*/
   ]) );
  SetInventory( ([
                   JID_NPC "/dolad" : 1,
                   JID_NPC "/porcil" : 1,
              ]) );
  SetListen( ([ "default" : "The library is quiet except for the "
                  "occasional sound of someone else working in the "
                  "library." ]) );
  SetSmell( ([ "default" : "The smell of old books is heavy in the "
                  "air but the area smells fresh and new." ]) );
}
