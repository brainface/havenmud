#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("fountain");
  SetShort("the Blood Fountain");
  SetLong("This used to be the blood fountain of Grymxoria. "
          "Here the sacred and pure water of the Blood "
          "River used to be piped up for all to drink but has "
	  "stopped working ages ago. ");
  SetPreventGet("You cannot take the fountain.");
 }
