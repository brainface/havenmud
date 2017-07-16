#include <lib.h>
#include <size.h>
#include <domains.h>
#include <damage_types.h>
inherit LIB_NPC;
int WormCrush(object who);

static void create() {
  ::create();
  SetKeyName("sand worm");
  SetRace("worm");
  SetSize(SIZE_GIANT);
  SetClass("animal");
  SetLevel(500);
  SetWander(1);
  SetLimit(5);
  SetShort("a giant sand worm");
  SetId( ({ "worm" }) );
  SetAdjectives( ({ "giant", "sand", }) );
  SetLong(
    "This massive worm is one of the legendary Xandrian giant sand worms. "
    "Over 300 feet long and 50 feet wide, this worm has a strange cinammon odor "
    "which clings to it as it moves across the sands of Xandria."
    );
  SetCorpseItems( ([
    XANDRIA_VIRTUAL "desert/spice" : random(6) + 1,
    ]) );
  SetEncounter(1000);
  SetCombatAction(15, (: WormCrush :) );
}

int WormCrush(object who) {
  if (!present(who, environment())) return -1;
  send_messages( ({ "twist", "roll" }), "$agent_name%^RED%^ $agent_verb and $agent_verb%^RESET%^ in an effort to crush $target_name!",
                 this_object(), who, environment() );
  if (random(GetSkillLevel("melee combat")) > random(who->GetSkillLevel("melee combat") + who->GetSkillLevel("dodge"))) {
    send_messages( ({ "are" }), "$agent_name $agent_verb %^RED%^crushed%^RESET%^ beneath the sand worm!", 
       who, 0, environment());
    who->eventReceiveDamage(this_object(), BLUNT, 50000, 0, who->GetLimbs());
    return 1;
  } else {
    send_messages( ({ "dodge" }), "$agent_name $agent_verb out of the way of the worm.",
      who, 0, environment() );
    return 1;
  }
  return -1;
}

int eventDie(object agent) {
  if (agent) agent->AddQuest("the Worm Slayer", "Xandrian Worm");
  return ::eventDie(agent);
}