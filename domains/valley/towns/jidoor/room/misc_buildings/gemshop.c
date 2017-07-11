//
// The Jidoor Gem Shop
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetAmbientLight(60);
   SetClimate("indoors");
   SetTown("Jidoor");
   SetProperties( ([
      "no bump" : 1,
   ]) );
   SetShort("the Jidoor Gem Shop");
   SetLong("This is the Jidoor Gem Shop. A large display case by "
           "the wall shows many different gems that are available "
           "to buy. The lights in the display case shine down on "
           "them, making them sparkle with beauty. This entire "
           "shop has been made nicely with all of the cases and "
           "counters coated with rupies. The curtains over the "
           "windows are a very pretty red velvet.");
   SetExits( ([ 
      "down" : JID_ROOM "/misc_buildings/genstore",
   ]) );
   SetInventory( ([ 
      JID_NPC "/auralia" : 1,
   ]) );
   SetItems( ([ 
      ({ "display case", "case" }) : 
         "This large display case has many different types of gems in it. "
         "There is a little price tag attatched to the back of each gem. It "
         "is nicely coated with rupies.",
      ({ "wall", "walls" }) : 
         "The walls in this room are very plain. There are a couple windows "
         "in the walls and a display case sitting by it.",
      ({ "gem", "gems" }) : 
         "The gems are inside the display case.",
      ({ "light", "lights" }) : 
         "These lights in the display case make the gems sparkle with beauty.",
      ({ "counter", "counters" }) : 
         "The shopkeeper is sitting behind this nice counter that is "
         "coated with rupies.",
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
