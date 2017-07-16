/*   Portia  12-11-98
     The royal tutor's room.
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a small study");
 SetClimate("indoors");
 SetExits( ([
   "west" : MAL_ROOMS + "throne",
   "north" : MAL_ROOMS + "mage",
   ]) );
 SetListen( ([
   "default" : "A slight hum can be heard from "
       "the west.",
   ]) );
 SetSmell( ([
   "default" : "There is a faint scent of food.",
   ]) );
 SetInventory( ([
   MAL_NPC + "royal_tut" : 1,
   ]) );
 SetLong("This study is quite cozy. It belongs to "
   "the royal tutor who is charged with educating the "
   "citizens of Malveillant. A large desk sits near "
   "the fireplace and a small window has been carved out "
   "of the wall. Other than these sparse furnishings, and "
   "the books that line the walls, the study is completly "
   "bare.");
 SetItems( ([
   "study" : (:GetLong:),
   "desk" : "The large desk is full of books.",
   "fireplace" : "The fireplace is aglow with warmth.",
   "window" : "The small window is carved from the "
       "obsidian wall.",
   "furnishings" : "The furnishings are quite sparse.",
   ({"books", "book"}) : "The books are everywhere.",
   ({"walls", "wall"}) : "The walls are made of obsidian.",
   ]) );
 SetItemAdjectives( ([
   "study" : "cozy",
   "desk" : "large",
   "fireplace" : "aglow",
   "window" : "small",
   "furnishings" : "sparse",
   "wall" : "obsidian",
   ]) );
 }
