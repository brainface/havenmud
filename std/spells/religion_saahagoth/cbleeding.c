#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("cause bleeding");
  SetSkills( ([
    "faith" : 100,
    "necromancy" : 100,
  ]) );
  SetRules("","LIV");
  SetSpellType(SPELL_COMBAT);
  SetDifficulty(190);
  SetReligions("Saahagoth");
  SetHelp(
    "This allows a powerful faithful to cause their target to spontaneously "
     "bleed. If they are already bleeding it makes the bleeding worse. "
  );
}

varargs int eventCast(object who, int level, mixed b, object array targets) {
  object target = targets[0];
  int resist;
  int chance = level + who->GetSkillLevel("necromancy");
  chance += random((int)who->GetSkillLevel("natural magic"));
  resist = target->GetMagicResistance() + target->GetLevel();
  
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
        }
        
  if(chance < resist) {
    send_messages( ({"grab", "shake"}),"$agent_name $agent_verb "
      "onto $target_name but $target_nominative $target_verb "
      "free.",who,target,environment(who));
  return 1;
  } 
  else {
  send_messages("grab","$agent_name $agent_verb onto $target_name causing "
    "$target_possessive skin to rip and tear, %^BOLD%^%^RED%^blood%^RESET%^ "
    "sprays out from $target_possessive wounds."
    ,who,target,environment(who));
  target->AddBleeding(level/5);
  return 1;
  }
}

