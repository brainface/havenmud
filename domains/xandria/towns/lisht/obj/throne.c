#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("throne");
  SetShort("a large gilded throne");
  SetId(  ({ "throne" }) );
  SetAdjectives( ({ "large", "gilded", "impressive", "imposing" }) );
  SetLong(
     "This imposing gilded throne is an impressive piece of craftmanship. Hard "
     "lines and corners make it almost harsh looking, but the soft velvet cushion "
     "on its seat and the intricate paintings over the golden inlay make it regal. "
     );
  SetPreventGet("Are you insane? This throne belongs to the Pharoah.");

} 
