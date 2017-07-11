// Proximo@Via Imperialis
// 05/30/2003 2:02:25 AM

#include <lib.h>
#include "../sulumus.h"

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("notice");
  SetMaterial( ({ "wood" }) );
  SetPreventGet("The sign is deeply rooted in the ground.");
  SetId( ({ "sign", "rules" }) );
  SetAdjectives( ({ "a", "of", "rules" }) );
  SetShort("a sign of rules");
  SetLong(
     "This sign lists the basic rules that all must follow within the limits of "
     "this trading post. One can read it. "
  );
  SetRead(
     "\nTo all who enter the limits of the Sulumus Trading Post: \n"
     "\n%^CYAN%^BOLD%^1) %^RESET%^Maintain lawful and orderly conduct. Those who "
     "in any way break or abuse the law shall be punished severely. \n\n"
     "%^CYAN%^BOLD%^2) %^RESET%^Do not attempt to steal, swindle, or in any way "
     "rob or harass the merchants you have come to do trade with. \n\n"
     "%^CYAN%^BOLD%^3) %^RESET%^Obey or be punished. \n\n"
     " - Thank you for your business - "
  );
}
