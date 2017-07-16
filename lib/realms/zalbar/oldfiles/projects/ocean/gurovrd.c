#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

void SetupExits(int, int);
void SetupEncounters(int, int);
int PreLagoon();

static void create(int x, int y) {
  ::create();
  SetLong(
    "The Gurov Road passes from the far east near Estergrym to the far west "
    "near Keryth. All the lands of this valley are claimed by the Prince "
    "of Gurov, who rules from the capital city for which the Principality "
    "is named."
    );
  SetShort("The Principality of Gurov");
  SetupExits(x, y);
  SetupEncounters(x, y);     
}

void SetupExits(int x, int y) {
  if (y == 0) {
    AddExit("east", GUROV_VIRTUAL "gurovrd/" + (x + 1) + "," + y);
    AddExit("west", GUROV_VIRTUAL "gurovrd/" + (x - 1) + "," + y);
    }

  /* Extended Road from 40 */
  if (x == 58 && y == 0) {
    AddLong(" The Gurov Road connects here with the North Road that connects "
            "Grymxoria to Gurov.");
    AddExit("east", ESTERGRYM_VIRTUAL "northroad/1,40");
  }
  
  /* Extended Road from -40 and changed exit */
  if (x == -99 && y == 0) {
    AddLong(" The Gurov Road merges to the west with a smaller road through "
            "the Western Wastes.");
    AddExit("west", FROSTMARCHES_VIRTUAL "frostmarchrd/0,49");
  }
  if (x == 0 && y >= 0) {
    AddExit("north", GUROV_VIRTUAL "gurovrd/" + (x) + "," + (y + 1));
    if (y) {
      AddExit("south", GUROV_VIRTUAL "gurovrd/" + (x) + "," + (y - 1));
      AddLong(" This part of the Gurov Road leads north and south from the main "
            "passage of the road to the capital city of the Principality. ");
           }
    if (!y) AddLong(" The road also branches to the north here, heading off "
                    "to the capital city of the Principality. ");
    
    /* Shortened Road to City */
    if (y == 10) {
      AddExit("north", GUROV_TOWNS "gurov/room/gate");
    }
    
    /* Changed  Forest due to shortened road */
    if (y == 8) {
      AddLong(" A thin forest lies to the southwest.");
      AddExit("southwest", GUROV_AREAS "forest/room/f01");
    }
    if (y == 7) {
      AddLong(" A thin forest lies to the west.");
      AddExit("west", GUROV_AREAS "forest/room/f01");
    }
    if (y == 3) {
      AddLong(" A thin forest lies to the west.");
      AddExit("west", GUROV_AREAS "forest/room/f05");
    }
    if (y == 2) {
      AddLong(" A thin forest lies to the northwest.");
      AddExit("northwest", GUROV_AREAS "forest/room/f05");
      }
  }
 if (x == -1 && y == 0) {
    AddExit("south", GUROV_AREAS "gurthlad/rooms/room1");
    AddLong(" To the south lie the dusty plains of Gurthlad.");
    }
    
    /* Moved Lagoon away from City */
 if (x == -40 && y == 0) {
    AddExit("north", GUROV_VIRTUAL "lagoon/0,-30", (: PreLagoon :) );
    AddLong(" To the north a terrifying icy lagoon spreads toward the sea.");
  }
  /* Removed due to Road being shortened 
  
if (x == 0 && y == 15) {
    AddExit("west", GUROV_VIRTUAL "lagoon/30,-15", (: PreLagoon :) );
    AddLong(" To the west a terrifying icy lagoon spreads toward the sea.");
  } */
}

void SetupEncounters(int x, int y) {
  if (!random(30)) AddInventory(GUROV_TOWNS "gurov/npc/farmer", 1);
  if (x == -99 && y == 0) {
    AddInventory(GUROV_TOWNS "gurov/npc/guard", 1);
  }
  if (x == 58 && y == 0) {
    AddInventory(GUROV_TOWNS "gurov/npc/guard", 1);
  }
}

  
int PreLagoon() {
  object who = this_player();
  if (who->GetLevel() < 50 && userp(who) && !creatorp(who)) {
    send_messages("",
      "$agent_name cannot seem to get up the courage to enter the lagoon.",
      who, 0, environment(who) );
    return 0;
    }
  return 1;
}