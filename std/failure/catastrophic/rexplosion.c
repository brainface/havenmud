// Thoin@Haven
// 02/20/06
// room explosion failure

#include <lib.h>
#include <daemons.h>
#include <damage_types.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  object *hurt = filter(all_inventory(environment(who)), (: living :) );
  int amount = 0;
  
  hurt = filter(hurt, (: noncreatorp :) );

  foreach(string skill in spell->GetSkills())
  {
    amount += who->GetSkillLevel(skill);
  }
    amount = amount*20;
    send_messages(0, "$agent_possessive_noun spell fails causing an "
                     "%^RED%^explosion%^RESET%^ of magical energies to rip "
                     "through the room injuring "
                     +conjunction(hurt->GetName())+" before it fades.",who,hurt,
                  environment(who));

  hurt->eventReceiveDamage(this_player(), HEAT, amount, 0);
  if (playerp(who)) CHAT_D->eventSendChannel("FAILURE!", "reports", who->GetCapName() +
        " got the Room Explosion failure!");
  return 1;
}
