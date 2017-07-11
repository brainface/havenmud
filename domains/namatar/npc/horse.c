#include <lib.h>
#include <position.h>
#include <damage_types.h>
inherit LIB_NPC;
int HoofAttack(object who);

static void create() {
  ::create();
  SetRace("horse");
  SetKeyName("namatarian wildhorse");
  SetShort("a namatarian wildhorse");
  SetId( ({ "horse", "wildhorse" }) );
  SetAdjectives( ({ "wild", "namatarian" }) );
  SetLong( "The hardy horse is dappled with spots from hindquarters "
    "to nose, making it look as though it has been spotted with gray "
    "ink. Silvery hair sprouts from mane, tail, and luxurious fetlocks "
    "around prancing, unshod hooves. The horse is quite wild and free.");
  SetGender(random(2) ? "male" : "female");
  SetClass("animal");
  SetLevel(60);
  SetAction(8, ({
    "!emote sniffs the ground looking for lunch.",
    "!emote whinnies.",
    }) );
  SetCombatAction(10, (: HoofAttack :) );
  SetWander(4);
  SetLimit(20);
}

int HoofAttack(object who) {
  who = GetCurrentEnemy();
  if (!who) return 0;
  send_messages( ({ "rear" }), "$agent_name $agent_verb back and knocks $target_name to the ground with its hooves!",
    this_object(), who, environment() );
  who->SetPosition(POSITION_LYING);
  who->AddParalyzed(2);
  who->eventReceiveDamage(this_object(), BLUNT, GetDamage(50, "melee", who->GetSkillLevel("melee defense")));
  return 1;
}
