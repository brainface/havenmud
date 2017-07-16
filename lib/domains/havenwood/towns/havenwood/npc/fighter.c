#include <lib.h>
#include <std.h>
#include "../wood.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Mane");
  SetShort("Mane Wild the Defender of the Havenwood");
  SetId( ({ "mane", "wild", "defender" }) );
  SetLong(
    "Mane Wild is the local trainer of warriors. His superior fighting "
    "skills are known throughout the Havenwood. He serves to add to the "
    "ranks of those sword to defend the wood."
    );
  SetRace("wild-elf");
  SetGender("male");
  SetClass("fighter");
  SetLevel(50);
  SetCurrency("imperials", random(300) + 1);
  SetInventory( ([
    STD_SLASH + "sword" : "wield sword",
    ]) );
  SetTown("Havenwood");
  SetPlayerTitles( ([
    "newbie" : "the Young Hunter",
    "mortal" : "the Quiet Hunter",
    "hm"     : "the Stalker of the Woods",
    "legend" : "the Defender of the Havenwood",
    "avatar" : "the Prescence in the Woods",
    ]) );
  SetFreeEquipment( ([
    STD_SLASH "sword" : 1,
    ]) );
}
