/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: main_tower.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Sept 17th, 1998
// Abstract: This is the temple of Zaxan Zimtafarous
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_CHAPEL;

int PreExit(string dir);

static void create() {
   chapel::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetTown("Jidoor");
   SetProperties( ([ "no bump" : 1 ]) );
   SetShort("the Temple of the Magildan");
   SetLong("The shimmering marble wall of the temple reflect light so "
           "brightly that it creates a strange visual effect of a "
           "hazy white glow inside the temple. A grand marble staircase "
           "spirals up the outside wall");
   SetExits( ([
      "out" : JID_ROOM "/temple/b",
   ]) );
   AddExit("up", JID_ROOM "/temple/boardroom", (: PreExit :));
   SetReligion("Magildan","Magildan");
   SetDeities( ({ "Zaxan" }) );
   SetClasses("mystic");
   SetItems( ([
      ({ "temple", "magildan church", "church", "tower"}) : (: GetLong :),
      ({ "spiral staircase", "staircase" }) :
         "A grand white marble staircase spirals up to the next level of "
         "the tower as it wraps its way around the wall.",
      ({ "marble","wall","walls","floor","ceiling" }) :
         "The white marble wall, floor and ceiling of the tower reflect "
         "light endlessly inside the tower. There is an abstract mural on "
         "the circular wall of the tower.",
      ({"mural"}) : "The mural depicted on the wall is totally abstract "
         "and doesn't seem to have a beginning or ending but merely wraps "
         "around the wall of the tower in a continous display of colors "
         "and patterns. Some say that the mural symbolizes the form of "
         "Zaxan Zimtafarous himself.",
   ]) );
   SetItemAdjectives( ([
      "mural" : ({ "abstract" }),
      "wall" : ({ "white", "marble" }),
      "floor" : ({ "white", "marble" }),
      "ceiling" : ({ "white", "marble" }),
      "marble" : ({ "white" }),
      "staircase" : ({ "spiral","marble","white" }),
   ]) );
   SetInventory( ([
      JID_NPC "/nervala" : 1,
      JID_NPC "/malkus" : 1,
      JID_OBJ "/magildan_sculpture" : 1,
   ]) );
}
// meh
int PreExit(string dir) {
  if(!creatorp(this_player()) ) {
      send_messages("slam",
         "$agent_name $agent_verb into a wall of force blocking "
         "$agent_objective from going " + dir + ".",
           this_player(), 0, environment(this_player()) );
      return 0;
   }
  return 1;
 }
