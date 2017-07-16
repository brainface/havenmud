#include <lib.h>
#include <std.h>
#include <dirs.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("summon lesser effigy");
  SetSpellType(SPELL_OTHER);
  SetMagicCost(100, 300);
  SetSkills( ([
    "faith"       : 150,
    ]) );
  SetRules("");
  SetRecoveryTime(50);
  SetDifficulty(50);
  SetHelp(
    "Summoning a lesser effigy is a way for very powerful clergy "
    "to demonstrate their faith.  Use of this spell is draining "
    "and disorienting, but can often be one of the most powerful "
    "spells that the cleric or priest holds."
    );
}

varargs int CanCast(object who, int level, mixed q, object *t) {
  object *effigies = children(DIR_SPELLS "/obj/lesser_effigy_ob");
  foreach(object eff in effigies) {
    if (eff->GetSummoner() == who->GetKeyName()) {
      who->eventPrint("But you already have an effigy summoned!");
      return 0;
    }
  }
  return ::CanCast(who, level, q, t);
}

varargs int eventCast(object who, int level, mixed q, object *t) {
  object eff = new(STD_SPELLS "obj/lesser_effigy_ob");
  if (!eff) {
    who->eventPrint("Something has gone wrong!");
    return 1;
    }
  eff->eventMove(environment(who));
  eff->SetReligion(who->GetReligion());
  eff->SetSummoner(who->GetKeyName());
  eff->SetOwner(who->GetKeyName());
  eff->SetLevel(eff->GetLevel() + who->GetLevel()/5);
  switch(who->GetReligion()) {
    case "Aberach":
      send_messages( ({ "call", }),
        "%^BOLD%^RED%^With a deep, resounding boom of $agent_possessive voice, $agent_name "
        "$agent_verb a fountain of flames from the air itself.%^RESET%^",
        who, eff, environment(eff) );
      send_messages( ({ "have", }),
        "%^BOLD%^RED%^"
        "As the chant end, it becomes apparent that $agent_name $agent_verb summoned " + eff->GetShort() + "!%^RESET%^",
        who, eff, environment(eff) );
      break;
    case "Kylin":
       send_messages( ({ "begin", }),
         "%^BOLD%^BLUE%^With a deep voice, lower by far than anything deemed normal, $agent_name "
         "$agent_verb a chant with words that seem alien.%^RESET%^",
         who, eff, environment(eff) );
       send_messages( ({ "yell", "scream" }), 
         "%^BOLD%^BLUE%^Suddenly, $agent_nominative $agent_verb out in holy ecstasy as $agent_nominative "
         "$agent_verb with the power of $agent_possessive faith.%^RESET%^",
         who, eff, environment(eff) );
       send_messages( ({  }),
         "BOLD%^BLUE%^"
         "A burst of brilliant%^WHITE%^%^BOLD%^ white light%^BLUE%^BOLD%^ tears forth from $agent_possessive "
         "very soul and when it ends " + eff->GetShort() + " has been summoned!%^RESET%^",
         who, eff, environment(eff) );
         break;
    case "SaaHaGoth":
      send_messages( ({ "summon", "begin" }),
        "%^RED%^With a scream of horror $agent_name "
        "$agent_verb a chaotic rift from nothingness and $agent_verb to chant..%^RESET%^",
        who, eff, environment(eff) );
      send_messages( ({ "have", }),
        "%^RED%^"
        "As the chant end, " + eff->GetShort() + " steps out of the rift!%^RESET%^",
        who, eff, environment(eff) );
      break;
    default:  /* Yeah, I suck */
       send_messages( ({ "summon" }),
         "$agent_name $agent_verb a lesser effigy of $agent_possessive faith!",
         who, eff, environment(eff) );
       break;
    }
  return 1;
}

