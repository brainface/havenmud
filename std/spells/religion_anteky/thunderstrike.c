// fire whirl
// midbie drood area effect spell
// mahkefel 2011
//   if this spell causes random runtimes, remove the last function block.
// hidden effect, knocks enemies down randomly
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("thunderstrike");
  SetRules("");

  SetEnhanceSkills( ({ "shock magic" }) );
  SetSkills( ([
    "faith" : 120,
    "evokation" : 120,
  ]) );
  SetDamageType(SHOCK|SOUND);
  SetStaminaCost(50, 25);
  SetAutoDamage(0);
  SetAreaSpell(1);
  SetSpellType(SPELL_COMBAT);
  SetDifficulty(100);
  SetReligions("Anteky");
  SetMessages( ({
    ({"", "$agent_possessive_noun %^YELLOW%^lightning%^RESET%^ "
      "flashes far above $target_name." }),
    ({"", "$agent_possessive_noun %^BOLD%^%^WHITE%^thunder%^RESET%^ "
      "rattles $target_name!" }),
    ({"", "$agent_possessive_noun %^BOLD%^YELLOW%^lightning%^RESET%^ "
      "smites $target_name with a loud crash of %^BOLD%^WHITE%^thunder!%^RESET%^ " }),
    }) );
  SetHelp(
    "The followers of the One God can call upon him to "
    "fell entire armies with the sudden fury of an angry and "
    "merciless sky."
  );
}

// broadcast a message to the room
int eventCast(object who, int level, string limb, object array targets) {
   int damage = GetDamage(level);
   int num = who->GetSkillLevel("necromancy")/10;
    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
          }
   send_messages( "",
     "%^BOLD%^YELLOW%^Thunder and lightning %^WHITE%^CRACK%^YELLOW%^ across the sky!%^RESET%^",
     who, who, environment(who));
   return spell::eventCast(who, level, limb, targets);

   foreach(object target in targets) {
     if (!target) continue;
     if (who->GetFriends() == target->GetKeyName()) return 0;
     target->eventReceiveDamage(who, GetDamageType(), damage, 0, target->GetRandomLimb(target->GetTorso()) );
     if (!random(4)) {
       target->eventCollapse();
     }
   }
   return 1;
}

