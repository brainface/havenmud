// Grym Rewrite
// Stolen from Haven Equipper
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("tiniv");
  SetId( ({ "tiniv" }) );
  SetAdjectives( ({ "assister", "youth", "equipper" }) );
  SetShort("Tiniv the Assister of Youth");
  SetLong(
    "Tiniv is an average-appearing human citizen. She has been charged "
    "by the Warlord of Grymxoria with the task of distributing free "
    "equipment to beginning adventurers in this town. She appears willing "
    "to help any who <ask> her or who <request> an item from her."
  );
  SetRace("nosferatu");
  SetClass("fighter");
  SetLevel(6);
  
  SetGender("female");
  SetMorality(-2000);
  SetCurrency("bloodgems", 100);
  SetAction(20, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
  }) );  
  SetLevelLimit(5);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "pole"  : STD_POLE "staff",
    "axe"   : STD_HACK "battle_axe",
    "bow"   : STD_PROJECTILE "bow_long_newbie",
    "fishing pole"  : STD_FISHING "pole",	
    ]) );
}
