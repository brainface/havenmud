//
// Torak@Haven
// War Touch
// Weapon buff / caffienater
// Religion Aberach
// originally from /std/spells/faith/bless.c
//

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;


static void create() {
  spell::create();
  SetSpell("war touch");
  SetRules("OBJ");
  SetSpellType(SPELL_OTHER);
  SetMagicCost(50, 50);
  SetSkills( ([
    "faith" : 125,
    "necromancy" : 125,
    ]) );
  SetReligions( ({ "Aberach" }) );
  SetHelp(
    "Cast on an object to imbue it with the Touch of War blessing "
    "causing it to deal ice damage when used as a weapon."
    "/n"
    "cast war touch on <target>"
    );
}

varargs int eventCast(object who, int level, mixed blah, object *targets) {
  int amt, time, ice;
  string icedmg;
  object target = targets[0];
  ice = who->GetSkillLevel("ice magic") * level/100;
  icedmg = "ICE|" + target->GetDamageType();
  amt = who->GetSkillLevel("faith") * level/100;
  if (amt < 1) amt = 1;
  if (amt > 20) amt = 20;
  
  // mahkefel 2014: no idea if this has any effect on vehicles.
  // fixed a display bug, though at least.
  if (vehiclep(target)) {
    time = level + (who->GetSkillLevel("faith"));
    send_messages("bless",
     "$agent_name%^BOLD%^CYAN%^ $agent_verb%^RESET%^ the ship with the Touch of War.",
      who, target, environment(who));
      target->eventBless(amt, time);
    return 1;
  }
  
  if (!living(target)) {
    time = level + (who->GetSkillLevel("faith"));
    send_messages("imbue",
     "$agent_name%^BOLD%^CYAN%^ $agent_verb%^RESET%^ $target_name with the Touch of War.",
      who, target, environment(who));
      target->eventBless(amt, time);

      if(GetDamageType()){
        target->SetDamageType(icedmg);
        }

    return 1;
  }
  if (living(target)) {
    send_messages("reach",
     "$agent_name%^BOLD%^BLUE%^ $agent_verb%^RESET%^ with an icy finger touching "
     "$target_name on the shoulder.",
      who, target, environment(who));
      target->AddCaffeine(ice);
    return 1;
  }
  return 1;
}
