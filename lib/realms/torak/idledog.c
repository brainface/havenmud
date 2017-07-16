#include <lib.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetProperty("lycanthrope", 1);
  SetKeyName("werewolf");
  SetId("werewolf");
  SetAdjectives( ({ "vicious", "grey" }) );
  SetShort("a vicious grey werewolf");
  SetLong(
    "A vicious grey werewolf.  dun dun dun.  "
  );
  SetRace("wolf", "daemon");
  SetClass("horror");
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(BLUNT, "immune");
  SetResistance(HUNGER, "immune");
  SetResistance(DISEASE, "immune");
  SetSkill("brawling", 1, 1);
  SetSkill("necromancy", 1, 1);
  SetLevel(80);
  if(random(2)) { SetGender("male"); }
   else  { SetGender("female"); }
  SetFirstCommands( ({
    "wield all",
  }) );
  SetReligion("Rath Cult");
  SetSize(SIZE_LARGE);
  SetInventory( ([
    ]) );
  SetSpellBook( ([
    ]) );
  SetCombatAction(8, ({
    "!scream",
    "!disorient",
    "!uppercut",
  }) );
  SetAction(5, ({ 
    "!say DUN DUN DUN",
    "!emote dun dun dun",
    "!bark",
    "!say but... WHERE... is the WOLF...? eh? eh?",
    "!say I'll rip your lungs out, Jim! Also you, Sue. But not you, Bill. We're totes cool.",
    "!emote dances with you doggily.",
  }));
}

