#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <magic_protection.h>

inherit LIB_SPELL;

static void create() {
     spell::create();
     SetSpell("shockwave");
     SetSpellType(SPELL_COMBAT);
     SetRules("", "LIV");
     SetDifficulty(20);
     SetSkills( ([
      "faith"      : 35,
      "evokation" : 35,
     ]) );
     SetCooldown(6);
     SetDamageType(MAGIC);
     SetAutoDamage(0);
     SetMorality(0);
     SetHelp("Syntax: <cast shockwave on LIVING>\n\n"
          "This clerical evokation spell allows the "
          "caster to create a shockwave to blast "
          "where the target is standing stunning them and knocking them to the "
          "ground.\n"
          "This spell scales with level."
          );
}

int CanCast(object who, int level, string limb, object array targets) {
     foreach(object target in targets) {
          if (target->GetParalyzed()) {
               message("my_action","But "+target->GetName()+" is "
                    "already paralyzed!",who);
               return 0;
          } else {
               return spell::CanCast(who, level, limb, targets);
          }
     }
}

int eventCast(object who, int level, mixed limb, object array targets) {
     int chance;
     chance = level + random((int)who->GetSkillLevel("faith"));
    chance -= targets[0]->GetLevel() * 5;
    
    if(!present(targets[0]->GetKeyName(),environment(who))) return 0;

    // scale with level
    if( CanAttack(who, targets, who->GetSkillLevel("evokation")/2 + level/5) == -1 ) {
      who->eventPrint("Your powers fail you.");
      return 0;
    }
    who->AddCooldown(GetSpell(), GetCooldown());

    send_messages("shake", "$agent_name $agent_verb "
                     "$target_name with a %^RED%^shockwave%^RESET%^."
                     ,who,targets,
                     environment(who));
    targets->eventCollapse();
    return 1;
}

