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
  SetPreventGet("The view is for everyone!");
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
    who->eventPrint("Beyond the minaret the vast "
      "Yozrath Desert expands out until it is swallowed "
      "by shadow.");
  } else {
    who->eventPrint("The vast glory of the Yozrath Desert expands "
      "out beyond the minaret and its flora.  A monastery can "
      "be seen to the north while the city of Yozrath can be seen to "
      "the southwest.  Heat waves from the sun make it "
      "difficult to judge where the sands end from where the horizon "
      "begins, save the northern borders where the River Bjorn flows swiftly.");
  }
  return 1;
}

