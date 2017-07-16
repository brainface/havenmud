#include <lib.h>
#include <damage_types.h>
#include <domains.h>

inherit LIB_NPC;

static void create() {
  ::create();

  SetKeyName("skinny goblin");
  SetId( ({"goblin"}) );
  SetAdjectives( ({"skinny"}) );
  SetShort("a skinny goblin");
  SetLong("Quite skinny and short, this goblin looks like a "
     "weakling and you can see the skin hanging loosely from "
     "it's bones. It has a crazed look in it's eyes and appears "
     "to be very hungry.");
  SetRace("goblin");
  SetClass("fighter");
  SetGender("male");
  SetLevel(8);
  AddCurrency("ducats", random(10));
  SetSkill("blunt defense", 5, 2);
  SetSkill("knife defense", 2, 2);
  SetCombatAction(3, ({
     "!emote runs at you screaming incoherently.",
     "!emote runs around the room screaming before charging you again.",
    }) );
  SetAction(3, ({
     "!emote grumbles angrily.",
     "!emote screams loudly while glancing about nervously.",
    }) );
  SetInventory( ([
     AVERATH_OBJ "tlarmour" : "wear armour",
     AVERATH_OBJ "sshield.c" : "wear shield on right arm", 
     AVERATH_OBJ "wclub" : "wield club",
     ]) );
  SetEncounter(0);
  SetMorality(-20);
}
