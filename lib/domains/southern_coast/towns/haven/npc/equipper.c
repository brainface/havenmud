#include <lib.h>
#include <std.h>
#include "../haven.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("loran");
  SetLimit(1);
  SetShort("Loran the Aider of Youth");
  SetId( ({ "loran", "aider", "equipper" }) );
  SetAdjectives( ({ "loran" }) );
  SetRace("elf");
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "fishing pole"  : H_OBJ "newbie_pole",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "bow"   : STD_WEAPON "projectile/bow_long_newbie",
    "staff" : STD_WEAPON "staff",
    "epee"  : STD_WEAPON "pierce/epee",
    ]) );
  SetLong("Loran, also known as Loran the Generous, "
          "operates in Haven Town to be sure that all "
          "young people are aided, if not well, at least to a "
          "bare minimum. Simply requesting his assistance "
          "is enough to get his attention.");
  SetGender("male");
  SetClass("fighter");
  SetSkill("melee combat",1,2);
  SetReligion("Kylin");
  SetMorality(350);
  SetLevel(6);
  SetCurrency("imperials", 10);
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(2, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
    }) );
}
