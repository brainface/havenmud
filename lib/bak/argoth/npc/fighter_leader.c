#include <lib.h>
#include "../argoth.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("modious");
  SetShort("Modious Slickblade");
  SetId( ({ "modious", "modious slickblade", "slickblade" }) );
  SetLong(
    "Modious is an enormous brute of an orc.  It is obvious from "
    "the scars on his skin, and the medals on his armour, that he is an "
    "accomplished fighter."
  );
  SetRace("orc");
  SetClass("fighter");
  SetLevel(45);
  SetGender("male");
  SetTown("Karak");
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Fighter",
    "mortal" : "the Defender of Argoth",
    "hm" : "the Render of Flesh",
  ]) );
  SetInventory( ([
    ARGOTH_OBJ + "slickblade.c" : "wield sword",
  ]) );
  SetAction(5, ({
    "!emote mumbles to himself.",
    "!emote flexes his hands, clicking his long nails together.",
  }) );
  SetFreeEquip( ([
    ARGOTH_OBJ + "cleaver.c" : 1,
  ]) );
}
