// enchantment summon

#include <lib.h>
#include <damage_types.h>
 inherit LIB_NPC;

static void create(){
  npc::create();
  SetShort("a rag dag");
  SetLong(
    "This clearly unnatural hound gazes eagerly up at all onlookers "
    "with two dubiously functional button eyes. Its skin is a patchwork and "
    "motley collection of old shirts, discarded trousers and the lost half of "
    "pairs of socks. A bit of drool dangling from its chin seems to be nothing "
    "but dry cotton."
  );
  SetKeyName("rag dag");
  SetAdjectives( ({"rag"}) );
  SetId(({"dag"}));
  SetRace("dog");
  SetClass("animal");
  SetLevel(2);
  SetGender("neuter");
  SetMeleeDamageType(PIERCE);
  SetMeleeAttackString("needly teeth");

  SetAction(5, ({
    "!emote barks loudly and persistently, sounding inconveniently like an entire drumline.",
    "!emote sneezes, sending cotton everywhere.",
    "!emote chases its tail in a whirlwind of fabric.",
    "!emote slams into you with all the speed and force of a slow "
      "moving pillow.",
  }) );
  
  SetNoCorpse(1);
}

int eventDie(object killer) {
  object scrap;
  object room;
  if (room = environment((this_object()))) { 
    send_messages("unravel" , 
      "$agent_name $agent_verb into a ragged piece of cloth.",
      this_object(), this_object(), room);
    scrap = new("/std/crafting/survival/scrap_textile");
    scrap->eventMove(room);
  }
  return (npc::eventDie(killer));
}
