#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() 
{
  spell::create();
  SetSpell("color spray");
  SetReligions("Eclat");  
  SetRules("LIV", "");
  SetSpellType(SPELL_COMBAT);
  SetReligions("Eclat");
  SetSkills( ([
    "natural magic" : 50,
	  ]) );
  SetDifficulty(40);
  SetHelp(
    "This spell creates a spectrum of color that blinds the "
	"target.");
}
 
int eventCast(object who, int level, mixed limb, object array targets) 
  {
  int chance;
  foreach(object target in targets) 
  {
    if (environment(target) != environment(who)) targets -= ({ target });
  }
  if (!sizeof(targets)) 
  {
    send_messages(({ "" }),"Small sparks fizzle "
      "about $agent_possessive_noun fingers.",
      who,targets,environment(who));
    return 1;
  }
  chance = random(level/5) + who->GetSkillLevel("natural magic")/3;
  chance -= (targets[0]->GetLevel() + targets[0]->GetMagicResistance());
  if (chance < 0) 
  {
    send_messages(({ "" }),"Small sparks fizzle "
      "about $agent_possessive_noun fingers.",
      who,targets[0],environment(who));
    return 1;
  }
  else 
  {
    send_messages(({ "spread" }),"$agent_name $agent_verb "
      "$agent_possessive_noun fingers and a stream of color "
      "sprays into $target_possessive_noun face.",
      who,targets[0],environment(who));
    targets[0]->eventBlind(who, chance, ({ "","The swirls of color "
	"surrounding $agent_possessive_noun face fade into "
	"nothingness." }));
    return 1;
  }
}
