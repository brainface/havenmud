
#include <lib.h>
#include <std.h>
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("ashurbanipal");
  SetLimit(1);
  SetShort("Ashurbanipal the Youth Aider");
  SetId( ({ "ashurbanipal", "aider", "equipper" }) );
  SetAdjectives( ({ "aider", "equipper" }) );
  SetRace("lamrani");
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "vest"   : STD_ARMOUR "free_armour/medium/oldvest",
    "leather pants"  : STD_ARMOUR "free_armour/medium/oldpants",
    "boots"  : STD_ARMOUR "free_armour/medium/oldboots",
    "glove"  : STD_ARMOUR "free_armour/medium/oldglove",
    "helmet" : STD_ARMOUR "free_armour/medium/oldhelmet",
    "fishing pole" : STD_FISHING "pole",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "bow"   : STD_WEAPON "projectile/bow_long_newbie",
    "staff" : STD_WEAPON "staff",
    "epee"  : STD_WEAPON "pierce/epee",
    ]) );
  SetLong("Ashurbanipal has been designated by Mingad"
          " Mardan the mayor to aide the young Jidoorians"
          " in their quest for knowledge. She sits around"
          " in the library offering free goods to those who"
          " are interested, and young enough, to receive.");
  SetGender("female");
  SetClass("evoker");
  SetSkill("melee combat",1,2);
  SetReligion("Magildan");
  SetMorality(350);
  SetLevel(6);
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(2, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
    }) );
}
