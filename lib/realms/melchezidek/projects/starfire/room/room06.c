#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../starfire.h"

inherit LIB_ROOM;
int CheckMe();
string ResetLong();
static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("the prayer room");
  SetLong( (: ResetLong :) );
  SetItems( ([
     ({ "alcove", "alcoves" }) : 
       "The alcoves on either side provide a little privacy"
       " for those in prayer. They have kneelers set near the"
       " walls.",
     ({ "kneeler", "kneelers" }) :
       "The alcoves on either side have wooden kneelers for"
       " congregants looking to pray.",
     ({ "wall", "cracks", "sandstone" }) :
       "The northern wall is made of the same yellow sandstone"
       " found throughout the temple. Time has made its mark on"
       " this wall though in the presence of cracks through.",
     ({ "sand", "floor", "pile", "piles" }) :
       "The floor is covered with a thin layer of sand. In some spots it has collected"
       " into small piles making it hard to determine any specifics about the"
       " underlying construction.",
     ]) );
  SetItemAdjectives( ([
     "alcove"  : ({ "small", "eastern", "western" }),
     "kneeler" : ({ "wood", "wooden", "several" }),
     "wall"    : ({ "stone", "yellow", "sandstone", "cracked" }),
     "sand"    : ({ "thin", "piled" }),
    ]) );
  SetExits( ([
     "south"  : SF_ROOM "room03",
     ]) );
     
}

int CheckMe() {
  object room;
  room = this_object();

  if ((room->GetProperty("westlamplit") == 1 && room->GetProperty("eastlamplit") == 1) ||
      room->GetProperty("wall_down") == 1) {

      AddExit("north", SF_ROOM "room07");
      SF_ROOM "room07"->eventPrint("The southern passage is open!");
      debug("Yes");
      return 1;
   }
  debug("No. wl: " + room->GetProperty("westlamplit") + 
        " el: " + room->GetProperty("eastlamplit") + 
        " wall: " + room->GetProperty("wall_down"));
  return 0;
}

string ResetLong() {
  if (CheckMe() == 1) {
    //AddExit("north", SF_ROOM "room07");
    return "There are small alcoves on the eastern and western walls with several"
           " kneelers packed close to the wall. The room is fairly boxed shaped"
           " with few other distinguishing features. The room is missing a northern"
           " wall.";
   } else {
    return "There are small alcoves on the eastern and western walls with several"
       " kneelers packed close to the wall. The room is fairly boxed shaped"
       " with few other distinguishing features. The northern wall is bare"
       " with a few cracks in the sandstone as the only exception. To the"
       " south the temple proper can be seen through an arched doorway.";
   }
}
