// Targoviste
// Laoise
// August 2004
// Enchantment Trainer

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetTown("Targoviste");
  SetShort("the library of Targoviste");
  SetLong(
    "Sturdy shelves line the walls of the library, neatly filled with "
    "hefty tomes. Various foreign languages and complex symbols are "
    "tooled in to the bindings. A wide path of black wood runs from here "
    "to the west, bordered on either side by thick red carpeting. Gold "
    "symbols inlaid in the wood suggest that this aisle is used for practicing "
    "magical dueling. Other parts of the library lie to the south and east. "
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The abrupt snap of magical forces ruptures the air.",
  ]) );
  SetSmell( ([
    "default" : "Tangles of sulphur wend through the air, wrapping "
    "around matching veins of incense smoke.",
  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "library5",
    "west" : TARG_ROOM "library3",
  ]) );
}
