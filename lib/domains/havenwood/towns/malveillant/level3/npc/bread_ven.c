//  Food Vendor for Market
//  Alessandra 2009
 
#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();

  SetKeyName("Tobin");
  SetShort("tobin, the baker");
  SetId( ({"vendor", "merchant", "dark-elf", "tobin", "baker", "man", "bread vendor"}) );
  SetAdjectives( ({"tall", "slender"}) );
  SetLong(
     "A tall and slender man, Tobin is the local baker and food vendor. His "
     "breads are always fresh and delicious, and he has many cheeses and "
     "fruits imported to sell with his baked goods. His black eyes glint "
     "with the promise of good deals."
     );
  SetRace("dark-elf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(25);
  SetLocalCurrency("roni");
  SetInventory( ([
     ]) );
  SetMenuItems( ([
     "cheese wheel" : STD_MEAL "food/wheel",
     "hunk of bread" : STD_MEAL "food/bhunk", 
     "apple" : MAL_OBJ3 + "apple",
     ]) );

}
