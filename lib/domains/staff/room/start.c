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
        SetProperty("no teleport", 1);
	SetProperty("no weather", 1);
	SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("Wispy clouds spread out in all directions from here, "
          "giving the impression of an endless sky. To begin your "
          "time on the world of Kailie, you must head down to the "
          "game world. Feel free to spend as much time as you like "
          "here reviewing the help documentation.");
//  SetSmell("Your password for ALL new characters is \"password\". Use the \"passwd\" command to fix that.");
	SetInventory( ([
     "/std/obj/newbie_book" : 1,
	  ]) );
}


void init() {
	::init();
	if (newbiep(this_player())) this_player()->eventForce("wear all");
        if (newbiep(this_player())) this_player()->RemoveChannel("ooc");
}

int Newbie() {
  object who = this_player();

  if (!(who->GetQuestCompleted("Newbie Book"))) {
    who->eventPrint("You cannot enter the world until you have read "
                    "the newbie book.  Type \"read book\". ");
    return 0;
    }
  who->eventForce("describe");
  return 1;
}

int eventReceiveObject(object ob) {
  if (ob->GetLevel() == 0) ob->RemoveChannel("ooc");
  return ::eventReceiveObject(ob);
}

int eventReleaseObject(object ob) {
  ob->AddChannel("ooc");
  return ::eventReleaseObject(ob);
}
