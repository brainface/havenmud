// enchantment summon

#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
inherit LIB_MOUNT;

static void create(){
  npc::create();
  SetShort("a steel steer");
  SetLong(
    "An elegant, hollow and most importantly animate steel sculpture forms "
    "the outline of a horse. Its glassy eyes glow a ruby red, and bits of "
    "steam spurt from its mouth. Somewhere in the center of its torso, what "
    "must be its heart shines with the same ruby red light."
  );
  SetKeyName("steel steer");
  SetAdjectives( ({"steel"}) );
  SetId(({"steed"}));
  SetRace("horse");
  SetClass("animal");
  SetLevel(2);
  SetGender("neuter");
  SetMeleeDamageType(BLUNT);
  //SetMeleeAttackString("needly teeth");
  
  SetAction(5, ({
    "!emote snorts fire.",
    "!emote stamps the ground with a CLANG.",
    "!emote whinnies loudly, sounding like a pile of pots and pans falling over.",     
  }) );
  
  SetNoCorpse(1);  
}

int eventDie(object killer) {
  object scrap;
  object room;
  if (room = environment((this_object()))) { 
    send_messages("collapse" , 
      "$agent_name $agent_verb into a small heap of scrap metal.",
      this_object(), this_object(), room);
    scrap = new("/std/crafting/survival/scrap_metal");
    scrap->eventMove(room);
  }
  return (npc::eventDie(killer));
}


