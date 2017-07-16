// torak@Haven
// 1/June/2017
// Spirit Totem
// Kuthar Shaman Ancestor Communicator
// Magic 8 Ball with status effects

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("spirit totem");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
     "faith" : 1,
  ]) );
  SetStaminaCost(100, 25);
  SetMagicCost(10, 10);
  SetDifficulty(20);
  SetMorality(0); // atonement, +bless
  SetConjure("");   // place appropriate totem from race check //
  SetMessages( ({
     ({
     ({ "verb here", }),
      "%^BLUE%^Race check for requirements and totem creation.%^RESET%^"
     }),
  }) );
  SetHelp(
    "Casting a Spirit Totem is how a Shaman of Kuthar communicates "
	"with their ancestors. Simply follow the instructions. "
	"cast spirit totem on <target>"
	"        TARGET TYPES"
	"<<-------------------------->>"
	"  Barian Human : Edibles"
	"  Gwonish Lizardman : Corpses"
	"  Kreshen Goblin : Drinkables"
	);
// a race based check for spell requirements and totem spawned.
// ex: lizardman would need a corpse but a halfling corpse would be better.
// part magic 8-ball part alignment fixer and bless, this thing gets prayers going.
// The totem is a eventually self-Destructing Object which would random list
// & mentally answer questions
// Questions and magic 8-ball answers will appear on the prayer channel.
// effects/durations would scale with player level and SetValue as appropriate
}


