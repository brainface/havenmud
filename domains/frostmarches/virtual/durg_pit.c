/*
 * Small Virtual area for Kylin Outpost
 * in the Frostmarches
 *
 *  - Melchezidek Aug 13, 2008
 */
 
#include <lib.h>
#include <domains.h>
#include "/domains/frostmarches/towns/durgoroth/durgoroth.h"

inherit LIB_ROOM;

int CheckLeave();
static void create(int x, int y) {
  string n, e, s, w;
  string long = "";
  string place = "/durg_pit/";
  string array OkEx, NoOk;
  mapping inv = ([ ]), items = ([ ]);
  ::create();
  
  /* Set Exits */
 
  if (x == 0 && y ==0) {
   AddExit("west", DURG_ROOM "road08", (: CheckLeave :));
   s = FROSTMARCHES_VIRTUAL + place + x + "," + (y -1);
   e = FROSTMARCHES_VIRTUAL + place + (x + 1) + "," + y;
  }
  if (x < 5) e = FROSTMARCHES_VIRTUAL + place + (x + 1) + "," + y;
  if (x > 0) w = FROSTMARCHES_VIRTUAL + place + (x - 1) + "," + y;
  if (y > -5) s = FROSTMARCHES_VIRTUAL + place + x + "," + (y - 1);
  if (y < 0) n = FROSTMARCHES_VIRTUAL + place + x + "," + (y + 1);
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);

  long = "The pit is a huge mixture of blood, bones and mud. All around are"
       " the signs of carnage. Daemons of all shapes and sizes come here to"
       " prove their worth and to assert their place in society.";
    
  NoOk = ({ "north", "south", "east", "west" });
  NoOk -= GetExits();
  if (sizeof(NoOk) == 0) { long += " The pit continues in all directions.";   }
  if (sizeof(NoOk) == 1) { long += " The rubble is piled too high to allow access to the "
                         + NoOk[0] + ".";   }
  if (sizeof(GetExits()) > 1 && sizeof(NoOk) > 1) {
    long += " The pit continues to the " + conjunction(GetExits(), "and") + ".";
  }

  switch(random(3)) {
  case 0:
     inv[DURG_NPC "toughcitizen2"] = (random(1) + 2);
     break;
  case 1:
     inv[DURG_NPC "toughcitizen"] = (random(1) + 2);
     break;
  case 2:
     inv[DURG_NPC "weakcitizen"] = (random(1) + 2);
     break;
  }

  SetShort("Within the Killing Pit of Durgoroth");
  SetClimate("sub-arctic");
  SetDomain("Frostmarches");
  SetGoMessage("You cannot go that way.");
  SetLong(long);
  SetInventory(inv);
  SetSmell( ([
       ]) );
  SetListen( ([
   ]) );
}

int CheckLeave() {
 if (this_player()->id("durg_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}
