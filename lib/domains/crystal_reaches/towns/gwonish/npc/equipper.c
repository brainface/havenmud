#include <lib.h>
#include <std.h>
#include "../gwonish.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("krral");
  SetLimit(1);
  SetShort("Krral the raider");
  SetId( ({ "krral", "raider", "equipper" }) );
 
  SetRace("lizardman");
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "fishing pole"  : STD_FISHING "pole",
    "sword" : GWONISH_OBJ "serrated_newbie",
    "club"  : GWONISH_OBJ "newbie_club",
    "knife" : STD_KNIFE "hunting_knife",
    "staff" : STD_WEAPON "staff",

    ]) );
  SetLong("Krral the raider is known for his cunning ability for finding "
          "equipment to supply to a young lizardman raider. Ask Krral "
          "for some help, if he is in a good mood he may not charge "
          "you.");
  SetGender("male");
  SetClass("fighter");
  SetSkill("melee combat",1,2);
  SetReligion("Kuthar");
  SetMorality(-350);
  SetLevel(6);
  SetCurrency("rounds", 10);
  SetInventory( ([
     STD_CLOTHING "body/loin" : "wear loincloth",
     ]) );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(2, ({
    "!speak Perhaps you need my assistance?",
    "!speak Do you have any money?",
    "!speak Ask me, and I will help you.",
    }) );
}
