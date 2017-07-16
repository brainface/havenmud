/*  A spell of turning Undead.
 *  Duuktsaryth 6 August 1998
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("turn undead");
  SetSpellType(SPELL_COMBAT);
  SetRules("LIV","");
  SetSkills( ([
    "faith" : 1,
    ]) );
  SetDifficulty(15);
  SetStaminaCost(10, 10);
  SetHelp(
    "This \"spell\" is actually a power granted to all clerics and priests "
    "of Kailie. It allows the caster some control over the forces of the undead "
    "by making them either flee or doing damage to them. Please remember that "
    "this is based upon the faith of the caster in relation to the power of "
    "the undead."
    );
}

varargs int CanCast(object who, int level, mixed x, object *t) {
  t = filter(t, (: $1->GetUndead() :));
  if (!sizeof(t)) {
    who->eventPrint("No undead target there!");
    return 0;
  }
  return ::CanCast(who, level, x, t);
}

varargs int eventCast(object who, int level, mixed x, object *t) {
  object target = t[0];
  int UndeadLevel = target->GetLevel();
  int faith = who->GetSkillLevel("faith");
  
  faith = random(faith);
  if (faith < UndeadLevel) {
    send_messages("are", 
         "$agent_name $agent_verb stunned by the failure of $agent_possessive turning attempt.",
         who, target, environment(who) );
    who->SetParalyzed(3);
    return 1;
    }
  if (faith >= UndeadLevel && faith < UndeadLevel * 2) {
    send_messages("are",
      "$target_name $target_verb unaffected by $agent_possessive_noun attempt to turn $target_objective.",
      who, target, environment(who) );
    return 1;
    }
  if (faith >= UndeadLevel * 2 && faith < UndeadLevel * 3) {
    send_messages("are",
      "$target_name $target_verb stunned by $agent_possessive_noun turning attempt!",
      who, target, environment(who) );
    target->SetParalyzed(2);
    return 1;
    }
  if (faith >= UndeadLevel * 3 && faith < UndeadLevel * 5) {
    send_messages("are", 
       "$target_name $target_verb frightened off by the powerful aura emitted by $agent_name!",
      who, target, environment(who) );
    target->eventWimpy();
    return 1;
    }
  if (faith >= UndeadLevel * 5 && faith < UndeadLevel * 10) {
    send_messages("are",
      "$target_name $target_verb %^YELLOW%^stricken%^RESET%^ by the power of $agent_possessive_noun faith!",
      who, target, environment(who) );
    target->eventReceiveDamage(who, MAGIC|SHOCK, faith, 1);
    target->eventWimpy();
    return 1;
    }
  if (faith >= UndeadLevel * 10) {
    send_messages("are",
      "$target_name $target_verb %^RED%^obliterated%^RESET%^ by the power of $agent_possessive_noun faith!",
      who, target, environment(who) );
    target->eventDie(who);
    return 1;
    }
}
