
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();

  SetKeyName( "card" );
  SetId(({ "card"}));
  SetShort( "a Vampony Fan Club Membership Card" );
  SetAdjectives( ({ "club", "fan", "membership" }) );
  SetLong(
     "This small piece of laminated paper proves the named to be "
     "a member of the Vampony Vampire Pony Fan Club. And likely "
     "a closet twilight fan as well. It is an extremely prestigious "
     "club, or at least claimed to be, by its members."
     );
  SetVendorType(VT_TREASURE);
  SetProperty("history", "Alessandra bought her very own laminating "
     "machine just so that she could make this to carry in her Hello "
     "Kitty wallet, along with a picture William Shatner. But this "
     "is probably far too much information.");
  SetRead("default",
     "  VAMPONY Vampire Pony Fan Club  \n"
     "  -----------------------------  \n"    
     "    This card certifies that:    \n\n"
     "           ALESSANDRA            \n\n"
     "  Is the PRESIDENT and founding  \n"
     "          member of the          \n"
     "  VAMPONY Vampire Pony Fan Club  \n"
     );
}
