
#include <lib.h>
#include <std.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("message");
  SetId( ({"message"}));
  SetShort("a message for Urg Unt Alla");
  SetAdjectives( ({ "for urg unt alla", "for Urg Unt Alla" }) );
  SetLong("This scroll is rolled closed with a tongue "
          "securing it closed.");
  SetMass(50);
  SetValue(0);
  SetDestroyOnSell(1);
  SetMaterial( ({"natural"}) );
  }
