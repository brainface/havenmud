#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;
int eventThing();

static void create(



) {
  npc::create();
  SetKeyName("giant spider");
  SetShort("Jagra's giant spider");
  SetId( ({ "spider" }) );
  SetAdjectives( ({ "giant","jagra's" }) );
  SetLong("This giant spider stands five feet tall, and is covered "
          "with black scales and small spikes. Unlike normal spiders "
          "this one has only two eyes, and peers at you with hidden "
          "intelligence.");
  SetGender("male");
  SetRace("arachnid");
  SetClass("animal");
  SetLevel(130);
  SetStat("agility",500);
  SetFearType("arachnophobia");
  SetResistLevel(100);
  SetFearLength(10);
  SetCombatAction(25, (: eventThing :) );
  SetMorality(-200);
   }

int eventThing() {
     if (1) {
     send_messages("attack",
        "$agent_name $agent_verb%^RED%^BOLD%^ $target_name "
        "%^RESET%^with "
        "$agent_possessive poison!", this_object(), 
         GetCurrentEnemy(), environment() );
      GetCurrentEnemy()->eventDestruct(); 
    return 1;
        }
  return 0;
  }

void init() {
  fear::init();
  npc::init();
  }

