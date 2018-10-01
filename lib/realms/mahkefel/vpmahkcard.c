
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();

  SetKeyName( "card" );
  SetId(({ "card"}));
  SetShort( "a %^BOLD%^%^MAGENTA%^Vampony%^CYAN%^ Fan %^YELLOW%^Club %^RED%^Membership %^BLUE%^Card%^RESET%^");
  SetAdjectives( ({ "club", "fan", "membership" }) );
  SetLong(
     "This small piece of laminated paper proves the named to be "
     "a member of the Vampony Vampire Pony Fan Club. And likely "
     "a closet twilight fan as well. It is an extremely prestigious "
     "club, or at least claimed to be, by its members."
     );
  SetVendorType(VT_TREASURE);
  SetProperty("history", "Alessandra bought her very own laminating "
     "machine just so that she could make this to give to Mahkefel. "
     "She suspects he will keep it in his vinyl Pokeman wallet that he "
     "thinks no one knows about, along with his picture of Slush twerking, "
     "but everyone really knows already. So.. the jig is up? ");
  SetRead("default",
     "  %^BOLD%^%^MAGENTA%^VAMPONY%^CYAN%^ Vampire %^YELLOW%^Pony %^RED%^Fan %^BLUE%^Club%^RESET%^  \n"
     "  -----------------------------  \n"    
     "    This card certifies that:    \n\n"
     "            MAHKEFEL            \n\n"
     " Is the CREATOR and honorary VIP  \n"
     "          member of the          \n"
     "  %^BOLD%^%^MAGENTA%^VAMPONY%^CYAN%^ Vampire %^YELLOW%^Pony %^RED%^Fan %^BLUE%^Club%^RESET%^  \n"
     );
}
