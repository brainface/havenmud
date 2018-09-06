// probs duuk
// mahk 2018: added secret witches

#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;
#define START "/domains/averath/towns/averath/room/road6"
#define END   "/domains/averath/towns/dalnairn/room/gates"
#define THIS  "/domains/averath/virtual/averathroad/"
#define NPCS  "/domains/averath/virtual/npc"

static void create(int x, int y) {
   string long = "";
   mapping items = ([ ]), itemadjs = ([ ]), inv = ([ ]);
   SetNoReplace(1);
   ::create();
   SetDomain("Averath");
   SetClimate("temperate");
   SetShort("the Averath Road");
   long +=
     "The Averath Road is relatively wide and paved with stone. It "
     "seems ratherly well maintained, though a few blocks seem to have been "
     "knocked out of place.";

   items += ([ ({ "road" }) : (: GetLong :),
               ({ "stone", "blocks", "block" }) : "The road seems well "
                 "maintained, though a few blocks have been knocked out of "
                 "place, making it a bumpy ride for anything on wheels.",
            ]);
   itemadjs += ([ "road" : ({ "averath" }),
               ]);
   if(x == 0) {
     AddExit("east", START);
     AddExit("west", THIS + (x-1) + ",0");
     long += " The road seems to end to the east, as it enters the Averath city bounds.";
     items += ([ ({ "averath" }) : "The city of Averath lies to the east.",]);
   }
   else if(x == -30) {
     AddExit("west", END);
     AddExit("east", THIS + (x+1) + ",0");
     long += " The road seems to end to the west, as it approaches the city of Dalnairn.";
     items += ([ ({ "dalnairn" }) : "The city of Dalnairn lies to the west.",]);
   }
   else {
     AddExit("east", THIS + (x+1) + ",0");
     AddExit("west", THIS + (x-1) + ",0");
     long += " The road continues east and west across the island.";
   }
   if (x == -4 && y == 0) {
    AddExit("south", AVERATH_AREAS "lumber/room/room1");
    long += " To the south lies some kind of lumber camp.";
  }
  if  (x == -15 && y == 0) {
        AddExit("south", AVERATH_AREAS "avfield/field/field1");
        long += " A barren wasteland lies to the south.";
        }
   SetSmell( ([
                "default" : "The hint of the ocean breeze is faint.",
           ]) );
   SetListen( ([
                 "default" : "The occasional passing birds tweet happily.",
            ]) );
   if (random(6) == 0) {
     inv += ([ NPCS + "/traveller" : 1 ]);
   } else if (random(6) == 0) {
     inv += ([ NPCS + "/traveller_f" : 1]);
   } else if (random(6) == 0) {
     inv += ([ NPCS + "/traveller_witch" : 1]);
   } else if (random(6) == 0) {
     inv += ([ NPCS + "/traveller_f_witch" : 1]);
   }

   SetInventory(inv);
   SetLong(long);
   SetItems(items);
   SetItemAdjectives(itemadjs);
}

