/*   Portia  1-9-99
    The necro's study.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a necromancer's workroom");
  SetClimate("indoors");
SetAmbientLight(20);
  SetExits( ([
     "northwest" : MAL_ROOMS3 + "entranceway",
     "southeast" : MAL_ROOMS3 + "hall1",
    ]) );
  SetInventory( ([
/*
    "/quests/alchemist/npc/whey_spider" : 2,
*/
    MAL_NPC3 + "teach_nec" : 1,     
    MAL_NPC3 + "lead_nec" : 1,      
    ]) );
  SetListen( ([
    "default" : "The room is deathly silent.",
    ]) );
  SetSmell( ([
    "default" : "The room smells putrid.",
    ]) );
  SetLong("This room seems to be full of shadows. There are no "
    "windows and there is a strong sense of evil. The large table "
    "in the center of the room is full of books with various colored "
    "covers. Huge spiderwebs hang in the corners and a single torch "
    "burns. Upon one of the shelves lies the skull of what seemingly "
    "used to be a lizardman.");
  SetItems( ([
    ({"room", "workroom"}) : (: GetLong :),
    ({"shadows", "shadow"}) : "The shadows fill the room and give it "
        "a sinister aura.",
    ({"table"}) : "The table is full of books.",
    ({"books", "book"}) : "The books are several colors.",
    ({"spiderwebs", "spiderweb"}) : "The spiderwebs seem very old.",
    ({"torch"}) : "The torch burns dimly.",
    ({"shelves", "shelf"}) : "The shelf contains a large skull.",
    ({"skull"}) : "The skull seems to be that of a lizardman.",
   ]) );
  SetItemAdjectives( ([
    "workroom" : ({"necromancer's"}),
    "table" : ({"large"}),
    "spiderwebs" : ({"old", "huge"}),
    "torch" : "single",
    "skull" : "large",
    ]) );
  }
