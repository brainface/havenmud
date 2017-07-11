/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: jail.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: May 24th, 1999
// Abstract: This is the Jidoor City Jail
/* ----------------------------------------------------------------------- */


#include <lib.h>
inherit LIB_ROOM;
#include "../../jidoor.h"

static void create() {
  room::create();
  SetShort("Jidoor City Jail");
  SetClimate("indoors");
  SetExits( ([
    "south" : JID_ROOM + "/misc_buildings/jail_cell",
    "out" : JID_ROOM + "/road11",
    ]) );
  SetAmbientLight(40);
  SetLong("The city jail of Jidoor is a small building and it is "
         "fairly obvious by it's size that Jidoor does not have "
         "a problem with crime.  On the southern wall, a large "
         "braced door leads into the jail's only cell.");
  SetItems( ([
     ({"building","jail""room"}) : (: GetLong :),
       "stench" : "You cannot see a stench.",
    ]) );
  SetItemAdjectives( ([ 
    "jail" : ({"plain","small"}),
  ]) );
  SetDoor("south", JID_OBJ + "/jail_door");
  SetListen( ([ 
      "default" : "It is quiet here.",
           ]) );
  SetSmell( ([ 
      "default" : "A slight stench comes from the jail cell.",
      "stench" : "Concentrating on the stench, you determine that "
                 "it smells like feces even though it is faint."
           ] ));

 }
