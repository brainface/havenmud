//
// The Divine Chalice
// Filename: tavern.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the Divine Chalice");
  SetNewsgroups( ({ "player.general" }) );
   SetClimate("indoors");
   SetAmbientLight(55);
   SetExits( ([
      "out" : H_ROOM + "wharf",
      "up"  : H_ROOM + "shops/rogue",
   ]) );
   SetInventory( ([
      H_NPC + "brook" : 1,
      H_NPC + "citizen" : 1,
   ]) );
   SetLong("The Divine Chalice is a far cry from the former tavern "
           "that occupied this place in town. Its clean walls and "
           "floor are spotless in their cleanliness, and the tables "
           "and benches are sanded to perfection. Along the east wall "
           "a bar stretches from the north wall to the south wall, "
           "and its polished steel surface gleams in the light that "
           "glows from the magical glow globes hanging on the walls.");
   SetItems( ([
      ({ "chalice", "tavern" }) :
         (: GetLong :),
      ({ "wall", "walls" }) : 
         "The walls of the Divine Chalice are painted white and no "
         "dirt mars their surface.",
      ({ "floor", "floors" }) : 
         "The floor of the tavern is spotless, obviously cleaned "
         "quite often.",
      ({ "bar" }) : 
         "The bar runs from north wall to south, and gleams in the "
         "light of the glow globes.",
      ({ "globe", "globes", "object", "objects" }) : 
         "The glow globes are simple magical objects that give "
         "off light.",
      ({ "table", "tables" }) : 
         "The tables are simple yet elegant, each precisely arranged "
         "to make the tavern appear larger than it is.",
      ({ "bench", "benches" }) : 
         "The benches are smooth and made of a softwood which is "
         "easy to sit on and does not splinter.",
      ({ "surface" }) :
         "The surface of the bar gleams in the light.",
   ]) );
   SetItemAdjectives( ([
      "globe" : ({ "glow", "magical" }),
      "wall" : ({ "white", "clean" }),
      "floor" : ({ "spotless", "clean" }),
      "table" : ({ "simple", "elegant" }),
      "bench" : ({ "smooth" }),
      "surface" : ({ "polished", "steel" }),
   ]) );
   SetSmell( ([
      "default" : "The scents of mulled wine and warmed ale fill the "
                  "tavern.",
   ]) );
   SetListen( ([
      "default" : "The cheery din of conversation warms the room.",
   ]) );
}

/* Approved by Haun on Tue Apr 27 21:17:46 1999. */
