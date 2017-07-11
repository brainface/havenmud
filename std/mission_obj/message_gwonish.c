
#include <lib.h>
#include <std.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("message");
  SetId( ({"message"}));
  SetShort("a message for Sslan Sslar");
  SetAdjectives( ({ "for sslan sslar", "for Sslan Sslar" }) );
  SetLong("This scroll is rolled closed with a tongue "
          "securing it closed. The blood looks fresh. ");
  SetMass(50);
  SetValue(0);
  SetDestroyOnSell(1);
  SetMaterial( ({"natural"}) );
  }
