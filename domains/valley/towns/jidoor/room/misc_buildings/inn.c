/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Inn
// Filename: inn.c
// Author: Derek Noble
// Immortal: zaxan@haven, dylanthalus@haven
// Creation Date: December 11th, 1998
// Abstract: This is part of the main street of Jidoor.
// Revision History: Originally Created by Zaxan@Haven
//                   Recoded entirely by Dylanthalus@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetProperty("no attack",1);
  SetProperty("no bump", 1);
  SetProperty("no attack", 1);
  SetProperty("no steal", 1);
  SetShort("Jidoor City Inn");
  SetLong("This small inn sitting in the heart of Jidoor has been "
           "provided for all of the weary travellers in the world. "
           "Everything about the room smells and looks clean. The "
           "room seems to emanate an aura of peace and seems as though it "
           "would be a safe place for tired mages to rest. ");
  SetItems( ([ 
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetExits( ([ 
     "out" : JID_ROOM "/road4",
//      "east" : JID_ROOM "/misc_buildings/player_inn",
  ]) );
}
