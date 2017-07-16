//
// Sanctify Spell
// Coded by Dunedain@Haven
// 14 September 1997
//

#include <lib.h>
#include <magic.h>
#include <message_class.h>

inherit LIB_SPELL;

int SanctifyRoom(object who);
int EndSanctify(object env, mapping savedproperties);

void create()
{
  ::create();
  SetSpell("sanctify");
  SetRules("");
  SetSkills( ([
    "faith" : 30,
    "enchantment" : 30,
  ]) );
  SetDifficulty(30);
  SetRequiredMagic(70);
  SetRequiredStamina(50);
  SetMagicCost(60,20);
  SetStaminaCost(40,20);
  SetSpellType(SPELL_OTHER);
  SetHelp(
          "Protects the area that the caster is in from attack of any "
          "kind for a certain time period.  All fighting present at the "
          "time of casting will be stopped as well.  The length of the "
          "sanctification depends on the skill of the caster.");
}

varargs int eventCast(object who, int level, string limb, object *targets) {
  call_out((:SanctifyRoom:),random(3)+2,who);
}

int SanctifyRoom(object who) {
  int timelength;
  mapping savedproperties = ([]);
  if (!who) return 1;
  if (!environment(who)) return 1;
  if (environment(who)->GetProperty("sanctified") == 0)
  {
    timelength = (random(15) + (who->GetSkillLevel("faith")
                                    + who->GetSkillLevel("enchantment") ) / 2 );
    send_messages(({"summon"}), "%^BOLD%^%^CYAN%^As $agent_name $agent_verb "
                    "energies from $agent_possessive god, all aggression in "
                    "the area is put to an end.%^RESET%^", who, 0,
                    environment(who));
    if (environment(who)->GetProperty("no attack")) savedproperties[0] = 1;
    if (environment(who)->GetProperty("no bump")) savedproperties[1] = 1;
    if (environment(who)->GetProperty("no steal")) savedproperties[2] = 1;
    if (environment(who)->GetProperty("no magic")) savedproperties[3] = 1;
    if (environment(who)->GetProperty("no teleport")) savedproperties[4] = 1;

    environment(who)->SetProperty("no attack",1);
    environment(who)->SetProperty("no bump",1);
    environment(who)->SetProperty("no steal",1);
    environment(who)->SetProperty("no magic",1);
    environment(who)->SetProperty("no teleport",1);
    environment(who)->SetProperty("sanctified",1);
    call_out((:EndSanctify:), timelength, environment(who), savedproperties);
    return 1;
  }
  else
  {
    if (who)
    send_messages(({""}), "This room has already been sanctified.", who, 0, who);
    return 0;
  }
}

int EndSanctify(object env, mapping savedproperties) {
  if (!env) return;
  send_messages(({""}), "%^CYAN%^The protective aura around the room fades "
                        "away.%^RESET%^", env, 0);
  if (!savedproperties[0])
    env->SetProperty("no attack",0);
  if (!savedproperties[1])
    env->SetProperty("no bump",0);
  if (!savedproperties[2])
    env->SetProperty("no steal",0);
  if (!savedproperties[3])
    env->SetProperty("no magic",0);
  if (!savedproperties[4])
    env->SetProperty("no teleport",0);
  env->SetProperty("sanctified",0);
  return 1;
}

