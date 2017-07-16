#include <lib.h>
#include "../path.h"

inherit LIB_ITEM; 

static void create() {
  item::create();
  SetId("sign","large sign","laws","rules");
  SetShort("a large sign");
  SetLong("Some of the laws of Glimmerdin are posted here.");
  SetRead("%^YELLOW%^%^BOLD%^     -=Glimmerdin Code of Laws=-%^RESET%^\n\n"
          "%^RED%^%^BOLD%^"
          "1. Violence against citizens of Glimmerdin is prohibited.\n"
          "2. Theft from individuals, businesses or the state is\n"
          "   prohibited.\n"
          "3. Vandalism of property within Glimmerdin is prohibited.\n"
          "\n%^BOLD%^%^GREEN%^"
          "Violation of the above mentioned laws may result in discipline.%^RESET%^");
  SetPreventGet("You cannot carry that!");
}
