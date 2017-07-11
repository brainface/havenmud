#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("tent");
   SetShort("a grey-brown mess");
   SetId( ({ "tent","mess" }) );
   SetAdjectives( ({ "grey","brown","grey-brown","made" }) );
   SetLong("The grey-brown mess is a collapsed tent.");
   SetPreventGet("The tent is too large and unwieldly for such an "
                 "action.");
}
