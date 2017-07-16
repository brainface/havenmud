//--    Torak@Haven    --//
//-- Obsidian Apostles --//

#include <lib.h>
#include "obsidian.h"
inherit LIB_ROOM;
int AcceptableCheck();

static void create() {

  room::create();
  SetDomain("Estergrym");
  SetClimate("indoors");
  SetShort("The main hall");
  SetLong("This room is very large with dark tapestries "
          "hanging on the walls.  The floor is black "
          "marble and shines with a wax coating.  Huge "
          "white marble pillars rise out from the floor "
          "to grasp the ceiling with ease.  A smaller "
          "hallway leads out to another room.");
  SetItems( ([
    ({ "room", "hall", "marble" }) :
       (: GetLong :),
    ({ "tapestries" }) :
       "The tapestries hanging on the wall depict the "
       "destruction of all that is good on Kailie, and "
       "start of an era of evil across the land.",
    ({ "wall", "walls" }) :
       "The walls are painted black and give an aura "
       "of evilness through the hall.",
    ({ "floor" }) :
       "The floor of the hall shines from the wax that "
       "makes the black marble glisten darkly.",
    ({ "pillar", "pillars" }) :
       "These huge pillars seem to keep the entire ceiling "
       "of the hall up, as they are a good ten feet in "
       "diameter and seem to go further down than the floor.",
    ({ "ceiling" }) :
       "The ceiling rests very high atop the hall.",
    ({ "hallway" }) :
       "The hallway leads to another room which seems blocked "
       "off to those who do not belong there.",
    ]) );
  SetInventory( ([
    OBSIDIAN + "guard" : 3,
    ]) );
  SetExits( ([
    "out" : OBSIDIAN + "start",
    ]) );
  AddExit("north", OBSIDIAN + "oa", (: AcceptableCheck :) );
  }

int AcceptableCheck() {
  object who = this_player();
  object guard = present("guard", this_object());

  if (!immortalp(this_player())) {
    if (!guard) return 1;
    if (who->GetGuild() != "apostles") {
      message("system", who->GetName() + " tries to go north.",
          this_object());
      guard->eventForce("say you are not permitted to enter there.");
      return 0;
      }
    return 1;
    }
  return 1;
  }
