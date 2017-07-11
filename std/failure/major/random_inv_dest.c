// Zeddicus@Haven
// 08/16/2004 12:40PM
// Randomly pick an item from the caster's inventory and destroy it.

#include <lib.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  object *inv = all_inventory(who);
  object gone = (sizeof(inv) ? inv[random(sizeof(inv))] : 0);

  if (gone)
  {
    send_messages(0, capitalize(gone->GetShort()) + " is consumed in the "
                  "failure of $agent_possessive_noun spell.",
                  who, 0, environment(who));
    gone->eventDestruct();
  }
  return 1;
}
