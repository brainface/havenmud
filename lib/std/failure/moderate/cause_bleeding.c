// Zeddicus@Haven
// 08/16/2004 01:28PM
// Causes the caster to bleed

#include <lib.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  int power = 5 + (who->GetSpellBook()[spell->GetSpell()] / 2);

  if (who->GetBleeding())
  {
    send_messages(0, "The failure of $agent_possessive_noun spell worsens "
                     "$agent_possessive bleeding!",
                     who, 0, environment(who));
  }
  else
  {
    send_messages(0, "The failure of $agent_possessive_noun spell causes "
                     "$agent_objective to %^RED%^bleed%^RESET%^!",
                     who, 0, environment(who));
  }

  who->AddBleeding(power);
  return 1;
}
