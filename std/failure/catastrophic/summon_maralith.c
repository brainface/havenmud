// Zeddicus@Haven
// 09/02/2004 02:35PM
// Summon a totally BS maralith that will attack everything in the room and
// disperse after a short while.
// Added in a channel report so we could all taunt people. 
// Duuk

#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
#include <std.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  object demon = new(STD_NPC "failure_maralith");

  if (present("spell_failure_maralith", environment(who))) return 1;

  demon->SetLifeSpan(5 + (who->GetLevel()/10));
  demon->SetLevel(who->GetLevel());
  demon->eventMove(environment(who));
  demon->eventForce("growl");
  demon->eventForce("attack all");
  demon->SetAttack(who);

  if (playerp(who)) CHAT_D->eventSendChannel("Maralith!", "reports", who->GetCapName() +
        " got the Maralith failure!");
  message("", "%^BOLD%^RED%^A demon appears from the ether!%^RESET%^",
          environment(who), 0);
  return 1;
}
