#include <lib.h>    
inherit LIB_ITEM;                                  

static void create() {
  ::create();
  SetKeyName("cookie");
  SetShort("a decorative cookie");
  SetId( ({ "cookie" }) );
  SetAdjectives( ({ "decorative" }) );
  SetLong("Made of ceramic and artlessly painted to look like an oatmeal cookie, this kitschy thing can't even be eaten.");
  SetMass(100);
  SetValue(10);
}
