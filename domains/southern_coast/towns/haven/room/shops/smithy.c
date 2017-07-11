//
// Naythen's Smithy
// Filename: smithy.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Naythen's Smithy");
   SetClimate("indoors");
   SetAmbientLight(50);
   SetExits( ([
      "out" : "../merchants_way/mw3",
   ]) );
   SetLong("The dark, ashen walls and floor greet anyone that enters \n"
           "this shop.  The smithy of Haven Town is a prosperous business \n"
           "that supplies the town with metal goods, especially for those \n"
           "that need armour of some kind.  The forge is a huge structure \n"
           "of stone and mortar which towers to the roof.");
   SetItems( ([
      ({ "forge", "structure" }) : 
         "The forge is a large structure that is big enough for a large "
         "creature to fit into.",
      ({ "wall", "walls", "floor", "floors" }) :
         "The walls and floors of this shop are dark and ashen. They seem "
         "to be greeting to anyone that enters here.",
      ({ "business", "smithy", "shop" }) :
         (: GetLong :),
      ({ "good", "goods", "armour" }) :
         "This shop is one that is looked upon for many metal goods and "
         "many armour types.",
   ]) );
   SetItemAdjectives( ([
      "forge" : ({ "huge", "large" }),
      "wall" : ({ "dark", "ashen" }),
      "smithy" : ({ "naythen's" }),
      "good" : ({ "metal", "many" }),
   ]) );
   SetEnters( ([ 
      "forge" : H_ROOM + "shops/forge",
   ]) );
   SetInventory( ([ 
      H_NPC + "naythen" : 1,
   ]) );
   SetProperties( ([
      "metal working" : 1,
      "natural working" : 1,
      "wood working" : 1,
      "leather working" : 1,
      "textile working" : 1,
      "mithril working" : 1,
   ]) );
}


/* Approved by Haun on Tue Apr 27 21:17:22 1999. */
