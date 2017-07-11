/* Mahkefel 2011
 * To reduce annoying spam on "exchange spells", 
 *  converts all of caster's free stamina
 *  into mana.
 */

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("mind over matter");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetSkills( ([
     "conjuring" : 100,
     "enchantment" : 100,
    ]) );
  SetDifficulty(25);
  SetHelp(
    "The conjurer, in a time of great need, can focus all of "
    "her body's energy into magical power. Those unskilled in "
    "this spell may draw too much power and feint from the "
    "strain!"
  );
}

varargs int eventCast(object who, int level, mixed limb, object array tars) {
  int caster_stamina, caster_mana_missing;

  int amount, base, ratio;

  switch (level) {
    case 0..20:
       ratio = 5;
       break;
    case 21..40:
       ratio = 4;
       break;
    case 41..60:
       ratio = 3;
       break;
    case 61..80:
       ratio = 2;
   default:
       ratio = 1;
       break;
  }

  if (who->GetStaminaPoints() <= 100) {
    who->eventPrint("Drawing more power from your exhausted body "
      "will not help anything.");
    return 0;
  }

  if (who->GetMagicPoints() ==who->GetMaxMagicPoints()) {
    who->eventPrint("You think better of straining yourself for no reason.");
    return 0;
  }

  caster_stamina = who->GetStaminaPoints() - 100;
  if (caster_stamina < 0 ) caster_stamina = 0;

  caster_mana_missing = who->GetMaxMagicPoints() - who->GetMagicPoints();

  //debug("caster health:");
  //debug(caster_stamina);
  //debug("caster mana missing:");
  //debug(caster_mana_missing);

  amount = caster_stamina;
  if (caster_mana_missing < caster_stamina) amount = caster_mana_missing;

  // sacrifice some stamina
  who->AddStaminaPoints(-amount);
  //debug(amount);
  // minus your suck value
  amount = amount / ratio;

  //debug(amount);
  // now we actually add the mana
  who->AddMagicPoints(amount);

  send_messages( ({"scruntch","focus"}),
    "$agent_name $agent_verb up $agent_possessive face and "
    "$agent_verb intently!",
    who, 0, environment(who) );

  // a fun failure message. don't die, little conjurer!
  if (level < 50 && !random(10)) {
    send_messages(({"attempt","feint"}),
      "$agent_name $agent_verb to focus more energy than $agent_possessive "
      "body can handle, and $agent_verb!",
      who, 0, environment(who) );
    who->SetSleeping(1+random(2));
  }

  who->eventDisplayStatus();
  
  return 1;
}

