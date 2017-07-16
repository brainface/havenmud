/*   Portia  10-24-98
     A healer for Malveillant.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_HEALER;

static void create() {
  healer::create();
  SetKeyName("victoria");
  SetShort("Victoria the Healer");
  SetId( ({"victoria", "healer"}) );
  SetLong("Victoria is one who could be very useful if one was "
         "hurt. She seems to know how to be of service to people "
         "with severe injuries.");
  SetRace("dark-elf"); 
  SetTown("Malveillant");
  SetMorality(-200);
  SetStat("wisdom", 10000, 1);
  SetGender("female");
  SetClass("rogue");
  SetLevel(90);
  SetCombatAction(5, ({
  		"!disarm",
  		"!disorient",
  		}) );
  SetFriends("Tallia");
  
  SetInventory( ([
       MAL_OBJ + "/clothing/elf_dress" : "wear dress",
        ]) );
  SetCurrency("roni",random(40)+10);
  SetLocalCurrency("roni");
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  ]) );
  SetReligion("Soirin", "Soirin");
  }
