//Illura@Haven
//August 2009
#include <lib.h>
#include <magic.h>
#include <message_class.h>

inherit LIB_SPELL;

int SanctifyRoom(object who);
int EndSanctify(object env, mapping savedproperties);

void create()
{
  ::create();
  SetSpell("seduce");
  SetRules("");
  SetSkills( ([
    "faith" : 100,
  ]) );
  SetDifficulty(100);
  SetRequiredMagic(100);
  SetMagicCost(90,20);
  SetSpellType(SPELL_OTHER);
  SetReligions("Soirin");
  SetHelp(
          "This spell harnesses the power of the Princess of Darkness "
          "to make the caster irresistibly enticing to any enemies "
          "around them for a short time, interrupting their spells and "
          "attacks. The artifice of seduction lasts for varying times, "
          "depending on the skill of the caster.");
}

varargs int eventCast(object who, int level, string limb, object *targets) {
  call_out((:SanctifyRoom:),random(3)+2,who);
}

int SanctifyRoom(object who) {
  int timelength;
  mapping savedproperties = ([]);
  if (environment(who)->GetProperty("sanctified") == 0)
  {
    timelength = (random(20) + (who->GetSkillLevel("faith")) / 2
);
    send_messages(({"summon"}), "%^BOLD%^%^MAGENTA%^As $agent_name $agent_verb "
                    "scintillating powers of Alessandra, all attackers "
                    "are charmed and amazed.%^RESET%^", who, 0,
                    environment(who));
    if (environment(who)->GetProperty("no attack")) savedproperties[0] = 1;
    if (environment(who)->GetProperty("no bump")) savedproperties[1] = 1;
    if (environment(who)->GetProperty("no magic")) savedproperties[2] = 1;
    if (environment(who)->GetProperty("no teleport")) savedproperties[3] = 1;

    environment(who)->SetProperty("no attack",1);
    environment(who)->SetProperty("no bump",1);
    environment(who)->SetProperty("no magic",1);
    environment(who)->SetProperty("no teleport",1);
    environment(who)->SetProperty("sanctified",1);
    call_out((:EndSanctify:), timelength, environment(who), savedproperties);
    return 1;

}
  else
  {
    if (who)
    send_messages(({""}), "Everyone here is already charmed by you.", who, 0,
who);
    return 0;
  }
}

int EndSanctify(object env, mapping savedproperties) {
  if (!env) return;
  send_messages(({""}), "%^MAGENTA%^Erotic whispers fill your head as the dark "
                        "arts of seduction leave you.%^RESET%^", env, 0);
  if (!savedproperties[0])
    env->SetProperty("no attack",0);
  if (!savedproperties[1])
    env->SetProperty("no bump",0);
  if (!savedproperties[2])
    env->SetProperty("no magic",0);
  if (!savedproperties[3])
    env->SetProperty("no teleport",0);
  env->SetProperty("sanctified",0);
  return 1;
}

