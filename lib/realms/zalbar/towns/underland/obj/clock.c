#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetShort("a huge transparent clock");
  SetKeyName("clock");
  SetId( ({ "clock" }) );
  SetAdjectives( ({ "huge", "transparent" }) );
  SetLong("This huge clock is made of large brass gears and springs. The center "
          "cutouts of each gear has been painstakingly adorned in stained glass "
          "which makes each revolution of the gear look like a hurricane of "
          "colours. The face of the clock is marked with large gems at each hour, "
          "and decorated with intricate scroll work that looks like puffs of steam. "
          "You can <read clock> to get the time.");
  SetPreventGet("The clock is integral to the front of the hall.");
  SetInvis(1);
  SetRead("default", "It reads, \"" + mtime(time()) + "\"");
}
