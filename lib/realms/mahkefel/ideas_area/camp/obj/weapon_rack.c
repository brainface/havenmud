#include <lib.h>
#include "../camp.h"

inherit LIB_ITEM;

static void create() {
    ::create();

    //descriptions
    SetKeyName("weapons rack");
    SetId( ({ "rack" }) );
    SetShort("a weapons rack");
    SetLong(
      "Will eventually hold spears."
    );
}

