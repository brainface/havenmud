/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: citizens_room.c
// Author: Derek Noble
// Sage: dylanthalus@haven
// Creation Date: December 4th, 1998
// Abstract: City Hall Citizen's Room
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("The Citizen's Area of Jidoor City Hall");
  SetDayLong("The citizen's area is a modestly furnished area with a great "
             "with a couple of couches for citizens to sit around and "
             "discuss local politics. A small voting booth is set up " 
             "for players to vote on things when the local government is "
             "requesting their opinion.  A message board is also set up "
             "for the citizen's of the city only so they can discuss "
             "issues in secrecy without outsiders.  Sunlight enters the "
             "room from a window overlooking the town's square.");
  SetNightLong("The citizen's area is a modestly furnished area with a great "
             "with a couple of couches for citizens to sit around and "
             "discuss local politics. A small voting booth is set up " 
             "for players to vote on things when the local government is "
             "requesting their opinion.  A message board is also set up "
             "for the citizen's of the city only so they can discuss "
             "issues in secrecy without outsiders.  Moonlight enters the "
             "room from a window overlooking the town's square.");
  SetItems( ([ 
      ({ "city hall","hall" }) : (: GetLong :),
      ({ "window" }) : "The window overlooks the town square.",
      ({ "couch","couches" }) : "These couches look to be comfortable.",
      ({ "grand staircase", "staircase" }) : 
           "The staircase is made from a red colored marble.",
          ]) );
  SetListen( ([ "default" : "Few sounds enter into the peacefulness of "
                 "the meeting room."
            ]) );
  SetSmell( ([ "default" : "The air in the room holds no distinctive "
                 "smell."
          ] ));
  SetNewsgroups( ({ "town.jidoor" }) );
  SetInventory( ([ 
      JID_OBJ "/voting_booth" : 1,
  ]) );
  SetExits( ([ 
     "down" : JID_ROOM "/cityhall/foyer",
  ]) );
  SetDomain("Valley");
}
