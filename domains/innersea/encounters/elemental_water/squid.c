// mahkefel may '10
// water elemental boarder
#include <lib.h>
#include <domains.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_PIRATE;

void eventSpecial();
int eventFishies();

static void create() {
  ::create();
  SetRace("squid");
  SetGender("male");
  SetClass("sailor");
  SetLevel(1);
  SetKeyName("squid");
  SetId( ({ "squid" }) );
  SetShort("a squirming squid");
  SetAdjectives( ({ "squirming" }) );
  SetLong(
    "This slithering and squirming squid is about the size of a "
    "muezzin, if a muezzin was made of tentacles and had no respect "
    "for personal boundaries. Its lone eye glances about with curious "
    "intelligence, and the suckers along its tentacles look "
    "like they could get a pretty good grasp of things."
  );
  SetAction(5, ({
    "!emote squirms about.",
    "!emote hugs you.",
  }) );
  SetCombatAction( 15, ({
    (: eventSpecial :),
  }) );
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/mop" : "wield mop in third tentacle and seventh tentacle",
    INNERSEA_ENCOUNTERS "obj/rigging_knife" : random(2),
    INNERSEA_ENCOUNTERS "obj/broad_axe" : random(2),
    INNERSEA_ENCOUNTERS "obj/belaying_pin" : random(2),
  ]) );
  SetFirstCommands(({
    "wield knives",
    "wield pins",
    "wield axes",
  }));
  SetCaptainAggressiveness(80);
  SetResistance(WATER, "high");
  SetResistance(POISON, "high");


  SetResistance(SHOCK|HEAT, "weakness");
  SetProperty("pirate", "nereid");
  SetShipWander(1);

  SetReligion("Damhair");
  SetMinLevel(1);
  SetMaxLevel(300);
}

// I steal stuff, for I am a squid.
void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  object array eq = all_inventory(target);
  if (!who || !target) return;
  send_messages("wrap",
    "$agent_name%^GREEN%^ $agent_verb%^RESET%^ a tentacle around $target_name!",
    who, target, environment() );
  if(sizeof(eq)) {
    object thing = (eq[random(sizeof(eq))]);
    send_messages("yank",
      "$agent_name%^BOLD%^GREEN%^ $agent_verb%^RESET%^ a " + thing->GetKeyName()
      + "from $target_name!",
      who, target, environment(who));
    target->eventRemove(thing);
    thing->eventMove(this_object());
    eventForce("wield all"); // eh, might work
  }
}

