// Zeddicus@Haven
// 09/06/2004 04:33PM
// Makes you very hungry.

#include <lib.h>
#include <damage_types.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  who->AddFood(-(who->GetFood()));
  who->eventPrint("You become extremely hungry!");
  return 1;
}
