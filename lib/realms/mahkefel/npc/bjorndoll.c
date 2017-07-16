#include <lib.h>
inherit LIB_ITEM;

void eventDancePunk();

static void create() {
  ::create();
  SetKeyName("stuffed bjorn");
  SetShort("an adorable stuffed bjorn");
  SetId( ({ "bjorn" }) );
  SetAdjectives( ({ "adorable", "stuffed" }) );
  SetLong("This adorable plush bjorn is stuffed with what you are fairly "
    "certain is a thin layer of cotton hiding smuggled cannabis. His mouth "
    "hangs open muppetlike and happy, but something about the creepy stare in "
    "his eyes makes him look waaaay too much like Chucky. Fortunately, he has "
    "no butcher knife. Yet.");
  SetMass(100);
  SetValue(100000);

  call_out( (: eventDancePunk :), 0);
}

void eventDancePunk() {
  object *victims;

  switch(random(6)) {

  case 0:
  send_messages("hum",
    "Plush Bjorn laughs mockingly at you.",
    this_object(), 0, environment()
  );
  break;

  case 1:
  send_messages("",
    "Plush Bjorn exhales a narcotic cloud.",
    this_object(), 0, environment()
  );
  break;

  case 2:
  send_messages("",
    "Plush Bjorn says, %^CYAN%^'I have important things to say!.'%^RESET%^",
    this_object(), 0, environment()
  );
  break;

  case 3:
  send_messages("",
    "Plush Bjorn farts realistically, because there is no god, or because He has abandoned you.",
    this_object(), 0, environment()
  );
  break;

  case 4:
  send_messages("",
    "Plush Bjorn says, %^CYAN%^'Sometimes I make poopies.'%^RESET%^",
    this_object(), 0, environment()
  );
  break;

  case 5:
  send_messages("",
    "Plush Bjorn chews mechanically on a piece of plastic bacon.%^",
    this_object(), 0, environment()
  );
  break;

  }

  call_out( (: eventDancePunk :), 30);
}

