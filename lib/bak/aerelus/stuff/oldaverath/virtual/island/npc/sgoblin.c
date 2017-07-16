#include <lib.h>
#include <damage_types.h>
#include <domains.h>

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("short goblin");
  SetShort("a short goblin");
  SetId( ({ "goblin" }) );
  SetAdjectives( ({ "short" }) );
  SetLong("This goblin is truelly a pathetic example of its race. "
          "It stands at around 3 feet tall, and in its eyes is "
          "nothing but fear and loathing.");
  SetRace("goblin");
  SetClass("fighter");
  SetGender("male");
  SetLevel(5);
  AddCurrency("ducats", random(10));
  SetCombatAction(3, ({
    "!emote runs at you screaming incoherently.",
    "!emote runs away from you screaming incoherently.",
    }) );
  SetAction(3, ({
    "!emote mutters quietly to itself.",
    }) );
  SetInventory( ([ 
     AVERATH_OBJ "rssword.c" : "wield sword",
     AVERATH_OBJ "sshield.c" : "wear shield on right arm", 
     AVERATH_OBJ "tlarmour.c" : "wear armour",
     ]) );
  SetEncounter(0);
  SetMorality(-20);
}
