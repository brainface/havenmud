//
// The Nanivant Gem Shop
// Created by Zaxan@Haven
// Stolen by Davantalus@Haven
//

#include <lib.h>
#include "../mal.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetAmbientLight(60);
   SetClimate("indoors");
   SetTown("Malveillant");
   SetProperties( ([
      "no bump" : 1,
   ]) );
   SetShort("the Malveillant Gem Shop");
   SetLong("This is the Malveillant Gem Shop. A large display case by "
           "the wall shows many different gems that are available "
           "to buy. The lights in the display case shine down on "
           "them, making them sparkle with beauty. This entire "
           "shop has been made nicely with all of the cases and "
           "counters coated with clear glass. The curtains over the "
           "windows are a very pretty red velvet.");
   SetExits( ([ 
      "out" : MAL_ROOMS3 "center3",
   ]) );
   SetInventory( ([ 
      MAL_NPC "aurian" : 1,
   ]) );
   SetItems( ([ 
      ({ "display case", "case" }) : 
         "This large display case has many different types of gems in it. "
         "There is a little price tag attatched to the back of each gem.",
      ({ "wall", "walls" }) : 
         "The walls in this room are very plain. There are a couple windows "
         "in the walls and a display case sitting by it.",
      ({ "gem", "gems" }) : 
         "The gems are inside the display case.",
      ({ "light", "lights" }) : 
         "These lights in the display case make the gems sparkle with"
          " beauty.",
      ({ "counter", "counters" }) : 
         "The shopkeeper is sitting behind this nice counter made of wood.",
      ({ "tag", "tags" }) : "You can't quite make out the prices. Why not ask"
          " the shopkeeper?",
      ({ "glass" "clear glass" }) : "The glass is clear and free from imperfections.",
      ({ "curtain", "curtains" }) : 
         "These curtains are made of a fine red velvet.",
      ({ "window", "windows" }) : 
         "These windows are very plain. They are somewhat covered by "
         "curtains.",
   ]) );
   SetItemAdjectives( ([
      "case" : ({ "display" }),
   ]) );
}
