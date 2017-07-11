#include <lib.h>
inherit LIB_BOARD;
 
static void create() {
   bboard::create();
   SetKeyName("book");
   SetShort("a guest book");
   SetId( ({ "board","book","guestbook" }) );
   SetAdjectives( ({ "guest","old" }) );
   SetLong("The pages of the guest book are worn and have obviously "
           "been written on before, but most of the earlier pages "
           "have been ripped out.");
   SetPreventGet(1);
   set_board_id("amelia_hiker_guest_book");
}
