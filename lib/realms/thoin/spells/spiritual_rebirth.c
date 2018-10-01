// Artanis@Haven (July 24, 2004)

#include <lib.h>
#include <dirs.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("spiritual rebirth");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
     "faith" : 20,
     "conjuring" : 30,
  ]) );
  SetMagicCost(120, 150);
  SetStaminaCost(25, 50);
  SetDifficulty(20);
  SetRecoveryTime(1 + random(2));
  SetConjure(DIR_SPELLS "/obj/spirit_reb_ob");
  SetHelp(
     "This is one of many talents possessd by the Kuthar. "
     "Shamans of Kuthar are renouned for their ability to contact "
     "ancestors from many generations ago to assist them from "
     "time to time. This spell summons forth an ancient spirit "
     "that assists the caster. "
  );
 }

int CanCast(object who, int level, string limb, object *targets) {
  object ob;
  if ( ob = present("spirit", environment(who)) ) {
    if( ob->id("spirit_kuthar") ) {
      message("system", "You already have a spirit!", who);
      return 0;
    }
  }
  return spell::CanCast(who, level, limb, targets);
  }

int eventCast(object who, int level, mixed limb, object *targets) {
  object critter;
  critter = new(GetConjure());

  if (!present(critter, environment(who) ) ) {
    critter->eventMove(environment(who));
    }

  critter->eventForce("follow " + who->GetKeyName());
  critter->SetLevel(critter->GetLevel() + who->GetLevel()/5);
  critter->SetOwner(who->GetKeyName());
  who->eventForce("lead first spirit");

  send_messages("call", "$agent_name $agent_verb forth an %^CYAN%^"
                       "ancient spirit%^RESET%^ to assist $agent_objective. ",
                       who, critter, environment(who));

  return 1;
  }
