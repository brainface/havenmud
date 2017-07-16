/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: jail_cell.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: May 24th, 1999
// Abstract: This is the Jidoor City Jail Cell.
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_ROOM;
#include "../../jidoor.h"

static void create() {
  room::create();
  SetShort("inside a jail cell");
  SetClimate("indoors");
  SetExits( ([
    "north" : JID_ROOM + "/misc_buildings/jail",
    ]) );
  SetAmbientLight(25);
  SetProperty("no teleport", 1);
  SetProperty("no combat", 1);
  SetProperty("no attack", 1);
  SetProperty("no bump", 1);
  SetProperty("no magic", 1);
  SetLong("Very little light filters into this room.  It is plain, with "
         "furniture other than two bunkbeds attached to the east and "
         "west walls of the cell. In the center of the beds is a small "
         "bench with a hole in the center. The room is not filthy, but "
         "it is far from the cleanliness of the rest of the city of "
         "Jidoor.");
  SetItems( ([
     ({"cell","jail""room"}) : (: GetLong :),
     "hole" : "The hole is for bodily functions.",
     "bench" : "The bench has a small hole in the center on which one "
           "might take care of their bodily functions.  Sitting on the "
           "side of the bench is a small wash basin.",
     "basin" : "The small basin is available for criminals to at least "
           "maintain some form of sanitation while in the jail.",
     ({"furniture","bunkbed","bunkbeds","bed","beds"}) : "The bunkbeds "
         "are the only "
         "semi-clean space for someone to sleep in this cell. They are "
         "covered in a few sheets with one very stiff looking pillow "
         "at the southern ends of each bed.",
     ({"pillow","pillow"}) : "The pillows are hard."
    ]) );
  SetItemAdjectives( ([ 
    "cell" : ({"jail","plain"}),
    "hole" : ({"small"}),
    "bench" : ({"small"}),
    "basin" : ({"small","wash"}),
  ]) );
  SetDoor("north", JID_OBJ + "/jail_door");
  SetListen( ([ 
      "default" : "It is quiet here.",
           ]) );
  SetSmell( ([ 
      "default" : "The smell from the hole on the bench is repulsive.", 
      "hole" : "The smell of feces and other excrement is utterly "
               "disgusting." 
           ] ));

 }
