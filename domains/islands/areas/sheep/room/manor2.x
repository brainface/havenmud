#include <lib.h>
#include "../sheep.h"
inherit LIB_ROOM;
string SearchShelves();
int SearchComplete;

static void create() {
  ::create();
  SetShort("a small library");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetLong(
   "The manor library is a well-furnished affair with soft cushions and books lining the walls. "
   "Off to the west the manor house opens up to the main fields. The bookshelves around the room "
   "appear to mainly consist of black-bound books and scrolls of a deviant nature."
  );
  SetItems( ([
    ({ "cushion", "cushions" }) : "The cushions appear to be well crafted, soft seats lined with "
                                  "gold flecked material.",
    ({ "book", "bookshelves", "books", "shelves", "shelf" }) : "The bookshelves are covered with "
                                  "evil looking books too extensive to preview at a mere glance.",
    ]) );                                  
  SetSearch("book", (: SearchShelves :) );    
  SetExits( ([
    "west" : "manor1",
  ]) );
  SetInventory( ([
    SHEEP_NPC "necromancer" : 1,
  ]) );
  SearchComplete = 0;
  SetSmell("The scent of dust on the books is light and oddly friendly.");
  
}

string SearchShelves(object who) {
   object scroll = new(SHEEP_OBJ + "book");
   object gladia = present("gladia", this_object());
   
   if (living(gladia)) {
     gladia->eventForce("speak You may not view my books without my consent!");
     return "Lady Gladia prevents your search.";
    }
   send_messages("search", "$agent_name $agent_verb through the various books on the shelves.", who, 0, this_object());
   if (SearchComplete) {
    return "The room appears to have been previously ransacked.";
   }
   if (!scroll->eventMove(who)) scroll->eventMove(this_object());
   SearchComplete = 1;
   return "You discover a black-bound book which is cool to the touch.";
}
