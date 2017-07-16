#include <lib.h>
#include <std.h>
#include <rooms.h>
inherit LIB_ROOM;
int Newbie();

static void create() {
	::create();
  SetShort("in the skies above Kailie");
	SetExits( ([
        "east" : "/domains/staff/staffroom",
	  ]) );
  AddExit("down", "/domains/staff/room/setup", (: Newbie :) );
  SetObviousExits("down");
	SetProperty("no weather", 1);
	SetClimate("indoors");
  SetLong("Wispy clouds spread out in all directions from here, "
          "giving the impression of an endless sky. To begin your "
          "time on the world of Kailie, you must head down to the "
          "game world. Feel free to spend as much time as you like "
          "here reviewing the help documentation.");
	SetInventory( ([
	  ]) );
}


void init() {
	::init();
	if (newbiep(this_player())) this_player()->eventForce("wear all");
}

int Newbie() {
  object who = this_player();

  if (!(who->GetQuestCompleted("Newbie Book"))) {
    who->eventPrint("You cannot enter the world until you have read "
                    "the newbie book.  Type \"read book\". ");
    return 0;
    }
  return 1;
}
