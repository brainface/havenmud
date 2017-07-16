/*   Portia  10-24-98
    The local innkeeper.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("paige");
  SetShort("Paige Tallir, the local innkeeper");
  SetId( ({"paige", "tallir", "paige tallir", "innkeeper"}) );
  SetAdjectives( ({"local"}) );
  SetGender("female");
  SetRace("dark-elf"); 
  SetTown("Malveillant");
  SetMorality(-200);
  SetReligion("Soirin","Soirin");
  SetClass("rogue");
  SetLevel(30);
  SetLong("Paige seems to be a very strong woman who could defend "
         "herself rather easily. Working in the inn everyday has "
         "apparently trained her well.");
  
  SetLocalCurrency("roni");
  SetInventory( ([
      MAL_OBJ + "/clothing/elf_skirt"     : "wear skirt",
      MAL_OBJ + "/clothing/elf_blouse"    : "wear blouse",
      MAL_OBJ + "/clothing/elf_medallion" : "wear medallion",
       ]) );
  SetCurrency("roni",random(50) + 20);
  SetCombatAction(5 , ({
  		"!disarm",
  		"!disorient",
  		}) );
  SetMenuItems( ([
      "steak"  : "/std/meal/food/steak",
    	"cheese" : "/std/meal/food/cheese",
    	"bread"  : "/std/meal/food/bread",
   		"milk"   : "/std/meal/drink/milk",
    	"water"  : "/std/meal/drink/water",
      ]) );
  }
