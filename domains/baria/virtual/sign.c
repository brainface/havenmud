/*  A sign */
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sign");
  SetPreventGet("You cannot take that.");
  SetLong("This is a road sign with words on it.");
  SetShort("a small sign");
  SetId( ({ "sign" }) );
  SetAdjectives( ({ "small" }) );
  SetRead("default", "The Barian Jungle.  \n \n  Beware!");
  }
