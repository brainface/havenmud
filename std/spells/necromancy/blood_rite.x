/* Mahkefel 2011
 * To reduce annoying spam on "exchange spells", 
 *  converts all of caster's free health
 *  into mana.
 */

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("blood rite");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  //SetHealthCost(10, 40);
  SetSkills( ([
     "necromancy" : 100,
    ]) );
  SetDifficulty(25);
  SetHelp(
    "The necromancer, in a moment of desperation or insanity, "
    "sacrifices nearly all of his life to the spirits of the "
    "dead in exchange for magical energy in a single, bloody "
    "instant. The effects such an act have on the caster's "
    "soul are best left unmentioned."
  );
}

varargs int eventCast(object who, int level, mixed limb, object array tars) {
  int caster_health, caster_mana_missing;

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

  if (who->GetHealthPoints() < 150) {
    who->eventPrint("Cutting slightly into your bloodied body, "
      "you think better of adding to your woes.");
    return 0;
  }

  if (who->GetMagicPoints() ==who->GetMaxMagicPoints()) {
    who->eventPrint("You think better of cutting yourself for no reason.");
    return 0;
  }

  caster_health = who->GetHealthPoints() - 200;
  if (caster_health < 0 ) caster_health = 0;

  caster_mana_missing = who->GetMaxMagicPoints() - who->GetMagicPoints();

  //debug("caster health:");
  //debug(caster_health);
  //debug("caster mana missing:");
  //debug(caster_mana_missing);

  amount = caster_health;
  if (caster_mana_missing < caster_health) amount = caster_mana_missing;

  // sacrifice some health
  who->AddHealthPoints(-amount);
  //debug(amount);
  // minus your suck value
  amount = amount / ratio;

  //debug(amount);
  // now we actually add the mana
  who->AddMagicPoints(amount);

  send_messages("slice",
    "$agent_name%^BOLD%^WHITE%^ $agent_verb%^RESET%^ deeply into "
    "$agent_possessive forearm and blood "
    "%^RED%^gushes%^RESET%^ everywhere!",
    who, 0, environment(who) );

  // a fun failure message. don't die, little necromancer!
  if (level < 50 && !random(10)) {
    send_messages("cut",
      "$agent_name $agent_verb too deeply, and can't stop the bleeding!",
      who, 0, environment(who) );
    who->AddBleeding(1+random(10));
  }

  // let's make this actually evil maybe?
  who->AddMorality(-50); 

  who->eventDisplayStatus();
  
  return 1;
}

