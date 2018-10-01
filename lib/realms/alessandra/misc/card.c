#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();

  SetKeyName( "card" );
  SetId(({ "card"}));
  SetShort( "a teddy bear card" );
  SetAdjectives( ({ "thank", "you", "teddy", "bear" }) );
  SetLong(
     "This small card has a picture of a teddy bear holding an "
     "american flag. Awwwww.. it's adorbs. You can probs read it. "
     "If you aren't southern drunk on ancient age."
     );
  SetVendorType(VT_TREASURE);
  SetProperty("history", "Alli could not find the keys to her car and "
     "so made use of a special HoA 'go to hell Allison Davies' card "
     "instead of buying a legit thank you card.");
  SetRead("default",
     "  Allison,  \n"
     "  We have had many complaints of   \n"    
     "  mosquito swarms coming from      \n"
     "  your back patio...               \n\n"
     "  Mike,  \n"
     "  These are not the mosquitoes     \n"
     "  you are looking for..            \n"
     "  *waves hand*                     \n"
     "  And.. thank you for your         \n"
     "  torturous.. I mean generous      \n"
     "  gift. You're kind of a weirdo    \n"
     "  and a jerkface but you're my     \n"
     "  friend whether you like it or    \n"
     "  not.. probs.                     \n"
     "                 -Alli             \n"
     );
}
