/* The remains of an inn - made by Sardonas */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the forgotten inn");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetExits( ([
     "out"  : ROOM "/ruins4",
     "west" : ROOM "/smithy",
  ]) );

  SetLong("The old inn has seen better days, and better customers.  Delicate "
          "webs hang ghost-like throughout the inn.  A layer of dust covers "
          "everything and reacts to the slightest breeze.  The decorations "
          "of the room are aged, and faded.  Fallen timbers block the stairs "
          "to the second floor. Bits of ash float in from a doorway to the west.");

  SetItems( ([
    ({ "the forgotten inn", "forgotten inn", "inn", "room", "old inn" })  :
       (: GetLong :),
    ({ "decorations", "decoration" })  :
       "The decorations are very old, and would be valuble, if they were in "
       "good condition.  The carpet is frayed and faded, and the paintings "
       "are chipped and damaged.  Dust covers everything.",
    ({ "layer of dust", "dust" })  :
       "A thick layer of grey dust makes everything look old and bland.",
    ({ "painting", "paintings" })  :
       "The paintings of the inn are very old and chipped.  Small squares of "
       "paint are all that remain of these once grand paintings.",
    ({ "small squares of paint", "small square of paint", "small squares",
       "small square", "square", "squares" })  :
       "Small chips of paint are all that remain of the paintings.  Their "
       "colors seem to suggest light and plants.",
    ({ "carpet" })   :
       "The carpet may have had a beautiful design at one time.  Now it's "
       "faded and badly worn.",
    ({ "beautiful design", "design" })  :
       "The design of the carpet may have been a woodland scene but now, "
       "it's too faded to tell.",
    ({ "woodland scene", "scene" })  :
       "The woodland scene is too faded to see.",
    ({ "delicate web", "delicate webs", "web", "webs" })  :
       "The delicate webs are small and wispy.",
    ({ "stairs", "stair" })  :
       "The stairs to the second floor are blocked by fallen timbers.",
    ({ "fallen timber", "fallen timbers", "timber", "timbers" })   :
       "Fallen timbers lie on the stairs, blocking access to the upper "
       "floors.",
    ({ "bits", "ash","bits of ash", "doorway", "courtyard" }) :
       "Someone is apparently tending a fire in the courtyard of the inn."
  ]) );

  SetListen( ([
    "default"  : "The ceiling creaks under its own weight.",
  ]) );

  SetInventory( ([
     NPC "/koboldf" : 2,
     NPC "/kobold_childm" : 1,
     NPC "/rogue" : 1,
  ]) );
}

