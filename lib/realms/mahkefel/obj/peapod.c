#include <lib.h>

inherit LIB_ITEM;

void eventDancePunk();

static void create() {
  item::create();
  SetKeyName("peapod");
  SetShort("an innocent peapod");
  SetId(({ "peapod","pod" }));
  SetAdjectives( ({ "innocent","pea" }) );
  SetLong(
    "It's just a peapod. It's not full of spiders instead of peas. But you're "
    "going to stare at it for hours, knowing spiders will jump out. Because "
    "that's the sort of thing that happens here. But it's not happening this "
    "time. It's just not going to happen."
  );
  
  call_out( (: eventDancePunk :), 0);
}

void eventDancePunk() {
  object *victims;

  switch(random(4)) {

  case 0:
  send_messages("wiggle",
    "The peapod doesn't wiggle from the spiders that aren't inside it moving around.", this_object(), 0, environment()
  );
  break;

  case 1:
  send_messages("",
    "The peapod starts to crack. Because it's old and dry, not because eight-legged arachnids have grown to maturity and are escaping.",
    this_object(), 0, environment()
  );
  break;

  case 2:
  send_messages("",
    "The strand like substance attached to the peapod is just normal pea-plant strands, not spiderwebbing.",
    this_object(), 0, environment()
  );
  break;

  case 3:
  send_messages("",
    "The peapod feels scratchy because it's a peapod, not because spiders are crawling out of it and onto your fingers.",
    this_object(), 0, environment()
  );
  break;

  }
  call_out( (: eventDancePunk :), 30);
}
