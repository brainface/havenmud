
#include <lib.h>
#include <std.h>
#include "../yozrath.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("mehrak");
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetGender("male");
  SetTown("Yozrath");
  SetClass("merchant");
  SetLevel(40);
  SetMorality(150);
  SetId( ({ "mehrak", "merchant", "prince" }) );
  SetAdjectives( ({ "merchant" }) );
  SetShort("Mehrak the Merchant Prince of Yozrath");
  SetLong(
    "Mehrak the Merchant Prince was once like any other vendor. "
    "Then it occurred to him that he could make more profit by "
    "teaching others to trade and setting himself up only to "
    "influence the world through his students.  He could make "
    "anyone interested into a <merchant>."
    );
  SetLimit(1);
  SetPlayerTitles( ([
    "newbie" : "$N the Merchant's Apprentice",
    "mortal" : "$N the Travelling Merchant",
    "hm"     : "$N the Shrewd Dealer of the Desert",
    "legend" : "$N the Merchant Prince",
    "avatar" : "Merchant Prince $N the Seller of Sand in the Desert",
    ]) );
  SetInventory( ([
    YOZRATH_OBJ "thobe" : "wear thobe",
    ]) );
  SetFreeEquipment( ([
    STD_FISHING "pole" : 1,
    STD_OBJ     "digging/shovel" : 1,
    ]) );
}
