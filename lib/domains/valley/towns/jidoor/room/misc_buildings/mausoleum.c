/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor 
// Filename: mausoleum.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Feb 4th, 1999
// Abstract: This is the mausoleum in Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetShort("a dark mausoleum");
  SetLong("The city's mausoleum is dark and dreary looking. There are a "
       "few caskets on altars and some others resting on the marble floor. "
       "The mausoleum is remarkably free of cobwebs and dust and looks as "
       "thought someone has been taking care of it. There is a doorway "
       "leading out into the cemetery.");
  SetItems( ([ 
     ({"mausoleum"}) : (: GetLong :),
     ({ "doorway","door" }) : "The doorway simply leads out to the "
          "cemetery.",
     ({"floor","marble floor","marble"}) : "",
     ({"cemetery"}) : "The cemetery is just outside the door.",
     ({"casket","coffin","caskets","coffins"}) : "The caskets likely "
         "hold bodies of the deceased.",
     ({"cobwebs","webs","web","cobweb"}) : "There are very few cobwebs "
         "in the mausoleum and they are mostly confined to the dark "
         "corners of the room.",
  ]) );
  SetInventory( ([ 
      JID_NPC "/xloria" : 1,
              ]) );
  SetExits( ([ 
     "out" : JID_ROOM "/cemetery",
  ]) );
  SetListen( ([ 
      "default" : "It is deafeningly quiet in here.",
           ]) );
  SetSmell( ([ 
      "default" : "The room smells of musty rotting odors." 
           ] ));
}
