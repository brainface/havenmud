//Selket@Haven
//2006
// Mahkefel 2011
//   --made cast spells/shields etc.
//   --fixed some skill weirdness.
#include <lib.h>
#include <std.h>
#include "../lisht.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("neferu");
  SetShort("Neferu, the Justified");
  SetId( ({ "neferu", "teacher", "priestess" }) );
  SetAdjectives( ({ "justified" }) );
  SetSkill("faith",1,1);
  SetSkill("necromancy",1,1);
  SetSkill("evokation",1,1);
  SetSkill("pole combat", 1, 1);
  SetLevel(70);


  SetTown("Lisht");
  SetRace( "gnoll");
  SetGender("female");
  SetBaseLanguage("Rehshai");
  SetLong("Neferu has given her life to Selket in exchange "
          "for the power to pass knowledge to others. Just "
          "as her name implies, she is stunningly beautiful "
          "even for a gnoll. It is her duty to oversee the "
          "rituals of this temple, and she upholds it with a "
          "joyous, quiet dignity.");
  SetReligion("Enniae");
  SetSpellBook( ([
    "divine retribution" : 100,
    "barrier of faith" : 100,
    "curse" : 100,
    ]) );
  SetAction(5, ({
    "!emote anoints the altar with perfumed oils.",
    "!speak Shall I teach you of she who gives us breath?",
    "!speak All praises to Selket. May she bring us fortune.",
    "!speak Are you here to learn, little one?",
  }) );
  SetCombatAction(15, ({
    "!cast curse",
    "!cast divine retribution",
    "!cast harm body",
  }) );
  SetCurrency("deben", 750);
  SetInventory( ([
    STD_POLE + "staff" : "wield staff",
    LISHT_OBJ "ldress" : "wear dress",
    LISHT_OBJ "cinn_sash" : "wear sash",
  ]) );
  SetTrainingSkills( ({
    "pole combat",
    "bargaining",
    "skinning",
  }) );

  SetFirstCommands( ({
    "cast barrier of faith",
    "cast barrier of faith",
    "cast barrier of faith",
  }) );
  SetMorality(-1500); // ebil? right?
}

