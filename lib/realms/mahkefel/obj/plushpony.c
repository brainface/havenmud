#include <lib.h>
inherit LIB_ITEM;

void eventDancePunk();

static void create() {
  ::create();
  SetKeyName("stuffed vampony");
  SetShort("an adorable stuffed vampony");
  SetId( ({ "vampony" }) );
  SetAdjectives( ({ "adorable", "stuffed" }) );
  SetLong("This adorable plush vampire pony is stuffed with snuggly "
    "cotton. His mouth is open in a wide grin and cloth fangs dangle in "
    "odd directions. A small compartment between his plastic wings "
    "holds batteries.");
  SetMass(100);
  SetValue(10);

  call_out( (: eventDancePunk :), 0);
}

void eventDancePunk() {
  object *victims;

  switch(random(7)) {

  case 0:
  send_messages("hum",
    "Vampony's plastic wings frantically flap.",
    this_object(), 0, environment()
  );
  break;

  case 1:
  send_messages("",
    "Vampony ineffectively tries to bite you with his adorable stuffed teeth.",
    this_object(), 0, environment()
  );
  break;

  case 2:
  send_messages("",
    "Vampony snuggles with you. Dawwww.",
    this_object(), 0, environment()
  );
  break;

  case 3:
  send_messages("",
    "Vampony's eyes blink an LED red.",
    this_object(), 0, environment()
  );
  break;

  case 4:
  send_messages("",
    "Vampony sings, %^CYAN%^'Remember kids! Fairies sparkle, vampires loom!'%^RESET%^",
    this_object(), 0, environment()
  );
  break;
  
  case 5:
  send_messages("",
    "Vampony's legs twitch in unconvincing walking motions while galloping noises echo from his tinny speakers.%^",
    this_object(), 0, environment()
  );
  break;
  
  case 6:
  send_messages("",
    "Vampony sings, %^CYAN%^'Spirits in the night! All night!'%^RESET%^",
    this_object(), 0, environment()
  );
  break;
  
  case 7:
  send_messages("",
    "Vampony sings, %^CYAN%^'One, one bale of hay, ahahahaha.'%^RESET%^",
    this_object(), 0, environment()
  );
   
  break;
  }

  call_out( (: eventDancePunk :), 30);
}

