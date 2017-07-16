// Zeddicus@Haven
// 11/6/2005 8:22PM
// Move the caster to a random room

#include <lib.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  object *allrooms = objects( (: $1->GetClimate() && !vehiclep($1) :) );

  allrooms = filter(allrooms, (: strsrch(base_name($1), "/domains/")==0 :) );
  allrooms = filter(allrooms, (: strsrch(base_name($1), "/domains/staff/")!=0 :) );
  allrooms = filter(allrooms, (: !$1->GetProperty("ocean") :) );

  who->eventMove(allrooms[random(sizeof(allrooms))]);

  return 1;
}
