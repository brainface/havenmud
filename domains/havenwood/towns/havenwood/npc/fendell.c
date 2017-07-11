#include <lib.h>
#include "../wood.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("fendell");
  SetShort("Fendell, Provisioner of Havenwood");
  SetRace("wild-elf");
  SetClass("rogue");
  SetLevel(9);
  SetMorality(15);
  SetId( ({ "fendell", "provisioner"}) );
  SetGender("male");
  SetLong("Fendell is a tall wild-elf with long tangled hair.  He loves "
          "caring for his garden but loves making food for the citizens "
          "of Havenwood more.");
  SetLocalCurrency("imperials");
  SetMenuItems( ([
      "grapes" : HWD_OBJ "/grapes",
    	"wine"   : HWD_OBJ "/hw_wine",
    	"salad"  : HWD_OBJ "/salad",
    	]) );
  }