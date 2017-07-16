#include <lib.h>

inherit LIB_ITEM;

void eventDancePunk();

static void create() {
  item::create();
  SetKeyName("wooget");
  SetShort("a fluffy wooget");
  SetId(({ "wooget", "woget" }));
  SetAdjectives( ({ "fluffy" }) );
  SetLong(
    "This wooget is comforting and fluffy and woaaarm. There are no hidden "
    "spiders or solders or peapods, it's just a bunch of fur and wool and "
    "blankety stuff. It also does not have sleeves because it is not a "
    "slanket because we have goddamned standards here."
  );

  call_out( (: eventDancePunk :), 0);
}

void eventDancePunk() {
  object *victims;

  switch(random(4)) {

  case 0:
  send_messages("snuggle",
    "The wooget is all snuggly.", this_object(), 0, environment()
  );
  break;

  case 1:
  send_messages("",
    "The wooget is superwarm, just how you remember woogets being! Exactly as you remember.",
    this_object(), 0, environment()
  );
  break;

  case 2:
  send_messages("",
    "The wooget hugs you back just a little bit, because this is imagination land and that can happen.",
    this_object(), 0, environment()
  );
  break;

  case 3:
  send_messages("",
    "The wooget is prepared to accompany you through whatever adventures you may take a wooget on, like getting beer out of the freezer. It's not going to war with you or nothing, it's just a wooget.",
    this_object(), 0, environment()
  );
  break;

  }
  call_out( (: eventDancePunk :), 30);
}

