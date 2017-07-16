/* road sign to bay
   Kyla 10-16-97
*/

#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("road sign");
  SetId( ({ "sign" }) );
  SetAdjectives( ({ "road", "small" }) );
  SetShort( "a small road sign" );
  SetLong( "A small road sign with words on it.");
  SetRead("default", "Platypus Bay -- South");
  SetPreventGet("You can't take the sign.");
    }
