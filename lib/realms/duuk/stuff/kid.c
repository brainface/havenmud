/* A kid that has a cold
 */
#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;
void MyGreet(object who);

static void create() {
  sentient::create();
  SetKeyName("elven child");
  SetShort("a sickly looking elven child");
  SetRace("elf");
  SetGender("male");
  SetInventory( ([
    STD_GERMS + "waste_sick" : 1,
    ]) );
  SetClass("merchant");
  SetLevel(1);
  SetLong("This child looks vaguely ill, as is suffering from something.");
  SetId( ({ "kid", "child", "elf" }) );
  SetAdjectives( ({ "sickly", "looking", "elven" }) );
  SetWander(1);
  SetWanderSpeed(10);
  SetGreet( (: MyGreet :) );
}

void MyGreet(object who) {
  eventForce("cough");
  new(STD_GERMS + "waste_sick")->eventInfect(who);
}