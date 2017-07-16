#include <lib.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
    SetKeyName("alai");
    SetShort("Alai the Cheater");
    SetLong("Alai the Cheater is the greatest merchant in Argoth.  He has "
    "never been defeated in a test of skills involving money.");
    SetId( ({ "alai", "alai the cheater", "cheater" }) );
    SetRace("orc");
    SetTown("Karak");
  SetClass("merchant");
  SetGender("male");
    SetLevel(25);
  SetUniqueSkills( ([
     "weapon smithing" : 1,
     "metal working" : 1,
    "armour smithing" : 2,
    "wood working" : 2,
     ]) );
  SetPlayerTitles( ([
    "newbie" : "the moneygrubber",
    "mortal" : "the Peddler of Argoth",
    "hm" : "the Swindler",
    "avatar" : "The Master Cheater",
    "fighter" : "the Economist of War",
    ]) );
  SetFreeEquip( ([
    "/std/obj/fishing/pole" : 1,
    "/std/weapon/knife/small_knife" : 1,
     ]) );
  }
