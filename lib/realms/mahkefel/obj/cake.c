#include <lib.h>    
inherit LIB_ITEM;                                  

void eventDancePunk();

static void create() {
  ::create();
  SetKeyName("cake");
  SetShort("a plastic birthday cake");
  SetId( ({ "cake" }) );
  SetAdjectives( ({ "plastic", "birthday" }) );
  SetLong("Made of chinese plastic, this novelty birthday cake "
    "is no replacement for the actual thing. Occasionaly, lights "
    "flash on the misaligned led candles atop the cake, and a tinny "
    "speaker hums incomplete verses of the happy birthday song.");
  SetMass(100);
  SetValue(10);

  call_out( (: eventDancePunk :), 0);
}

void eventDancePunk() {
  object *victims;  

  switch(random(5)) {
  
  case 0:
  send_messages("hum",
    "Static erupts from the cake.", this_object(), 0, environment()
  );
  break;

  case 1:
  send_messages("",
    "Discordant music slooowwwwwly rings from the cake.",
    this_object(), 0, environment()
  );
  break;

  case 2:
  send_messages("",
    "Lights blink on and off across the cake.",
    this_object(), 0, environment()
  );
  break;

  case 3:
  send_messages("",
    "A candle atop the cake pops violently as acrid smoke fills the room.",
    this_object(), 0, environment()
  );
  break;

  case 4:
  send_messages("",
    "The cake sings, %^CYAN%^'Sheng ri Kuai le!'%^RESET%^",
    this_object(), 0, environment()
  );
  break;
  }

  call_out( (: eventDancePunk :), 30);
}

