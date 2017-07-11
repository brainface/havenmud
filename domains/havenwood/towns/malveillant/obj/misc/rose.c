/*  a rose 
*/

#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rose");
  SetShort("a black rose");
  SetId(  ({"rose"}) );
  SetAdjectives( ({"black"}) );
  SetLong("This black rose is the symbol of the Soirin religion. It "
     "has been blessed by Alessandra, the Princess of Darkness, and "
     "seems to draw you into it.");
  SetMass(10);
  SetMaterial("natural");
  }
