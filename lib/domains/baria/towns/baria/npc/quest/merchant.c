
/* Merchant Caravan Quest Guy
 * Duukie
 */
#include <lib.h>
#include <daemons.h>
#include <domains.h>
#include "merchant_path.h"
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
  SetKeyName("barian herb runner");
  SetRace("draconian");
  SetGender(random(2) ? "male" : "female");
  SetClass("merchant");
  SetStat("strength", 15, 3);
  SetStat("durability", 15, 3);
  SetLevel(5);
  SetMorality(100);
  SetProperty("no bump", 1);
  SetLanguage("Barian", 100, 1);
  RemoveLanguage("Dragonish");
  SetShort("a sneaky draconian herb runner");
  SetId( ({ "runner", "draconian", "barian_merchant_quest" }) );
  SetAdjectives( ({ "sneaky", "draconian", "herb" }) );
  SetLong("This draconian is a lithe and sneaky looking person. "
          "The look of concern on its face is "
          "genuine, as the route from Baria to Keryth "
          "can be trying at times for those running unholy herbal supplies.");
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
    __DIR__ "merchant_obj" : 1,
    ]) );
  AddCurrency("chits", 100);
  SetWanderPath(MERCHANT_PATH);
  //SetUnique(1);
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
  eventForce("speak I will pay you " + (string)wages + " chits "
             "to accompany me to Keryth.  Thank you.");
  Guards = distinct_array( Guards + ({ who }) );
  who->eventForce("follow herb runner");
  eventForce("lead " + who->GetKeyName());
  SetWanderSpeed(1);
  SetAction(1, ({
    "!speak We're off to Keryth!",
    "!speak Hopefully there will be no meddling Kylin whack-jobs.  Heh Heh",
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
    guard->AddCurrency("chits", wages);
    eventForce("speak Here you are, " + wages + " chits as agreed, " + guard->GetCapName() );
    if (!(guard->GetQuestCompleted("Barian Merchant"))) {
      guard->AddQuest("the Runner", "Barian Merchant");
      guard->AddRepPoints(50);
      guard->AddDevelopmentPoints(4);
      }
    }
  SetWanderSpeed(0);
  eventForce("speak Thank you for guarding me.");
  eventForce("wave farewell");
    Guards = ({ });
  eventMove(BARIA_TOWNS "baria/room/path9");
  SetWanderPath(MERCHANT_PATH);  
  //call_out( (: eventDestruct :), 0);
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
    environment()->eventPrint("The draconian runner runs for the hills!");
    eventDestruct();
  }
 // attempting to make this a little more sane for high level players
//  guardlevel = guardlevel/sizeof(Guards);
//  guardlevel = random(guardlevel);
  guardlevel = guardlevel/sizeof(Guards);
  guardlevel = guardlevel * 0.8;
  guardlevel += random( (guardlevel * 0.2) );
//      debug("Guardlevel " + guardlevel);
  if (!guardlevel) guardlevel = 1;
  num = random(num) + 2;
  if (num > 5) num = 5;
        num = num * sizeof(Guards);
//      debug("NUM " + num);
  if (enemies > 10) return;
  eventForce("yell A KYLIN INTERDICT TEAM!");
  while (num--) {
    if (random(2)) {
        attacker = new(BARIA_TOWNS "baria/npc/quest/bandit");
    } else {
        attacker = new(BARIA_TOWNS "baria/npc/quest/slash_bandit");
    }
    attacker->SetLevel(guardlevel);
    attacker->eventMove(environment());
    attacker->eventForce("follow runner");
    attacker->SetAttack(this_object());
    }
}


varargs int eventDie(object agent) {
  if (sizeof(Guards)) {
  Guards->eventPrint("You have failed to guard the Barian Runner.");
  CHAT_D->eventSendChannel("Quest", "reports",
    capitalize(conjunction(Guards->GetCapName())) + " failed to guard the Barian Runner.");
  }
  return ::eventDie(agent);
}

object *GetGuards() { return Guards; }

void eventGreet(object who) {
  return RequestJob(who, "");
}

