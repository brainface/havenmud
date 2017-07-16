#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("heal ship");
  SetRules("STR", "OBJ");
  SetMagicCost(100, 100);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(35);
  SetSkills( ([
      "faith"   : 15,
      "healing" : 15,
    ]) );
  SetHelp(
    "This spell attempts to repair damage to a ship. "
    "Use <cast heal ship on ship>."
    );
}

int CanCast(object who, int level, mixed s, object *t) {
  object ship = environment(who);
  
  if (!vehiclep(ship)) {
    who->eventPrint("You can only use this magic while onboard the ship.");
    return 0;
  }
  if (s) {
    if (!ship->GetDamagedSystem(s)) {
      who->eventPrint("It does not appear that the " + s + " are damaged.");
      return 0;
    }
  }
  if (!s && sizeof(t)) {
    foreach(object tr in t) {
      if (!vehiclep(tr)) {
        who->eventPrint("You cannot target " + tr->GetShort() + ", as it is not a ship.");
        return 0;
      }
      if (tr->GetDamagePoints() == tr->GetMaxDamagePoints()) {
        who->eventPrint("But " + tr->GetShort() + " is not damaged!");
        return 0;
      }
    }
  }
  return ::CanCast(who, level, s, t);
}

int eventCast(object who, int level, mixed s, object *t) {
  object ship, tr;
  ship = environment(who);
  
  if (!s && sizeof(t)) {
    tr = t[0];
    tr->AddDamagePoints(level * 100);
    if (tr != ship) {
      send_messages( ({ "draw" }),
        "$agent_name%^BLUE%^ $agent_verb power%^RESET%^ from the oceans to restore the "
        "seaworthiness of $target_name.",
        who, tr, environment(who));
    }
    if (tr == ship) {
      message("system",
        who->GetCapName() + "%^BLUE%^ draws power%^RESET%^ from the oceans to restore the "
        "seaworthiness of " + tr->GetShort() + ".",
        tr, who);
      message("system",
        "You%^BLUE%^ draw power%^RESET%^ from the oceans to restore the "
        "seaworthiness of " + tr->GetShort() + ".",
        who);
      }
    return 1;
  }
  if (s) {
    send_messages( ({ "draw" }),
        "$agent_name%^BLUE%^ $agent_verb power%^RESET%^ from the oceans to restore the "
        "seaworthiness of " + ship->GetShort() + ".",
        who, 0, environment(who));
    ship->RemoveDamagedSystem(s);
    return 1;
  }
  return 1;
}
