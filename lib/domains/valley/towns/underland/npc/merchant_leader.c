#include <lib.h>
#include <std.h>
#include "../underland.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("valiant");
  SetRace("gnome");
  SetGender("male");
  SetShort("Valiant the Merchant Prince");
  SetId( ({ "gnome", "prince", "merchant", "valiant" }) );
  SetAdjectives( ({ "merchant" }) );
  SetLong(
    "Valiant is a Merchant Prince, able to instruct those who desire it "
    "in the fine arts of being a merchant. Those interested in being a "
    "merchant should <greet> him."
    );
  SetClass("merchant");
  SetLevel(50);
  SetTown("Underland");
  SetFreeEquipment( ([
    STD_FISH "pole" : 1,
    STD_OBJ  "digging/shovel" : 1,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Sweeper of Floors",
    "mortal" : "the Near-Bankrupt Trader",
    "hm"     : "the Shopkeep",
    "legend" : "the Merchant Prince",
    "avatar" : "the Intercontinental Import/Export Specialist",
    ]) );
}
