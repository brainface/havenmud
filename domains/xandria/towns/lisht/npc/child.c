//Selket@Haven
//2006
#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("small child");
  SetShort("a small gnollish child");
  SetRace("gnoll");

  SetBaseLanguage("Rehshai");

  SetGender("male");
  SetClass("merchant");
  SetLevel(1);
  SetLong("This is a small child of Lisht.");
  SetId( ({ "kid", "child", "gnoll" }) );
  SetAdjectives( ({ "small", "gnollish" }) );
  SetWanderSpeed(5);
  SetLimit(4);
  }
