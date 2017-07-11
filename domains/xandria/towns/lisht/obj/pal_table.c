#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("table");
  SetShort("a massive stone table");
  SetId(  ({ "table" }) );
  SetAdjectives( ({ "massive", "stone" }) );
  SetLong(
     "This massive stone table sits in the center of the room with many "
     "parchments and papers scattered about it. The stone is rough-hewn "
     "around the edges and smooth across its surface."
     );
  SetPreventGet("Obviously you over estimate your own strength.");

} 
