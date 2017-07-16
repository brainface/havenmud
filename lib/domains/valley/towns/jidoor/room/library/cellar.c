/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: cellar.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Oct 23rd, 1998
// Abstract: This is the cellar of the Great Library of Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetAmbientLight(45);
   SetClimate("indoors");
   SetShort("the cellar of the Great Library of Jidoor");
   SetLong("The cellar is dark and dismal looking but clean none the "
           "less. Torches placed along the walls emit some degree of "
           "light but keep the room dark.  Books line various shelves "
           "in the room and a few plain chairs and tables have been "
           "set up in order for people to study.");
   SetItems( ([
      ({ "building", "library", "library of jidoor","cellar","room" }) : 
         (: GetLong :),
      ({"torch","torches"}) : "A few torches are the only source of "
          "light in this dismal cellar. They barely cast enough light "
          "to read.",
      ({"shelves","shelf","various shelves"}) : "The shelves of the "
          "cellar match those of the rest of the library and are placed "
          "along the walls.  A few added shelves rest in the center of "
          "the cellar.",
      ({"book","books"}) : "The books lining the shelves are all "
          "concerned with the study of necromancy, the darkest of all "
          "the magical arts.",
      ({"chairs", "chair","table","tables"}) : "The various tables and "
          "chairs of the cellar are uncomfortable looking but suit the "
          "needs of anyone wishing to research the lore of the dark "
          "books of the black art of necromancy.",
      ({"walls","wall"}) : "The walls are circular and darkened.",
      ({"staircase","stairs"}) : "The staircase is literally huge and "
          "reflects the light in the room casting an erie but pleasant "
          "radiance.  It leads up into the tower.",
          ]) );
   SetItemAdjectives( ([
      "staircase" : ({"large","marble"}),
      "chairs" : ({"plain","comfortable looking"}),
      "cellar" : ({"clean","dark","dismal looking"}),
   ]) );
  SetInventory( ([ JID_NPC "/hima" : 1,
                   JID_NPC "/purcil" : 1,
              ]) );
  SetExits( ([ 
      "up" : JID_ROOM "/library/tower",
   ]) );
  SetListen( ([ "default" : "The cellar is very quiet." ]) );
  SetSmell( ([ "default" : "The cellar smells musty." ]) );
}
