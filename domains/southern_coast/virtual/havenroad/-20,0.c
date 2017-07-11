#include <domains.h>
#include <lib.h>
inherit LIB_ROOM;
int DomainCheck();

static void create() {
   room::create();
   SetShort("Haven Road");
   SetDayLong("This is a small road that heads east and "
              "west. There are a few trees near this road "
              "that are really nice to look at. This road "
              "looks like it gets used a lot. The sky here "
              "is warm, still, and clear. The sun hangs in "
              "the sky, illuminating the entire area.  There seems "
              "to be a particularily thick copse of trees to "
              "the north. The Twitchy Nymph coffeehouse is here.");
   SetNightLong("This is a small road that heads east and "
                "west. There are a few trees near this road "
                "that are really nice to look at. This road "
                "looks like it gets used a lot. The sky here "
                "is chilly, still, and clear. The moon hangs "
                "in the sky, illuminating the entire area. "
                "The Twitchy Nymph coffeehouse is here.");
   SetItems( ([
                ({ "small cobblestone road","road","small road",
                   "cobblestone road" }) :
                   "This nicely made cobblestone road heads in the "
                   "eastern and western directions.",
                ({ "tree","trees" }) :
                   "The trees here are pretty and are nice "
                   "to look at.",
                ({ "nymph", "coffeehouse" }) : "The coffeehouse is a friendly, "
                        "inviting environment.",
           ]) );
   SetItemAdjectives( ([
     "nymph" : ({ "twitchy" }),
     ]) );
   SetEnters( ([
     "coffeehouse" : SOUTHERN_COAST_AREAS "coffeehouse/room/coffeehouse",
     ]) );
   SetExits( ([
                "west"  : SOUTHERN_COAST_VIRTUAL + "havenroad/-21,0",
                "east"  : SOUTHERN_COAST_VIRTUAL + "havenroad/-19,0",                
           ]) );
   AddExit("north", WESTWOOD_TOWNS + "soleil/room/soleilroad01", (: DomainCheck :) );
   SetInventory( ([
     SOUTHERN_COAST_AREAS "coffeehouse/obj/sign" : 1,
     ]) );
}

int DomainCheck() {
  if (!OPEN_WESTWOOD)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_WESTWOOD;  
}
