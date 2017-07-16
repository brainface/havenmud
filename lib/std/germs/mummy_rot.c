/*  Mummy Rot */
#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;
int eventSuffer();

static void create() {
  germ::create();
  SetKeyName("mummy rot");
  SetShort("mummy rot");
  SetContagious(75);
  SetCureChance(15);
  SetLifeSpan(30);
  SetSuffer( (: eventSuffer :) );
}

int eventSuffer() {
  object who = environment();

  if (!who) return 0;

  switch(random(4)) {
    case 0:
      who->eventPrint("You see something moving out of the corner of your eye.");
      break;
    case 1:
      who->eventPrint("You hear dreadful moaning somewhere behind you.");
      break;
    case 2:
      who->eventPrint("Loud chanting echoes in the distance.");
      break;
    case 3:
      who->eventPrint("The air suddenly grows cold.");
      break;
  }
  who->AddCursed(random(10));
  if (!random(3)) {
    send_messages("suffer",
       "$agent_possessive_noun skin starts to wither and rot!",
       who, 0, environment(who) );
    who->eventReceiveDamage(this_object(), DISEASE, 50+random(25), 1);
    who->AddParalyzed(1+random(3));
  }
  return 1;
}

