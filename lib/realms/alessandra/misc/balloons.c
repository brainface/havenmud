//Balloons!!!

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();

  SetKeyName( "balloon" );
  SetId(({ "balloon", "balloons"}));
  SetShort( "a %^RED%^bunch%^YELLOW%^ of %^BOLD%^%^MAGENTA%^colorful %^CYAN%^balloons%^RESET%^");
  SetAdjectives( ({ "bunch", "colorful", "birthday", "deflated" }) );
  SetLong(
     "This is a bunch of colorful birthday... well a bunch of "
     "balloons at any rate. Awesome, right? They are a little "
     "deflated and none of them actually say 'Happy Birthday' but "
     "one has a unicorn on it, so that counts for something?" 
     );
  SetVendorType(VT_TREASURE);
  SetProperty("history", "Aless got them on sale. You'll love them, or else.");
}
