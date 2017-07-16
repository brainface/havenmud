#include <lib.h>
#include <std.h>
#include "../yozrath.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("zulfaqar");
  SetLimit(1);
  SetShort("Zulfaqar the Charitable One");
  SetId( ({ "zulfaqar", "aider", "equipper" }) );
  SetAdjectives( ({ "zulfaqar", "charitable" }) );
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "female robe"   : YOZRATH_OBJ "abaya",
    "male robe"     : YOZRATH_OBJ "thobe",
    "turban"        : YOZRATH_OBJ "turban",
    "waterskin"     : YOZRATH_OBJ "waterskin",
    "fishing pole"  : STD_FISHING "newbie_pole",
    "shovel"        : STD_OBJ     "digging/shovel",
    "sword"         : YOZRATH_OBJ "newbie_kopesh",
    "club"          : STD_WEAPON  "newbie_club",
    "knife"         : STD_WEAPON  "knife/freeknife",
    "bola"          : STD_WEAPON  "projectile/bola",
    ]) );
  SetInventory( ([
    YOZRATH_OBJ "thobe"  : "wear thobe",
    ]) );
  SetLong("Zulfaqar, also known as the Charitable One, "
          "has given up his life of being a merchant to help "
          "the young faithful denizens of Yozrath.  Zulfaqar "
          "finds himself at peace and harmony with He Who Judges "
          "by donating his equipment to the youth that need it.");
  SetGender("male");
  SetClass("merchant");
  SetReligion("Kylin");
  SetMorality(1000);
  SetLevel(6);
  SetCurrency("ducats", 100);
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(2, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
    }) );
}
