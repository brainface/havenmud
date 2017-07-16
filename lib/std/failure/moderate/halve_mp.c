// Zeddicus@Haven
// 08/16/2004 02:11PM
// Cuts the caster's magic points in half

#include <lib.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  who->eventPrint("Your mental capacity is greatly reduced!");
  who->AddMagicPoints(-(who->GetMagicPoints()/2));

  return 1;
}
