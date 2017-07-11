#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("dmitry");
  SetShort("Dmitry Yevo, Commander of the Prince's Own");
  SetId( ({ "dmitry", "fighter", "commander", "guard" }) );
  SetFriends( ({ "guard" }) );
  SetAdjectives( ({ "commander" }) );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetTown("Gurov");
  SetClass("fighter");
  SetPlayerTitles( ([
    "newbie" : "the Young Guard of Gurov",
    "mortal" : "the Gurovian Guard",
    "hm"     : "the Member of the Prince's Own",
    "legend" : "the Right Arm of the Prince",
    "avatar" : "the Defender of the North",
    ]) );
  SetFreeEquipment( ([
    STD_HACK  "hand-axe"   : 1,
    STD_SLASH "shortsword" : 1,
    ]) );
  SetLong(
    "Dmitry Yevo is the Commander of the Prince's Own. He is "
    "responsible for recruiting new soldiers and is a fine "
    "person to teach new <fighters>. One could <ask> him <to "
    "join fighters>."
    );
  SetGender("male");
  SetLevel(80);
  SetCombatAction(10, ({
  	"!disarm",
  	"disorient",
    }) );
  SetCurrency( ([
    "rubles" : 50 + random(30),
    ]) );
  SetInventory( ([
    STD_HACK "battle_axe"        : "wield axe",
    STD_CLOTHING "cloak/surcoat" : "wear surcoat",
    ]) );
  SetLimit(1);
}
