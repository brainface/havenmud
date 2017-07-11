#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("itsak");
  SetLimit(1);
  SetShort("Itsak the Generous");
  SetId( ({ "itsak", "equipper" }) );
  SetAdjectives( ({ "generous" }) );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "epee"  : STD_PIERCE   "epee",
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "fishing pole"  : GUROV_OBJ "newbie_pole",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "leather pants" : STD_ARMOUR "free_armour/medium/oldpants",
    "vest" : STD_ARMOUR "free_armour/medium/oldvest",
    "glove" : STD_ARMOUR "free_armour/medium/oldglove",
    "helmet" : STD_ARMOUR "free_armour/medium/oldhelmet",
    "boots" : STD_ARMOUR "free_armour/medium/oldboots",
    ]) );
  SetLong(
    "Itsak the Generous lives a peaceful live in Gurov.  His main goal "
    "in life is to see young people have enough equipment to survive "
    "the harsh reality of life in the Principality. Simply requesting his assistance "
    "is enough to get his attention.");
  SetGender("male");
  SetClass("rogue");
  SetLevel(6);
  SetMorality(100);
  SetAction(2, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
    }) );
}
