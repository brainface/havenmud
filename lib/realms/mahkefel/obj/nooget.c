#include <lib.h>

inherit LIB_ITEM;

void eventDancePunk();

static void create() {
  item::create();
  SetKeyName("nooget");
  SetShort("a scruffy nooget");
  SetId(({ "nooget", "noget" }));
  SetAdjectives( ({ "scruffy" }) );
  SetLong(
    "This very discomforting noget is scruffy and cold. It is made entirely "
    "of spiders and solders and scratchy peapods. There's also a little bit "
    "of fur in there, you're not sure what from. It also lacks sleeves because "
    "it's not a goddamned slanket and even nogets have standards."
  );

  call_out( (: eventDancePunk :), 0);
}

void eventDancePunk() {
  object *victims;

  switch(random(4)) {

  case 0:
  send_messages("snuggle",
    "The nooget is incredibly disconcerting in every possible way.", this_object(), 0, environment()
  );
  break;

  case 1:
  send_messages("",
    "The noget is cold and itchy. It is nothing like you remember except in the darkest nightmares.",
    this_object(), 0, environment()
  );
  break;

  case 2:
  send_messages("",
    "The nooget hugs you just a little tighter than you are comfortable with, which is any at all.",
    this_object(), 0, environment()
  );
  break;

  case 3:
  send_messages("",
    "The nooget will abandon you in your hour of need.",
    this_object(), 0, environment()
  );
  break;

  }
  call_out( (: eventDancePunk :), 30);
}

