#include <lib.h>

inherit LIB_ITEM;

void eventDancePunk();

static void create() {
  item::create();
  SetKeyName( "balloon" );
  SetId(({ "balloon", "balloons"}));
  SetShort( "a %^RED%^bunch%^YELLOW%^ of %^BOLD%^%^MAGENTA%^colorful%^CYAN%^ balloons%^RESET%^ inflated with KITTENS");
  SetAdjectives( ({ "bunch", "colorful", "birthday", "inflated" }) );
  SetLong(
    "One fine day, someone looked at a bunch of colorful birthday "
    "balloons, and said 'This just isn't festive ENOUGH!' And because "
    "they were literally criminally insane, they took those balloons "
    "and stuffed them with loveable and adorable stray kittens. "
    "There's... probably some water and food in there? Because "
    "they're clearly still alive and terrible confused. "
  );
  //SetVendorType(VT_TREASURE);
  SetProperty("history", "You don't want to know.");
  call_out( (: eventDancePunk :), 0);
}

void eventDancePunk() {
  object *victims;

  switch(random(4)) {

  case 0:
  send_messages("pop",
    "Several pairs of cat ears pop out curiously and simultaneously from the balloons.",
    this_object(), 0, environment()
  );
  break;

  case 1:
  send_messages("",
    "A multitude of confused meows errupt in a disharmonic chorus from the pile of balloons.",
    this_object(), 0, environment()
  );
  break;

  case 2:
  send_messages("",
    "A fight breaks out and shreds of balloon go everywhere!",
    this_object(), 0, environment()
  );
  break;

  case 3:
  send_messages("",
    "A tiny kitten erupts from a balloon in a tiny tornado of claws, then scampers off to safety, stumbling adorably once.",
    this_object(), 0, environment()
  );
  break;

  }
  call_out( (: eventDancePunk :), 30);
}


