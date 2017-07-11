/* A kid that has a cold
 */
#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("elven child");
  SetShort("a small elven child");
  SetRace("elf");
  SetGender("male");
  SetLimit(2);
  SetInventory( ([
    ]) );
  SetClass("merchant");
  SetLevel(1);
  SetMorality(500);
  SetLong("This is a small elven citizen of Haven Town.");
  SetId( ({ "kid", "child", "elf", "haven_wander" }) );
  SetAdjectives( ({ "small", "elven" }) );
  SetWanderSpeed(10);
}
