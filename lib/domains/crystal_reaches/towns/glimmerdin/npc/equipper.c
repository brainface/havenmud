#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("jonah");
  SetLimit(1);
  SetShort("Jonah the Generous");
  SetId( ({ "jonah","dwarf" }) );
  SetAdjectives( ({ "generous" }) );
  SetRace("dwarf");
  SetClass("merchant");
  
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "epee"  : STD_PIERCE   "epee",
    "shirt" : STD_CLOTHING "small_shirt",
    "shoes" : STD_CLOTHING "small_shoes",
    "pants" : STD_CLOTHING "small_pants",
    "coat"  : STD_CLOTHING "small_coat",
    "fishing pole"  : G_OBJ "newbie_pole",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "axe"   : G_OBJ "axe",
    ]) );
  SetLong("Jonah the Generous, "
          "stands patiently in the Keep to be sure that all "
          "dwarves are equipped, if not well, at least to a "
          "bare minimum.  Simply requesting his assistance "
          "is enough to get his attention.");
  SetGender("male");
  SetLevel(6);
  SetMorality(100);
  SetAction(2, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
    }) );
}
