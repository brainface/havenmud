/* Merchant Caravan Quest Guy 
 * Duukie
 */
#include <lib.h>
#include <daemons.h>
#include <domains.h>
#include "merchant_path.h" 
#include "../haven.h"
#include <std.h>
inherit LIB_BARKEEP;
void RequestJob(object who, string what);
void CommandHire(object who, string verb, string what);
void eventAttackMerchant();
int cmdEndWander(); /* This command called from an object */
object *Guards;

static void create() {
  ::create();
  Guards = ({ });
  SetKeyName("dwarf merchant");
  SetRace("dwarf");
  SetGender(random(2) ? "male" : "female");
  SetClass("merchant");
  SetStat("strength", 15, 3);
  SetStat("durability", 15, 3);
  SetLevel(5);
  SetMorality(100);
  SetProperty("no bump", 1);
  SetLanguage("Eltherian", 100, 1);
  RemoveLanguage("Runic");
  SetShort("a wealthy dwarven merchant");
  SetId( ({ "merchant", "dwarf", "dwarf_merchant_quest" }) );
  SetAdjectives( ({ "wealthy", "dwarf", "dwarven" }) );
  SetLong("This dwarf is a robust and healthy looking merchant. "
          "The look of concern on the merchant's face is "
          "genuine, as the route from Haven Town to Glimmerdin "
          "can be trying at times.");
  SetAction(5, ({
    "!speak I wish I could hire some guards for my trip.",
    "!speak Perhaps you would like a job?",
    "!speak I would love to hire you!",
    "!emote looks worried.",
    }) );
  SetCombatAction(10, ({
    "!emote shrieks like a child.",
    "!whimper",
    "!speak Please don't kill me!",
    "!speak Help me!",
    "!emote looks ill.",
    }) );
  AddCommandResponse("hire", (: CommandHire :) );
  AddRequestResponse("job", (: RequestJob :) );
  SetInventory( ([
    STD_WEAPON "knife/small_knife" : "wield knife",
    STD_CLOTHING "shirt/tunic" : "wear tunic",
    STD_CLOTHING "pant/brown_pants" : "wear pants",
    H_OBJ "merchant_obj" : 1,
    ]) );
  AddCurrency("imperials", 100);
  SetWanderPath(MERCHANT_PATH);
}

void heart_beat() { 
  ::heart_beat();
  if (sizeof(Guards) && !random(25)) eventAttackMerchant();
}

varargs void RequestJob(object who, string what) {
  int wages;
  if (what != "job") {
    eventForce("speak The only thing I could offer would be a job.");
    return;
    }
  if (!userp(who)) {
    eventForce("speak Sorry, I only hire people of their own free will.");
    return;
  }
  wages = (((wages = who->GetLevel() * 500) > 5000) ? 5000 : wages);
  eventForce("speak I will pay you " + (string)wages + " imperials " 
             "to accompany me to Glimmerdin.  Thank you.");
  Guards = distinct_array( Guards + ({ who }) );
  who->eventForce("follow dwarven merchant");
  eventForce("lead " + who->GetKeyName());
  SetWanderSpeed(1);
  SetAction(1, ({
    "!speak We're off to Glimmerdin!",
    "!speak Hopefully there will be no bandits.  Heh Heh",
    }) );
}

varargs void CommandHire(object who, string verb, string what) {   
        RequestJob(who, verb);
}

int cmdEndWander() {
  int wages;
  
  foreach(object guard in Guards) {
  if (!guard) continue;
  wages = (((wages = guard->GetLevel() * 500) > 5000) ? 5000 : wages);
    guard->AddCurrency("imperials", wages);
    eventForce("speak Here you are, " + wages + " imperials as agreed, " + guard->GetCapName() );
    if (!(guard->GetQuestCompleted("Dwarf Merchant"))) {
      guard->AddQuest("the Caravan Guard", "Dwarf Merchant");
      guard->AddDevelopmentPoints(4);
      }
    }
  SetWanderSpeed(0);
  eventForce("speak Thank you for guarding me.");
  eventForce("wave farewell");
  call_out( (: eventDestruct :), 0);
  return 1;
}

void eventAttackMerchant() {
  object attacker;
  int num = 0, guardlevel = 0;
  int enemies = sizeof(GetEnemies());
  Guards = filter(Guards, (: $1 :) );
  foreach(object guard in Guards) {
    if (guard) {
      num += guard->GetLevel()/10;
      guardlevel += guard->GetLevel();
    } else {
        Guards -= ({ guard });
        }
  }
  if (!sizeof(Guards)) {
    eventForce("yell OH NOES! I'm UNGUARDED!");
    environment()->eventPrint("The dwarf merchant runs for the hills!");
    eventDestruct();
  }
  guardlevel = guardlevel/sizeof(Guards);
  guardlevel = random(guardlevel);
  if (!guardlevel) guardlevel = 1;
  num = random(num) + 2;
  if (enemies > 10) return;
  eventForce("yell BANDITS ARE ATTACKING!");
  while (num--) {
    if (random(2)) {
        attacker = new(SOUTHERN_COAST_TOWNS "haven/npc/quest/bandit");
    } else {
        attacker = new(SOUTHERN_COAST_TOWNS "haven/npc/quest/slash_bandit");
    }
    attacker->SetLevel(guardlevel);
    attacker->eventMove(environment());
    attacker->eventForce("follow merchant");
    attacker->SetAttack(this_object());
    }
}
  

varargs int eventDie(object agent) {
  if (sizeof(Guards)) {
  Guards->eventPrint("You have failed to guard the Dwarf Merchant.");
  CHAT_D->eventSendChannel("Quest", "reports",
    capitalize(conjunction(Guards->GetCapName())) + " failed to guard the Dwarven Merchant.");
  }
  return ::eventDie(agent);
}

object *GetGuards() { return Guards; }


void eventGreet(object who) {
  return RequestJob(who, "");
}
