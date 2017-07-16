// Karak Recode
// Stolen from Haven Equipper
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("nyeh");
  SetId( ({ "nyeh" }) );
  SetAdjectives( ({ "horde", "equipper" }) );
  SetShort("Nyeh the Horde Equipper");
  SetLong(
    "Nyeh is a half-orc of normal size who works for the orcish Horde in "
    "weapon and equipment procurement. More specifically, she provides "
    "beginning adventurers with free equipment so that they can begin their "
    "quests on solid footing. It appears that she would describe more of "
    "what she has if one were to <ask> her or <request> a piece of equipment "
    "from her."
  );
  SetRace("half-orc");
  SetGender("female");
  SetClass("fighter");
  SetLevel(6);
  SetReligion("Saahagoth");
  SetMorality(-50);
  SetCurrency("imperials", 10);
  SetAction(20, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
  }) );  
  SetLevelLimit(5);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "lg_shirt",
    "shoes" : STD_CLOTHING "lg_shoes",
    "pants" : STD_CLOTHING "lg_pants",
    "coat"  : STD_CLOTHING "lg_coat",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "staff" : STD_POLE "staff",
    "axe"   : STD_HACK "battle_axe",
    "bow"   : STD_PROJECTILE "bow_long_newbie",
    "fishing pole"  : STD_FISHING "pole",	
    ]) );
}
