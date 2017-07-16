#include <lib.h>
#include <std.h>
#include "../rome.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("xoran");
  SetLimit(1);
  SetShort("Xoran Minimus, Aider of the Poor");
  SetId( ({ "xoran", "minimus", "aider", "equipper" }) );
  SetAdjectives( ({ "xoran" }) );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetLevelLimit(5);
  SetFreeEquipment( ([
    "epee"  : STD_PIERCE   "epee",
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "fishing pole"  : ROME_OBJ "newbie_pole",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    ]) );
  SetLong("Xoran Minimus, also known as Xoran the Generous, "
          "stands watch in the Colosseum to be sure that all "
          "trainees are equipped, if not well, at least to a "
          "bare minimum.  Simply requesting his assistance "
          "is enough to get his attention.");
  SetGender("male");
  SetClass("fighter");
  SetLevel(6);
  SetAction(2, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
    }) );
}
