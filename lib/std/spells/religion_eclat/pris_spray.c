#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() 
{
  spell::create();
  SetSpell("prismatic spray");
  SetReligions("Eclat");  
  SetRules("LIV", "");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "natural magic" : 150,
    "enchantment"   : 150,
  ]) );
  SetDifficulty(45);
  SetHelp(
    "This spell creates a blast of colors at the target, "
    "each generating a type of damage.  The higher level "
    "the caster the more powerful the spell.");
}
 
int eventCast(object who, int level, mixed limb, object array targets) {
  int chance;
  
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
        } 
  foreach(object target in targets) {
    if (environment(target) != environment(who)) targets -= ({ target });
  }
  if (!sizeof(targets)) {
    message("system", "The spell fails.", who);
    return 0;
  }
  chance = level + random((int)who->GetSkillLevel("natural magic"));
  chance -= targets[0]->GetLevel();

    send_messages(({ "blast" }),"$agent_name $agent_verb $target_name "
      "with %^MAGENTA%^purple%^RESET%^ color!",who,targets,environment(who));
    targets->eventReceiveDamage(who, MAGIC, GetDamage(level), 0);
    
    send_messages(({ "blast" }),"$agent_name $agent_verb $target_name "
      "with %^RED%^red%^RESET%^ color!",who,targets,environment(who));
    targets->eventReceiveDamage(who, HEAT, GetDamage(level), 0);
    
    send_messages(({ "blast" }),"$agent_name $agent_verb $target_name "
      "with %^ORANGE%^orange%^RESET%^ color!",who,targets,environment(who));
    targets->eventReceiveDamage(who, SHOCK, GetDamage(level), 0);
    
    send_messages(({ "blast" }),"$agent_name $agent_verb $target_name "
      "with %^YELLOW%^yellow%^RESET%^ color!",who,targets,environment(who));
    targets->eventReceiveDamage(who, ACID, GetDamage(level), 0);
    
    send_messages(({ "blast" }),"$agent_name $agent_verb $target_name "
      "with %^GREEN%^green%^RESET%^ color!",who,targets,environment(who));
    targets->eventReceiveDamage(who, POISON, GetDamage(level), 0);
    
    send_messages(({ "blast" }),"$agent_name $agent_verb $target_name "
      "with %^CYAN%^cyan%^RESET%^ color!",who,targets,environment(who));
    targets->eventReceiveDamage(who, COLD, GetDamage(level), 0);
    
    send_messages(({ "blast" }),"$agent_name $agent_verb $target_name "
      "with %^BLUE%^blue%^RESET%^ color!",who,targets,environment(who));
    targets->eventReceiveDamage(who, WATER, GetDamage(level), 0);
    targets->eventParalyze(random(5));
    targets->eventCollapse();
    return 1;
}
