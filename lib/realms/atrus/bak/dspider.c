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
          "with black scales and small spikes. The massive undulating form "
          "encompases the area with an overpowering presense of pain. "
          "The giant legs of this spider flex and relax with absolute power"
          "as if they could crush a man like a feather. Unlike normal spiders "
          "this one has only two eyes, and peers at you with hidden "
          "intelligence.");
  SetGender("male");
  SetRace("arachnid");
  SetClass("valkyr");
  SetLevel(1375); /* Holy shit! */
 /*  SetStat("speed",5000); Commented out, NO speed stat anymore */
  SetFearType("GodPet Fear<tm>");
  SetResistLevel(10000000);
  SetFearLength(10);
  SetCombatAction(100, (: eventThing :) );
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
