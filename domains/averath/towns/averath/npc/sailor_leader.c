#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetTown("Averath");
  SetLimit(1);
  SetRace("human");
  SetBaseLanguage("Avera");     
  SetGender("male");
  SetClass("sailor");
  SetMorality(100);
  SetLevel(20);
  SetKeyName("Louis de Bourbon");
  SetId( ({ "louis", "bourbon", "admiral" }) );
  SetAdjectives( ({ "de", "louis", "grand", "admiral" }) );
  SetShort("Grand Admiral Louis de Bourbon");
  SetLong(
    "Grand Admiral Louis de Bourbon is the commander of the navy of the Duchy of Averath. "
    "His extensive mustache extends out nearly a foot from each side of his face. From the "
    "odd discoloration of his mustache, it is apparent that the Grand Admiral enjoys the "
    "occasional herbal treat."
    );
  SetPlayerTitles( ([
    "newbie" : "the Sailor",
    "mortal" : "the Crafty Sailor",
    "hm"     : "Captain $N",
    "legend" : "the Shore Raider",
    "avatar" : "the Scourge of the Fleet",
    ]) );
  SetCurrency("ducats", 30 + random(30) );
  SetInventory( ([
    STD_WEAPON + "slash/longsword" : "wield longsword",
    ]) );
  SetFreeEquipment( ([
    STD_WEAPON "slash/longsword" : 1,
    ]) );
}
