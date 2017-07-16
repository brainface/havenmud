// Proximo@Pax Imperialis

#include <lib.h>
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("quintis");
  SetId( ({ "merchant", "man" }) );
  SetAdjectives( ({ "bald", "filthy", "wandering" }) );
  SetShort("a bald, filthy wandering man");
  SetLong(
     "This unkept and rude man is a wanderer who travels far and wide to seek "
     "new riches and to see the world. His face looks to be covered in dirt, with his teeth "
     "heavily yellowed and rotting out of his mouth. His breath is almost toxic enough "
     "to bring down the strongest of any Oxen. He is very blunt and rude, laughing all the "
     "while he points out the flaws in every person he meets. He is by far a very "
     "foul man. "
  );
  SetLimit(1);
  SetClass("fighter");
  SetWander(5);
  SetRace("human");
  SetBaseLanguage("Imperial");
  SetMorality(-15);
  SetGender("male");
  SetSkill("melee combat", 1, 2);
  SetSkill("melee combat", 1, 2);
  SetSkill("pole combat", 1, 2);
  SetSkill("pole combat", 1, 2);
  SetInventory( ([
     "/domains/peninsula/virtual/obj/filthy_robe" : "wear robe",
     "/domains/peninsula/virtual/obj/staff" : "wield staff",
  ]) );
  SetLevel(7);
   SetCurrency("imperials", 5 + random(55));
  SetAction(5, ({
     "!laugh",
     "!fart",
     "!burp",
     "!say I like to travel, yes I do!",
     "!say Hey, don't poke me, ok?",
     "!say Whoa look out, I ain't got time to play 'round, yes?",
     "!say Hah and they call me ugly, look at you!",
     "!smirk",
     "!say I haven't bathed in months, ain't going to start now!",
     "!say Eh...",
  }) );
  SetCombatAction(5, ({
     "!say Hey! I was only kidding around!",
     "!say Nooo don't hurt me! I'm a coward! Please!",
     "!say Ahh Damnit I lost another tooth!",
     "!say You fight like a little girl...",
  }) );
}
