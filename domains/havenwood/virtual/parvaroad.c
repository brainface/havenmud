#include <lib.h>
#define CANENTERPARVA 1
inherit LIB_ROOM;

static private int XPosition, YPosition;
int PreEnterParva();

varargs static void create(int x, int y) {
   room::create();
   XPosition = x;
   YPosition = y;
   SetShort("Parva Road");
  SetClimate("temperate");
  SetDomain("HavenWood");
   SetLong("The road runs right alongside the Havenwood.  "
           "It goes both east and west.  A few bushes grow around "
           "the path, and some of the trees of the Havenwood have "
           "been chopped down around here too, leaving little "
           "rotting tree stumps in their path.");
   SetItems( ([
                ({ "parva road","road","path" }) :
                   (: GetLong :),
                ({ "growing bushes","bush","bushes" }) :
                   "The bushes are thriving among the "
                   "tree stumps.",
                ({ "tree stumps","stump","stumps" }) :
                   "The tree stumps are slowly rotting away, "
                   "having lost their ability to live.",
                ({ "havenwood","trees","tree" }) :
                   "The trees of the Havenwood are strong and "
                   "tall around here, but many were cut down.",
           ]) );
   SetItemAdjectives( ([
                         "road" : ({ "parva" }),
                         "bushes" : ({ "growing" }),
                         "stumps" : ({ "little","rotting","tree" }),
                    ]) );
   if(x == 15) {
      AddExit("east","/domains/havenwood/towns/parva/room/path1", (: PreEnterParva :));
      SetLong(GetLong() + "  There appears to be a town east of "
              "here.");
      AddExit("west","/domains/havenwood/virtual/parvaroad/" + (x-1) +","+y);
   }
   else if(x == 0) {
      AddExit("west","/domains/havenwood/virtual/havenwoodroad/165,165");
      AddExit("east","/domains/havenwood/virtual/parvaroad/" + (x+1) +","+y);
   }
   else {
      AddExit("east","/domains/havenwood/virtual/parvaroad/" + (x+1) +","+ y);
      AddExit("west","/domains/havenwood/virtual/parvaroad/" + (x-1) +","+y);
   }
}

int PreEnterParva() {
   if(CANENTERPARVA) return 1;
   if(immortalp(this_player())) return 1;
   else return 0;
}   
