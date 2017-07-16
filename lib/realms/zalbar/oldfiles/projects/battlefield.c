/*
 * Small Virtual area: Battlefield between Durgoroth
 *    and Kylin Outpost
 * in the Frostmarches
 *
 *  - Melchezidek Aug 13, 2008
 */
 
#include <lib.h>
#include <domains.h>
#include "/realms/zalbar/projects/outpost/outpost.h"
#include FROSTMARCHES_TOWNS + "durgoroth.h"

inherit LIB_ROOM;

int CheckLeave();
static void create(int x, int y) {
  string n, e, s, w;
  string long = "";
  string place = "/battlefield/";
  string array OkEx, NoOk;
  int rnd;
  mapping inv = ([ ]), items = ([ ]);
  ::create();
  
  /* Set Exits */
 
  if (x == 1 && y == 0) {
   s = OP_ROOM "north_gate";
   n = FROSTMARCHES_VIRTUAL + place + x + "," + (y + 1);
   e = FROSTMARCHES_VIRTUAL + place + (x + 1) + "," + y;
   w = FROSTMARCHES_VIRTUAL + place + (x - 1) + "," + y;
  }
  if (x == 1 && y == 4) {
   n = DURG_ROOM "road01";
   s = FROSTMARCHES_VIRTUAL + place + x + "," + (y - 1);
   e = FROSTMARCHES_VIRTUAL + place + (x + 1) + "," + y;
   w = FROSTMARCHES_VIRTUAL + place + (x - 1) + "," + y;
  }
  if (x < 2) e = FROSTMARCHES_VIRTUAL + place + (x + 1) + "," + y;
  if (x > 0) w = FROSTMARCHES_VIRTUAL + place + (x - 1) + "," + y;
  if (y > 0) s = FROSTMARCHES_VIRTUAL + place + x + "," + (y + 1);
  if (y < 4) n = FROSTMARCHES_VIRTUAL + place + x + "," + (y - 1);
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);

long = "This battlefield lies between the ruins of Durgoroth and the "
       "Kylin outpost. Littering the frozen ground is broken weapons "
       "and shattered pieces of armour. The blood of the dead and "
       "wounded has formed into small pools, which have frozen with "
       "the cold. ";
    
  NoOk = ({ "north", "south", "east", "west" });
  NoOk -= GetExits();
  if (sizeof(NoOk) == 0) { long += " The battlefield continue in all directions.";   }
  if (sizeof(NoOk) == 1) { long += " The trenchs to the " + NoOk[0] + " prevents "
      "movement in that direction.";   }
  if (sizeof(GetExits()) > 1 && sizeof(NoOk) > 1) {
    long += " The battlefield continues to the " + conjunction(GetExits(), "and") + ".";
  }

  
  
  
  switch(random(6)) {
  case 0:
   inv[OP_NPC "dwarf_paladin"] = (random(1) + 2);
   break;
  case 1:
     inv[OP_NPC "paladin"] = (random(1) + 2);
     break;
  case 2:
   inv[OP_NPC "inquisitor"] = (random(1) + 2);
   break;
  case 3:
   inv[OP_NPC "orthodox_monk"] = (random(1) + 2);
   break;
  default:
    break;
  }

  SetShort("the battlefield");
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
