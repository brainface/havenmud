#include <lib.h>
#include <std.h>
#include "../lisht.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("Duamutef");
  SetLimit(1);
  SetShort("Duamutef the Charitable");
  SetId( ({ "duamutef", "aider", "equipper" }) );
  SetAdjectives( ({ "charitable" }) );
  SetRace("gnoll");
  SetLevelLimit(5);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "fishing pole" : LISHT_OBJ "newbie_pole",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "bow"   : STD_WEAPON "projectile/bow_long_newbie",
    ]) );
  SetBaseLanguage("Rehshai");
  SetLong("Duamutef is a kindly hearted gnoll who helps "
          "those in need by supplying the barest of essentials. "
          "He despises elves, but if one is a gnoll, just "
          "asking for his assistance will generally get him "
          "to comply with any charity he can perform.");
  SetGender("male");
  SetClass("merchant");
  SetLevel(6);
  SetCurrency("deben", 100);
  SetMorality(-300);
  SetAction(2, ({
    "!speak Do you want something?",
    "!speak Selket brings glory to those who help others.",
    "!speak Ask me, and I will help you.",
    "!emote cast his eyes around, as if hunting out elves.",
    }) );
}
