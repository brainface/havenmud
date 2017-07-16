/*
 * planar ascension
 *
 * all planars as one for lazy shannon
 *
 * warlords, gypsies, and shadowmages get an extra stat
 *   and shadowmages turn invisible.
 *
 * this fails more often than normal planar, but fail duration
 *   is cut to a short time regardless of level.
 *
 * mahkefel 20101111
 */

#include <lib.h>
#include <magic.h>

int eventEndPlanar(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("planar ascension");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
    "conjuring" : 275,
    "enchantment" : 275,
  ])  );
  SetRequiredMagic(100);
  //SetMagicCost(50, 50);
  SetRequiredStamina(15);
  SetStaminaCost(50, 20);
  SetDifficulty(50);
  SetUniqueSpell(1);
  SetHelp(
    "This spell allows the caster to draw energy from the planes and "
    "greatly enhance all traits they find worthwhile in a living creature. "
    "Because planar energy is difficult to control, there is a chance of "
    "unexpected results. "
    "\n\nA fiery diamond must be consumed as a focus for this spell. "
  );
}

// I will not freaking allow this spell to stack with anything.
int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  object *diamonds;
  debug("iterating thru inventory");
  diamonds = filter(all_inventory(who),
    (: member_array("mining_diamond", $1->GetId() ) > -1 :) );
  //debug("i have this many shards: ");
  debug(sizeof(diamonds));
  if (sizeof(diamonds) < 1 ) {
    send_messages( "mutter", "$agent_name $agent_verb a few words of magic that "
      "sound impressive but have little effect", who, 0, environment(who) );
    message("system", "You must have a fiery diamond to cast this spell!", who);
    who->eventPrint();
    return 0;
  }
  if(target->GetProperty("planar_ascension")) {
    message("system", "That person's has already achieved ascension!", who);
    return 0;
  } else if(
    target->GetStatBonus("strength") ||
    target->GetStatBonus("durability") ||
    target->GetStatBonus("coordination") ||
    target->GetStatBonus("agility") ||
    target->GetStatBonus("intelligence") ||
    target->GetStatBonus("wisdom") ||
    target->GetStatBonus("charisma") ||
    target->GetStatBonus("luck") ) {
      message("system", "Other magic affecting that person is preventing " +
        possessive(target) + " planar ascension!", who);
    return 0;
  }

  if (diamonds[0]) diamonds[0]->eventDestruct();
  send_messages( ({"grasp","chant"}), "$agent_name $agent_verb a fiery "
    "diamond and $agent_verb a few words of magic.",
    who, 0, environment(who) );
  return spell::eventCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur, success;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("enchantment") +
    who->GetSkillLevel("conjuring"))/10 + 10;
  dur = (level * (15 + 10 + who->GetSkillLevel("enchantment")/20));
  success = 1;
  /* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/4)))) {
    success = -1;
    amt = -amt;
    // cut duration on a failure.
    // if someone has -70 to all stats for a long time, they'll just log.
    dur = 50 + random(10);
    if (target == who) {
      send_messages( ({ "lose", "mutate" }), "$agent_name $agent_verb control "
        "of the planar energies and horribly $agent_verb "
        "$agent_reflexive.", 
        who, 0, environment(who));
    } else {
      send_messages( ({ "lose", "mutate" }), "$agent_name $agent_verb control "
        "of the planar energies and horribly $agent_verb $target_name.",
        who, target, environment(target));
    }
  } else {

    /* SUCCESS SUCCESS SUCCESS */

    if (target == who) {
      send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
        "the planar energies and $agent_verb them to empower "
        "$agent_possessive_noun body and mind.", who, 0, environment(who));
    } else {
      send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
        "the planar energies and $agent_verb them to empower "
        "$target_possessive_noun body and mind.", who, target, environment(target));
    }

  }
  debug("dur: " + (string)dur + " amount: " + (string)amt);
  debug("success? " + (string)success);
  /* DO STUFF DO STUFF */
  target->SetProperty("planar_ascension", 1);
  target->AddStatBonus("strength", amt, dur);
  target->AddStatBonus("durability", amt, dur);
  target->AddStatBonus("intelligence", amt, dur);
  target->AddStatBonus("wisdom", amt, dur);
  target->AddStatBonus("charisma", amt, dur);
  if (who->GetClass() == "warlord") {
    debug("warlord");
    target->SetProperty("warlord_ascension",1);
    target->AddStatBonus("coordination", amt, dur);
    if (success) target->eventPrint(
      "%^BOLD%^GREEN%^You feel ready for war.%^RESET%^"
      );  
  } else if (target->GetClass() == "gypsy") {
    debug("gypsy");
    target->SetProperty("gypsy_ascension",1);
    target->AddStatBonus("luck", amt, dur);
    if (success) target->eventPrint(
      "%^BOLD%^GREEN%^You feel fated for glory.%^RESET%^"
      );  
  } else if (target->GetClass() == "shadowmage") {
    debug("shadowmage");
    target->SetProperty("shadowmage_ascension",1);
    target->AddStatBonus("agility", amt, dur);
    target->SetInvis(1);
    if (success) target->eventPrint(
      "%^BOLD%^GREEN%^You feel shadows embrace you.%^RESET%^"
      );  
    if (!success) {
      target->eventPrint("%^BOLD%^BLACK%^The world fades from view!%^RESET%^");
      target->eventBlind(dur);
    }
  } else {
    debug("evoker/enchanter or something");
    target->eventPrint(
      "%^BOLD%^GREEN%^Energy courses through your mind and body.%^RESET%^"
    );  
  }
  call_out( (: eventEndPlanar, target :), dur);

  return 1;
}

int eventEndPlanar(object who) {
  if (!who) {
    return 1;
  }
  who->RemoveProperty("planar_ascension");
  who->RemoveStatBonus("strength");
  who->RemoveStatBonus("durability");
  who->RemoveStatBonus("intelligence");
  who->RemoveStatBonus("wisdom");
  who->RemoveStatBonus("charisma");
  who->eventPrint("%^BOLD%^GREEN%^You feel your body return to a "
    "horrifying normalcy.%^RESET%^");
  if (who->GetProperty("warlord_ascension")) {
    who->RemoveProperty("warlord_ascension");
    who->RemoveStatBonus("coordination");  
  }
  if (who->GetProperty("gypsy_ascension")) {
    who->RemoveProperty("gypsy_ascension");
    who->RemoveStatBonus("luck");
  }
  if (who->GetProperty("shadowmage_ascension")) {
    who->RemoveProperty("shadowmage_ascension");
    who->RemoveStatBonus("agility");
    who->SetInvis(0);
  }
  return 1;
}
