// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("modious");
  SetId( ({ "modious", "slickblade", "orc" }) );
  SetAdjectives( ({ "modious", "slickblade" }) );
  SetShort("Modious Slickblade");
  SetLong(
    "Modious is an enormous brute of an orc. Beneath his matted skin his "
    "muscles bulge and ripple with every movement. Accompanying his unusual "
    "bulk is a remarkably cunning look in his dark red eyes, unexpected in "
    "such an accomplished warrior among the orcs, who do not pride themselves "
    "on higher thinking when it comes to combat. The scars on Modious' skin "
    "and brands displayed on his shoulder indicate that he is an accomplished "
    "fighter."
  );
  SetRace("orc");
  SetClass("fighter");
  SetGender("male");
  SetLevel(55);
  SetTown("Karak");
  SetReligion("Saahagoth");
  SetMorality(-500);
  SetInventory( ([
    KARAK_OBJ + "slickblade" : "wield sword",
  ]) );
  SetAction(5, ({
    "!emote mumbles to himself.",
    "!emote flexes his hands, clicking his long nails together.",
  }) );
  SetPlayerTitles( ([
    "newbie" : "the dirt-low initiate of the Horde",
    "mortal" : "Peon $N the servant of the Horde",
    "hm"     : "Stonecrusher $N the Backbone of the Orcish Horde",
    "legend" : "Axehand $N the mighty Fist of the Orcish Horde ",
    "avatar" : "Blooddrinker $N the revered Warmonger of the Orcish Horde",
  ]) );
}
