#include <lib.h>
#include <std.h>
#include "../dalnairn.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("barsun");
  SetLimit(1);
  SetId( ({ "barsun", "aider", "equipper" }) );
  SetShort("Barsun the Punished");
  SetLong("This dark-dwarf is stocky man who has been shaven completely "
          "bald.  Barsun, once a very wealthy merchant, is known as the "
          "Punished for trying to steal from Derek. As punishment, Derek "
          "ordered Barsun shaven and to donate freely any equipment to the "
          "youth of Dalnairn before they journey beyond the city gates. ");
  SetAdjectives( ({ "barsun" }) );
  SetRace("dark-dwarf");
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "small_shirt",
    "shoes" : STD_CLOTHING "small_shoes",
    "pants" : STD_CLOTHING "small_pants",
    "coat"  : STD_CLOTHING "small_coat",
    "sword" : STD_SLASH    "shortsword",
    "knife" : STD_WEAPON   "small_knife",
    "axe"   : STD_WEAPON   "hatchet",
    "staff" : STD_WEAPON   "staff",
    ]) );
  
  SetGender("male");
  SetClass("merchant");
  SetReligion("Soirin");
  SetMorality(-350);
  SetLevel(6);
  SetCurrency("shards", 10);
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(2, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
    }) );
}
