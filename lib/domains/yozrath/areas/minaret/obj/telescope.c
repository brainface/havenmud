// Heeyyy torak.
// this should work.
// maybe?
#include <lib.h>
inherit LIB_ITEM;

int look(string dir);
int showViewTo(object player);

// I don't think anyone can ever look view.
// if they try to get it, fuck them.

static void create() {
  item::create();
  SetKeyName("telescope");
  SetShort("a telescope");
  SetLong("This telescope is an impressive "
    "device.  It is almost as large as the observatory "
    "and is made of some form of resin material.  "
    "Large shield shaped pieces of glass bring "
    "the view into focus.  It is possible to, 'look "
    "through telescope.'");
  SetPreventGet("The telescope is too large!");
  SetPreventDrop("You cannot drop that!");
  SetPreventPut("You cannot put that there!");
}

// set us up the bomb

void init() {
  item::init();
  add_action("look","look");
}

// override look, providing different output
// if someone looks at the view

int look(string dir) {
  if ( (dir == "through telescope") ) {
    return showViewTo(this_player());
  }
  else return 0;
}

// show correct day or night description
int showViewTo(object who) {
  if(query_night()) {
    who->eventPrint("The telescope is positioned "
      "perfectly to view the constellation, 'The Magus'  "
      "which is the constellation most associated "
      "with Zaxan, the Lord of Magic and Energy.  "
      "The view of 'The Magus' is crystal clear and "
      "shows all 7 stars brilliantly.");
  } else {
    who->eventPrint("The sun shines too brightly to use this right now!");
  }
  return 1;
}

