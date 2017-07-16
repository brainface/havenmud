//
// Orc Cleric Leader - Karak Varn
// Coded by Ahriman@Haven
// 15 September 1997
//

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("varag");
  SetLevel(30 + random(7));
  SetGender("male");
  SetShort("Varag, Chief War-Priest of Saahagoth");
  SetId( ({ "varag","priest" }) );
  SetLong("Varag is a massive orc dressed in a flowing black robe "
          "complete with the tell-tale bulges of armor and weapons "
          "beneath.");
  SetTown("Karak");
  SetClass("priest");
  SetRace("orc");
  SetReligion("Saahagoth", "Saahagoth");
  SetPlayerTitles( ([
    "newbie"   : "the Saahagoth Faithful",
    "mortal"   : "the Saahagoth Crusader",
    "hm"       : "the Master Weirder of Saahagoth",
    "avatar"   : "the Holy Weirder of Saahagoth",
    "fighter"  : "the Saahagoth Monk",
    "cavalier" : "the Paladin of Saahagoth",
  ]) );
  SetRestrictRace(1);
  SetUniqueSkills( ([
  ]) );
  SetSpellBook( ([
    "protect"      : 100,
    "flaming arrow"    : 100,
    "holy shield" : 100
  ]) );
  SetInventory( ([
    K_OBJ + "/bflail" : "wield flail",
    K_OBJ + "/runea"  : "wear armor"
  ]) );
  SetFreeEquip( ([
    K_OBJ    + "/studded_leather" : 1,
    STD_HACK + "hand-axe" : 1,
  ]) );
  SetCombatAction(20, ({
    "!cast chaos bolt",
    "!cast hellfire",
  }) );
}
