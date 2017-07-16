#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sign");
  SetId("sign", "wooden sign");
  SetShort("a wooden sign");
  SetAdjectives( ({ "wooden","large"} ));
  SetLong("A large wooden sign has carefully carved lettering on it. \n");
  SetRead("All letters are hand-delivered to their recipient, \n"
          "if they are to be found in the Averath area. ");
  SetPreventGet("The wooden sign is nailed securely to the wall.");

}  
