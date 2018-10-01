#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../starfire.h"

inherit LIB_ROOM;
int NoReturn();
int DragonCheck();

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("the room of immolation");
  SetLong(
      "All around soot covers every surface. This room is a"
      " massive black cavern. Discerning the materials of the"
      " walls is next to impossible due to the overwhelming"
      " amount of soot covering them. A small passage can be"
      " seen heading north out of this area. The floor is thick"
      " with soot and sparkles with a myriad of small glass"
      " shards. "
      );
  SetInventory( ([
	SF_NPC "starfire" : 1,
    ]) );
  SetItems( ([
      ({ "soot", "wall", "walls", "cavern"}) : (: GetLong :),
      ({ "passage" }) : "A small passage leads north from here",
      ({ "floor", "glass", "shards", "sand" }) :
       "The floor is covered with soot and littered through there"
       " are small glass shards that were likely created from"
       " intense heat mixing with the sand found in this area."
    ]) );
  SetItemAdjectives( ([
      "soot"    : ({ "black", "massive" }),
      "passage" : ({ "small", "north", "northern" }),
      "floor"   : ({ "sparkling", "thick", "small", "glass" }),
    ]) );
  SetExits( ([
      ]) );
  AddExit("north", SF_ROOM "room08", (: DragonCheck :));
  AddExit("south", SF_ROOM "room06", (: NoReturn :));
  SetProperty("no teleport", 1);
  }

int NoReturn() {
   object who;
   who = this_player();

  // if(!creatorp(who)) {
     send_messages("attempt", "The southern passage crumbles as $agent_name $agent_verb to pass through!",
                    who, 0, environment(who));

     SF_ROOM "room07"->RemoveExit("south");
     SF_ROOM "room06"->RemoveExit("north");

     SF_ROOM "room06"->eventPrint("The northern wall magically appears with an audible pop!");

     SF_ROOM "room06"->RemoveProperty("westlamplit");
     SF_ROOM "room06"->RemoveProperty("eastlamplit");
     SF_ROOM "room06"->RemoveProperty("wall_down");
//   return 1;
//  }
   return 0;
}

int DragonCheck(string dir) {
  object dragon;
  dragon = present("starfire", this_object());

  if ( !dragon || !living(dragon) ) {
     return 1;
    } else {
     this_player()->eventPrint("You cannot pass through the dragon while it's alive.");
     return 0;
  }
}
