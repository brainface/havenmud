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
  SetKeyName("view object");
  SetInvis(2);
  SetShort("a view object");
  SetLong("This is a view object.");
  SetPreventGet("You cannot take that!");
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
  if ( (dir == "view"||dir=="the view"
    ||dir == "at the view"
    ||dir == "at view" ) ) {
    return showViewTo(this_player());
  }
  else return 0;
}

// show correct day or night description
int showViewTo(object who) {
  if(query_night()) {
    who->eventPrint("The fires from the village cast shadows across "
      "the tall walls.  The reflection of the moons dance across the "
      "shimmering pond.");
  } else {
    who->eventPrint("From here the village rooftops begin to look "
      "smaller and and the sun glistens off the pond, casting shadows "
      "of the villagers on the tall walls.");
  }
  return 1;
}
