
#include <lib.h>
#include <std.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("message");
  SetId( ({"message"}));
  SetShort("a message for Sklaag the Mauler");
  SetAdjectives( ({ "for sklaag the mauler", "for Sklaag the Mauler" }) );
  SetLong("This scroll is rolled closed with a tongue "
          "securing it closed. The blood looks dried "
          "and soaked into the scroll.");
  SetMass(50);
  SetValue(0);
  SetDestroyOnSell(1);
  SetMaterial( ({"natural"}) );
  }
