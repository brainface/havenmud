#include <lib.h>

inherit LIB_ITEM;

void eventDancePunk();

static void create() {
  item::create();
  SetKeyName( "package" );
  SetId(({ "package"}));
  SetShort( "a fed-ex package");
  SetAdjectives( ({ "fed-ex" }) );
  SetLong(
    "A roughly brick sized fed-ex package. (It weight much less than a brick.) "
    "Someone has sharpied a cartoon butterfly with smiling face on it, along "
    "with the note 'Just a little something to make your day more colorful!' "
    "The packing tape has failed on one end, and it looks like something is "
    "trying to crawl out."
  );
  //SetVendorType(VT_TREASURE);
  SetProperty("history", "Yeah you can totally buy these things.");
  call_out( (: eventDancePunk :), 0);
}

void eventDancePunk() {
  object *victims;
  if(environment()->GetKeyName()!="alessandra") return;
  
  switch(random(4)) {

  case 0:
  send_messages("pop",
    "A butterfly crawls out the box and /almost/ makes it the air, but isn't "
    "quite fast enough.",
    this_object(), 0, environment()
  );
  break;

  case 1:
  send_messages("",
    "One of the butterflies just tried to hide somewhere that looked "
    "safe and was actually your mouth. Tastes delicious, though.",
    this_object(), 0, environment()
  );
  break;

  case 2:
  send_messages("",
    "Butterflies working together in a coordinated escape erupt from the box "
    "in all directions! It's almost successful, but a single boot covers "
    "multiple butterflies, and you have two of those.",
    this_object(), 0, environment()
  );
  break;

  case 3:
  send_messages("",
    "A single butterfly tries to drag the box away from you, beautiful wings "
    "flapping futiley for a few heartbeats until you put a stop to it.",
    this_object(), 0, environment()
  );
  break;

  }
  call_out( (: eventDancePunk :), 30);
}

