/*  A sign */
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sign");
  SetPreventGet("You cannot take that.");
  SetMaterials( ({ "wood" }) );
  SetLong("This is a road sign with words on it.");
  SetShort("a small road sign");
  SetId( ({ "sign" }) );
  SetAdjectives( ({ "small" }) );
  SetRead("default",
    "      %^CYAN%^BOLD%^KAILIE ROAD DIRECTORY%^RESET%^\n\n"
       "%^RED%^BOLD%^Durgoroth 18 miles \"northwest\"%^RESET%^\n"
    "%^YELLOW%^BOLD%^Arcanith  15 miles \"north\"%^RESET%^\n"
    "%^GREEN%^BOLD%^Baria, Jidoor lie far \"south\"%^RESET%^\n"
  );
}

