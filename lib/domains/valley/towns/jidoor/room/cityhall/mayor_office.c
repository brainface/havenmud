/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: mayor_office.c
// Author: Derek Noble
// Sage: dylanthalus@haven
// Creation Date: December 4th, 1998
// Abstract: The Mayor's Office in Jidoor
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
  SetAmbientLight(40);
  SetShort("The Mayor of Jidoor's Office");
  SetLong("The mayor's office is a richly furnished area with a soft "
          "carpet on the floor and extravagantly decorated walls.  A "
          "stunning oak desk sits facing the stairs with a large "
          "comfortable looking chair behind it.  In front of it are two "
          "nice chairs, both facing the desk.  Behind the mayor's desk "
          "is a beautiful landscape picture of Jidoor painted from "
          "somewhere high above the city up in the Crystal Reaches that "
          "lie north of the city.  The only source of light in the room "
          "is from two globes of light hanging from the ceiling.");
  SetItems( ([
      ({ "area","mayors office", "office",
         "city hall","hall" }) : (: GetLong :),
      ({"ceiling"}) : "The covered with a wooden finish and gives no "
          "hint that this room is actually a basement.",
      ({"chair","chairs"}) : "The chairs of the room look comfortable "
          "and sturdy.",
      ({"desk"}) : "The mayor's desk is a fine piece of furniture and "
          "is the focal point of the room.",
      ({"carpet","floor"}) : "The floor of the office is covered in a "
          "soft, beige carpet",
      ({"walls","wall"}) : "The walls are decorated with various works "
          "of art.",
      ({"picture","landscape","landscape picture"}) : "",
      ({"art","works of art"}) : "In theme with the rest of the "
          "buildings in Jidoor, the office of the mayor is no different "
          "containing many pictures of fine art.",
      ({"globe","globes"}) : "The globes hanging from the citizen cast "
          "a fair degree of light.",
      ({ "grand staircase", "staircase" }) :
           "The staircase is made from a red colored marble.",
      ({ "globes","globe" }) :
           "Hanging globes are the primary source of lighting at night.",
          ]) );
  SetItemAdjectives( ([
      "landscape" : ({ "beautiful"}),
      "desk" : ({ "mayors","stunning","oak"}),
      "chair" : ({ "nice","comfortable looking"}),
      "globe" : ({ "hanging"}),
      "carpet" : ({ "soft"}),
                   ]) );
  SetExits( ([
     "up" : JID_ROOM "/cityhall/foyer",
  ]) );
  SetListen( ([ "default" : "Few sounds penetrate the silence of the "
                           "office."
            ]) );
  SetSmell( ([ "default" : "The air smells fresh here in the basement "
                          "office of the city hall, likely the work of "
                          "some enchanter."
          ] ));
  SetInventory( ([
      JID_NPC "/mingad" : 1,
      JID_NPC "/sentry" : 2,
  ]) );
}

