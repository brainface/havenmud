/*
  Apparently bjorn needs more ways to be annoying
  Mahkefel 2012
*/
#include <lib.h>
#include <std.h>
#include <magic.h>
inherit LIB_SPELL;

void makeVoodooDoll(int charges, string chum, object caster);

static void create() {
  spell::create();
  SetSpell("create voodoo doll");
  SetRules("OBJ", "LIV");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "necromancy" : 1,
    "natural magic" : 1,
    ]) );
  SetHelp(
    "Creates a voodoo doll from a bit of an opponent's torn hair. Nefarious "
    "casters can also create dolls from unguarded corpses or severed limbs. "
    "Voodoo dolls are only an effective tool when created from those with an "
    "especially strong soul (players)."
    //"Only victims possessing an especially strong soul can provide the material "
    //"for a working voodoo doll (players)." /* this limitation enforced in other spells */
    );
}

varargs int eventCast(object who, int level, mixed blah, object *targets) {
  int amt, time;
  object target = targets[0];
  amt = who->GetSkillLevel("necromancy") * level/100 / 25;
  if (amt < 1) amt = 1;
  if (amt > 5) amt = 5;

  if ( !living(target)
    && (target->GetKeyName() == "corpse" || target->GetKeyName() == "limb")
    && target->GetOwner()
    ) {

    time = level + (who->GetSkillLevel("necromancy"));
    send_messages("pluck",
     "$agent_name carefully%^BOLD%^RED%^ $agent_verb%^RESET%^ some hair "
     "from $target_name.",
      who, target, environment(who));
    makeVoodooDoll(amt, target->GetOwner(), who);
    send_messages("",
      "$target_name is rapidly consumed by a swarm of "
      "flies and worms that skitter away as fast as they appeared.",
      who, target, environment(target));
    target->eventDestruct();
    return 1;
  }

  if (living(target)) {
    send_messages("yank",
     "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ a thick tuft of "
     "hair from $target_possessive_noun head!",
      who, target, environment(who));
      target->AddBleeding(random(1,2)+1);
    makeVoodooDoll(amt, target->GetKeyName(), who);
    return 1;
  }
  who->eventPrint(capitalize(target->GetShort()) + " is not alive or never was!");
  return 0;
}




void makeVoodooDoll(int charges, string chum, object who) {
  object doll;

  doll = new(STD_SPELLS "obj/voodoo_doll");
  doll->SetVictim(chum);
  doll->SetCharges(charges);

  doll->eventMove(who);
  send_messages("work", "$agent_name $agent_verb clay into a "
    "vague reminiscence of "+chum+", tucking the hair into the "
    "head.", who, 0, environment(who));
}


