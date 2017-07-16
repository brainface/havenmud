
#include <lib.h>
inherit LIB_HEALER;

static void create() {
  healer::create();
  
  SetKeyName("Iana");
  SetShort("Iana the Healer");
  SetId( ({ "iana", "healer", }) );
  SetAdjectives( ({ }) );
  SetLong("Iana has a care-free, friendly look in her eyes, which "
          "gives her a pleasant enough demeanor. She has soft "
          "brown eyes and long, dark hair. She is obviously a native "
          "of Parva, but seems to be much happier than the norm.");
  SetGender("female");
  SetRace("human");
  SetClass("priest");
  
  SetSkill("melee combat", 1, 1);
  SetLevel(20);
  SetTown("Parva");
  SetMorality(100);
  SetLocalCurrency("oros");
  SetSpellBook( ([
        "lightning shield" : 100,
        "sanctify"                               : 100,
        ]) );
  SetFees( ([
        "resurrect" : 10,
        "magic"     : 0,
        "stamina"   : 5,
        "health"    : 3,
        "restore"   : 5,
        ]) );
  SetAction(5, ({ 
        "!say Come!  Come!  Let me heal you!",
    "!say For a small price I will heal you!",
    "!say Welcome, all!","!emote dances.",
    "!emote gleefully claps.",
    "!giggle",
    "!laugh",
    "!say Bright colors make life worth living.",
    "!smile" 
    }) );
  SetCombatAction(30, ({ 
        "!shout Help me! Heelp!",
        "!cast lightning shield",
    "!shout Please, come save me!",
    "!say Stop you rogue!",
    "!say Get out of my house!",
    "!say Leave me!",
    "!cast sanctify",
    "!say Help!",
    "!say Foul demon!",
    "!say Evil creature!" 
    }) );
}

