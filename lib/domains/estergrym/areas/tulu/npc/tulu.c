#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
inherit LIB_NPC;

int Special(object who);

static void create() {
  ::create();
  SetKeyName("tulu");
  SetShort("Tulu the Dreaming Horror");
  SetId( ({ "tulu", "horror" }) );
  SetAdjectives( ({ "dreaming" }) );
  SetRace("demon");
  SetClass("evoker");
  SetClass("rogue");
  SetSkill("faith", 1, 1);
  SetLevel(2500);
  SetSpellBook( ([
    "protection of tulu" : 100,
  ]) );
  SetFirstCommands( ({ "cast protection of tulu", "cast protection of tulu", "cast protection of tulu", "cast protection of tulu", "cast protection of tulu" }) );
  SetCombatAction(50, (: Special :) );
  SetLong(
    "Deep in the heart of Relyah, Tulu the Dreaming Horror has awoken. His massive head appears to be something akin "
    "to a squid, with tentacles rolling off it. His green ichor-laden body is a mass of vile bloat and shambling evil. "
    );
  SetGender("male");
  SetReligion("Tulu Cult");
  SetMorality(-2500);
  SetLimit(1);
}

int Special(object who) {
  int x = random(3);
  
  if (!who) return 1;
  switch(x) {
    case 0:
      send_messages( ({ "howl" }), "$agent_name $agent_verb an evil %^RED%^wail of death%^RESET%^ which stuns $target_name!",
                     this_object(), environment(), who);
      who->AddParalyzed(3);
      break;
    case 1:
      send_messages( ({ "spit" }), "$agent_name $agent_verb a %^GREEN%^vile substance%^RESET%^ at $target_name!",
                     this_object(), environment(), who);
      who->eventReceiveDamage(this_object(), ACID, 50000, 0, who->GetRandomLimb());
      break;
    case 2:
      eventForce("cast protection of tulu");
      break;
    }
  return 1;
}

int eventDie(object agent) {
  if (agent) {
    CHAT_D->eventSendChannel("Demon Slayer", "ooc", agent->GetCapName() + " has slain the Dreaming God Tulu!");
    agent->AddQuest("the Destroyer of Dreams", "Killed Tulu");
  }
  return ::eventDie(agent);
}
