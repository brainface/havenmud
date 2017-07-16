#include <lib.h>
#define me "/domains/world/virtual/parvanewbie"
#define LEAVE "/somethingorother"
inherit LIB_ROOM;
#include "npclist.h"

static int XPosition, YPosition;

static void create(int x, int y) {
   string long;
   int i = 0, xy = random(3)+2;
   mapping items = ([ ]), itemadj = ([ ]), inv = ([ ]);
   SetNoReplace(1);
   room::create();
   SetDomain("HavenWood");
   XPosition = x;
   YPosition = y;
   long = "Large trees clutter overheard, their "
          "branches drooping down towards the "
          "ground from the weight of small "
          "animals and leaves.  There are "
          "open spaces in almost all "
          "directions that would be easy to "
          "walk through.";
   items = ([ 
              ({ "green leaves","leaves","leaf" }) :
                 "The leaves are beautiful green "
                 "things that cling to the branches "
                 "and ruffle in the wind.",
              ({ "large trees","trees","tree" }) :
                 "The trees are deciduous and "
                 "old.  They are mostly tall and "
                 "thick, for leaf trees.",
              ({ "drooping branches","branches","branch" }) :
                 "The branches hand down towards the "
                 "ground, feeling weighted by their "
                 "leaves and any animals up in "
                 "them.",
              ({ "dirt ground","ground","debris" }) :
                 "The ground is covered with the "
                 "normal forest debris.",
           ]);
   itemadj = ([
                "leaves" : ({ "green" }),
                "trees" : ({ "larg","deciduous","leaf" }),
                "branches" : ({ "drooping" }),
                "ground" : ({ "forest","dirt" }),
             ]);
   if(y == 2) {
      long += "  Brush blocks the way to the "
              "north.";
      items += ([ ({ "north brush","brush" }) :
                     "The brush, all green and "
                     "leafy, blocks the way to the "
                     "north.",
               ]);
      itemadj += ([ "north brush" : ({ "north","green",
                    "leafy" })
                 ]);
   }
   if(y == -2) { 
      long += "  Brush blocks the way to the south.";
      items += ([ ({ "south brush","brush" }) :
                     "The brush to the south is "
                     "plain, but green and growing.",
               ]);
      itemadj += ([ "brush" : ({ "south" }), ]);
   }
   if(x == 3) {
      long += "  Trees grow too closely to the "
              "east.";
      items += ([ ({ "east trees","trees","tree" }) :
                  "The trees to the east cluster "
                  "together, preventing passage.",
               ]);
      itemadj += ([ "trees" : ({ "east" }), ]);
   }
   if(x == -3) {
      long += "  A river tinkles its way towards the "
              "ocean to the west.";
      items += ([ ({ "tinkling river","river" }) :
                     "The river blocks the way to "
                     "to the west.  It slowly "
                     "progresses towards the "
                     "ocean.",
               ]);
      itemadj += ([ "river" : ({ "west","tinkling" }), ]);
   }
   if(y > -2) {
      AddExit("south",me + "/" + x + "," + (y-1));
   }
   if(y < 2) {
      AddExit("north",me + "/" + x + "," + (y+1));
   }
   if(x < 3) {
      AddExit("east",me + "/" + (x+1) + "," + y);
   }
   if(x > -3) {
      AddExit("west",me + "/" + (x-1) + "," + y);
   }
   if(x == 0 && y == 2) {
      AddExit("north",LEAVE);
   }
   SetShort("a hunting area in Havenwood");
   switch(random(4)) {
      case 0:
      long += "A fallen log drapes itself across the "
              "forest floor.";
      items+= ([ ({ "fallen log","log" }) :
                    "The log is covered with all "
                    "sorts of scum involved in "
                    "decomposing it.",
              ]);
      itemadj+= ([ "log" : ({ "fallen" }), ]);
      break;
      case 1:
      SetSmell( ([ "default" : "Forest and earth smells "
                   "mingle with dust in the air.",
              ]) );
      break;
      case 2:
      SetListen( ([ "default" : "Birds chirp in the "
                    "distance.", ]) );
      break;
      case 3:
      SetListen( ([ "default" : "The branches rustle "
                    "with the movement of some "
                    "animal." ]) );
      break;
   }
   for(i=0;i<xy;i++) {
      inv += ([ npclist[random(sizeof(npclist))] : 1+random(2), ]);
   }
   SetLong(long);
   SetItems(items);
   SetItemAdjectives(itemadj);
   SetInventory(inv);
}
