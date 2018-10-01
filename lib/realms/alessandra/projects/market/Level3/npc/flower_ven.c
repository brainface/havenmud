// Flower Vendor for Market
// Aless 03/06 
 
#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();

  SetKeyName("flower girl");
  SetShort("a petite flower girl");
  SetId( ({"vendor", "merchant", "dark-elf", "livi", "girl"}) );
  SetAdjectives( ({"petite", "flower", "girl"}) );
  SetLong(
     "Livi's father owns the general store just near here. She is petite "
     "and cute as a button. Her jet black hair is pulled back into pigtails "
     "tied with red satin bows. Her dress is frilly and she is extremely "
     "worried about getting it dirty. Her father set up a flower wagon for "
     "her to sell her mother's flowers in."
     );
  SetRace("dark-elf");
  SetGender("female");
  SetClass("merchant");
  SetLevel(5);
  SetLocalCurrency("roni");
  SetInventory( ([
     ]) );
  SetMenuItems( ([
    "red rose" : MAL_OBJ3 + "redrose",
    "lily" : MAL_OBJ3 + "lily",
    "anemone" : MAL_OBJ3 + "anemone",
    "hellebore" : MAL_OBJ3 + "hellebore",
    "bouquet of black roses" : MAL_OBJ3 + "bouq_black",
     ]) );
  SetAction(5, ({ 
  	 "!emote frowns slightly while inspecting her dress.",
  	 "!say Would you like to buy a flower?",
  	 "!emote carefully plucks the petals from a rose.", 
  	 }) );


}
