#include <lib.h>
#include <damage_types.h>
#include <domains.h>

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("hungry beggar");
  SetShort("a hungry beggar");
  SetId( ({ "beggar", "human", }) );
  SetAdjectives( ({ "hungry" }) );
  SetLong("Hunched shoulders, and down cast eyes give an even more "
          "pitiful look to this old man, who has been forced to live "
          "in the sewers. Filth covers his tattered clothing, and "
          "from a distance things can be seen crawling in and out of "
          "his hair.");
  SetRace("human");
  SetClass("fighter");
  SetGender("male");
  SetLevel(2);
  AddCurrency("ducats", random(3));
  SetCombatAction(3, ({
    "!emote whines pathetically and looks for a way to escape."
    }) );
  SetAction(3, ({
    "!emote stumbles around, his hollow eyes looking around for something to
eat.",
    "!emote holds his hands out, asking for alms.",
    "!say could you spare a couple of ducats for a poor old man?",
    }) );
  SetInventory( ([ 
     AVERATH_OBJ "tpants.c" : "wear pants",
     AVERATH_OBJ "tshirt.c" : "wear shirt", 
     ]) );
  SetEncounter(0);
  SetMorality(50);
}
