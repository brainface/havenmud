//Balloons!!!

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();

  SetKeyName( "balloon" );
  SetId(({ "balloon", "balloons"}));
  SetShort( "a %^RED%^bunch%^YELLOW%^ of %^BOLD%^%^MAGENTA%^colorful %^CYAN%^balloons%^RESET%^ inflated with spiders..");
  SetAdjectives( ({ "bunch", "colorful", "birthday", "inflated" }) );
  SetLong(
     "This is a bunch of colorful birthday... well a bunch of "
     "balloons at any rate. Also, they're inflated by spiders, "
     "because someone was literally goddamned insane. Spiders "
     "are heavier than air, you may remember, so they're just "
     "dragging along the ground like sad beachballs made of "
     "horror. That ballons may or may not have images on them, "
     "you don't know, because oh fuck, the writhing."
     );
  SetVendorType(VT_TREASURE);
  SetProperty("history", "You don't want to know.");
}

