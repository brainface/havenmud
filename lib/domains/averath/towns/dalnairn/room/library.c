// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("in the dalnairn library");
  SetLong(
    "The library is an old building that sees very few visitors. The "
    "selection of books is very limited, though some seem vaguely related to "
    "the study of magic. A table surrounded by a few chairs stands in the "
    "center of the library, providing a quiet place for citizens to relax "
    "with a book.",
  );
  SetItems( ([
  ({ "library", "building" }) : (: GetLong :),
  ({ "books", "selection" }) : 
    "There aren't many books in the library. Most seem very old, some are "
    "even falling apart.",
  ({ "table", "chairs" }) : 
    "The table and chairs provide a relaxing place for citizens to read.",    
  ]) );
  SetItemAdjectives( ([
    "building" : ({ "old" }),
    "books" : ({ "old" }),    
  ]) );
  SetInventory( ([
    DAL_NPC "catriona" : 1,  
  ]) );
  SetListen( ([
    "default" : "The library is completely silent.",
  ]) );
  SetSmell( ([
    "default" : "The air smells of old paper and ink.",
  ]) );
  SetExits( ([
    "out" : DAL_ROOM "road6",
  ]) );  
}
