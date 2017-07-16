/* Merchant Caravan Quest Guy 
 * Duukie
 */
#include <lib.h>
#include <daemons.h>
#include "merchant_path.h" 
#include <domains.h>
inherit LIB_BARKEEP;
void RequestJob(object who, string what);
void CommandHire(object who, string verb, string what);
void eventAttackMerchant();
int cmdEndWander(); /* This command called from an object */
object *Guards;

static void create() {
  ::create();
  Guards = ({ });
  SetKeyName("worried merchant");
  SetLimit(1);
  SetRace("human");
  SetGender(random(2) ? "male" : "female");
  SetClass("merchant");
  SetLevel(2);
  SetLanguage("Eltherian", 100);
  SetLanguage("Dwarvish", 100, 0);
  SetShort("a wealthy merchant");
  SetId( ({ "merchant", "merchant_quest" }) );
  SetAdjectives( ({ "wealthy", "worried" }) );
  SetLong("This person is a robust and healthy looking merchant. "
          "The look of concern on the merchant's face is "
          "genuine, as the route from Averath to the coast "
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
    AVERATH_OBJ "merchant_obj" : 1,
    ]) );
  AddCurrency("ducats", 25);
  SetProperty("no bump", 1);
}

void heart_beat() { 
  ::heart_beat();
  if (sizeof(Guards) && !random(50)) eventAttackMerchant();
}

varargs void RequestJob(object who, string what) {
  int wages;
  if (what != "job") {
    eventForce("speak The only thing I could offer would be a job.");
    return;
    }
  wages = (((wages = who->GetLevel() * 5) > 50) ? 50 : wages);
  eventForce("speak I will pay you " + (string)wages + " ducats "              "to accompany me to my home.  Thank you.");
  Guards = distinct_array( Guards + ({ who }) );
  who->eventForce("follow merchant");
  eventForce("lead " + who->GetKeyName());
  SetWanderPath(MERCHANT_PATH);
  SetWanderSpeed(1);
  SetAction(1, ({
    "!speak We're off to my home!",
    "!speak Hopefully there will be no bandits.  Heh Heh",
    }) );
}

varargs void CommandHire(object who, string verb, string what) {   RequestJob(who, verb);
}

int cmdEndWander() {
  int wages;
  
  foreach(object guard in Guards) {
    wages = (((wages = guard->GetLevel() * 5) > 50) ? 50 : wages);
    AddCurrency("ducats", wages);
    eventForce("give " + wages + " ducats to " + guard->GetKeyName() );
    if (!(guard->GetQuestCompleted("Averath Merchant"))) {
    guard->AddQuest("the Caravan Guard", "Merchant Quest");

    guard->AddDevelopmentPoints(2);
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
  int num = 0;

  foreach(object guard in Guards) {
    num += guard->GetLevel()/10;
  }

  num = random(num) + 2;
  while (num--) {
    attacker = new(AVERATH_NPC "bandit");
    attacker->eventMove(environment());
    attacker->eventForce("follow merchant");
    attacker->SetAttack(this_object());
    }
}
  

varargs int eventDie(object agent) {
  if (sizeof(Guards)) {
  Guards->eventPrint("You have failed to guard the Averath Merchant.");
  CHAT_D->eventSendChannel("Quest", "reports",
    capitalize(conjunction(Guards->GetCapName())) + " failed to guard the Averath Merchant.");
  }
  return ::eventDie(agent);
}

object *GetGuards() { return Guards; }
