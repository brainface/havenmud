//  For possible future use
//  Magic Shop for Malv Marketplace
//  Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("the Magic Shop");
  SetLong(
     "Large bookshelves line the walls of this shop, stuffed to almost "
     "over flowing with books and scrolls and various arcane goods. A small "
     "counter sits towards the back of the room and is covered in boxes of "
     "more books and scrolls. Display cases have been set up in the middle of "
     "the store, but as yet they lie empty. A small staircase leads upwards "
     "to another shop."
     );
  SetSmell( ([
     "default" : "The mingling of wax and incense fills the air.",
     ]) );
  SetListen( ([
     "default" : "The shop is eerily quiet.",
     ]) );
  SetItems( ([
     ({"store", "shop", "room"}) : (:GetLong:),
     ({"bookshelf", "bookshelves", "shelf", "shelves"}) :
     	 "Handcrafted from wood, these bookshelves are plain and sturdy looking. "
     	 "They are stuffed with books and scrolls of all sizes, as well as "
     	 "various orbs and trinkets.",
     ({"goods", "orbs", "trinkets", "orb", "trinket", "objects"}) :
     	 "Various objects lie scattered about the bookshelves, some small clear "
     	 "orbs of glass, others larger and colored. They all must have some use "
     	 "but only those practiced in magic may know how to use them.",
     ({"case", "cases", "display", "display cases"}) :
     	 "The cases are made of wood, but covered in glass so that one might "
     	 "get a good look at the contents inside, unfortunately all the "
     	 "display cases here are empty.",
     ({"book", "books", "scroll", "scrolls"}) :
     	 "Books of all sizes line the shelves in this shop, some appear to be "
     	 "extremely old and in alarming condition. The scrolls are wedged "
     	 "between and on top of the books.",
     ({"box", "boxes"}) :
     	 "Large boxes stack on top of each other on the counter. A few are "
     	 "open and contain more books and scrolls.",
     ({"counter"}) :
     	 "The counter is very tidy aside from boxes which are stacked on top "
     	 "of it.",
     ({"stairs", "stairway"}) :
     	 "A narrow stairway that climbs up to another room on the second floor.",
     ({"floor", "ground"}) :
     	 "The floor is clean and neat, aside from a few boxes.",   
     ({"wall", "walls"}) : 
     	 "The walls are lined with large bookshelves, which hold many books "
     	 "and scrolls.",
     ]) );
  SetItemAdjectives( ([
     "shelf" : ({"wood", "wooden", "stuffed", "plain", "sturdy"}),
     "wall" : ({"lined"}),
     "goods" : ({"various", "small", "clear", "colored"}),
     "case" : ({"wood", "covered", "empty"}),
     "book" : ({"old", "large", "small"}),
     "floor" : ({"clean", "neat"}),
     "box" : ({"stacked", "open"}),
     "counter" : ({"tidy"}),
     "stairway" : ({"narrow"}),
     ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "out" : MAL_ROOMS3 + "market5",
     "up" : MAL_ROOMS3 + "gemshop",
     ]) );



}
