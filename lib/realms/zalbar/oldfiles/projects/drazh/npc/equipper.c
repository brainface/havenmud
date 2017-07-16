// by Dahaka
// Aug 2004

#include <lib.h>
#include <std.h>
#include "../drazh.h"

inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("frikkr");
  SetLimit(1);
  SetShort("Frikkr, Master of Arms");
  SetId( ({ "frikkr","skaven"}) );
  SetAdjectives( ({"master","of","arms" }) );
  SetRace("skaven");
  SetTown("Drazh");
  
  SetFreeEquipment( ([
    "sword"           : V_OBJ + "newbie_sword",
    "axe"             : V_OBJ + "newbie_axe",
    "leather vest"    : V_OBJ + "lvest",
    "leather pants"   : V_OBJ + "lpants",
    "buckler"         : V_OBJ + "buckler",
    "footman's lance" : V_OBJ + "newbie_lance",
    "robe"            : V_OBJ + "newbie_robe",
    "breastplate"     : V_OBJ + "recruit_armour",
    "staff"           : V_OBJ + "newbie_staff",
    "knife"           : V_OBJ + "newbie_knife",
    "tuck"            : V_OBJ + "newbie_tuck",
    "shirt"           : STD_CLOTHING "shirt",
    "shoes"           : STD_CLOTHING "shoes",
    "pants"           : STD_CLOTHING "pants",
    "coat"            : STD_CLOTHING "coat",
    "helmet"          : STD_ARMOUR "free_armour/medium/oldhelmet",
    "glove"           : STD_ARMOUR "free_armour/medium/oldglove",
    ]) );
  SetLong(
    "Frikkr is a tall dark furred skaven with one missing ear. Frikkr "
    "is the Master of Arms for the town watch. He will assist any skaven "
    "of Drazh.");
  SetGender("male");
  SetClass("fighter");
  SetLevel(15);
  SetCurrency("imperials", 40);
  SetLevelLimit(10);
  SetMorality(-800);
  SetInventory( ([
    V_OBJ + "scale_mail" : "wear armour",
    V_OBJ + "lpants"     : "wear pants",
    ]) );
  SetAction(2, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
    }) );
}
