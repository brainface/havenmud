#include <lib.h>
#include "../parva.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("Minkin");
  SetShort("Minkin the Innkeeper");
  SetId( ({ "minkin", "innkeeper" }) );
  SetTown("Parva");
  SetAdjectives( ({ }) );
  SetLong("Minkin is a fat man with milky blue-green "
          "eyes. His chubby fingers twitch constantly, "
          "and his eyes are always searching the crowd. "
          "He is a shrewd business-owner and "
          "his inn has become quite famous for providing everything "
          "a sailor could want.");
  SetGender("male");
  SetRace("human");
  SetClass("merchant");
  SetClass("rogue");
  SetLevel(35);
  SetLocalCurrency("oros");
  SetMenuItems( ([
    "grog"     : PARVA_OBJ "inn_grog",
    "matelote" : PARVA_OBJ "inn_matelote",
    "calamari" : PARVA_OBJ "inn_calamari",
    "lomi-lomi": PARVA_OBJ "inn_lomi",
    "fillet"   : PARVA_OBJ "inn_fillet",
    "clams"    : PARVA_OBJ "inn_clams",
  ]) );
  SetMorality(10);
  SetInventory( ([
    ]) );
  SetAction(1, ({ 
    "!speak Only the finest entertainment... available upstairs.",
    "!speak Food, grog... other needs? I can help.",
    "!speak Fill your stomach, then fill your... evening.",
     }) );
  SetCombatAction(10, ({  }) );
}
