// Thoin@Haven
// Makes you very thirsty.

#include <lib.h>
#include <damage_types.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  who->AddDrink(-(who->GetDrink()));
  who->eventPrint("You become extremely thirsty!");
  return 1;
}
