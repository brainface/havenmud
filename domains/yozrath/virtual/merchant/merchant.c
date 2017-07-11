/* Merchant Caravan Quest Guy 
 * Duukie
 */
#include <lib.h>
#include <daemons.h>
#include <domains.h>
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
  SetKeyName("desert merchant");
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetGender("male");
  SetClass("merchant");
  SetStat("strength", 15, 3);
  SetStat("durability", 15, 3);
  SetLevel(5);
  SetProperty("no bump", 1);
  SetShort("a thin desert merchant");
  SetId( ({ "merchant", "desert_merchant_quest" }) );
  SetAdjectives( ({ "thin", "desert", }) );
  SetLong("This merchant is a thin and wiry looking merchant. "
          "The look of concern on the merchant's face is "
          "genuine, as the route from the Havenwood to Yozrath "
          "can be trying at times.");
  SetAction(5, ({
    "!speak I wish I could hire some guards for my trip.",
    "!speak Perhaps you would like a job?",
    "!speak I would love to hire you!",
    "!emote looks nervous.",
    }) );
  SetCombatAction(10, ({
    "!emote howls in fear.",
    "!whimper",
    "!speak Please don't kill me!",
    "!speak Help me!",
    "!emote looks ill.",
    }) );
  AddCommandResponse("hire", (: CommandHire :) );
  AddRequestResponse("job", (: RequestJob :) );
  SetInventory( ([
    STD_WEAPON "knife/small_knife" : "wield knife",
    YOZRATH_VIRTUAL "merchant/merchant_obj" : 1,
    ]) );
  AddCurrency("dinar", 2000);
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
  wages = (((wages = who->GetLevel() * 10000) > 100000) ? 100000 : wages);
  eventForce("speak I will pay you " + (string)wages + " dinar " 
             "to accompany me to Yozrath.  Thank you.");
  Guards = distinct_array( Guards + ({ who }) );
  who->eventForce("follow desert merchant");
  eventForce("lead " + who->GetKeyName());
  SetWanderSpeed(1);
  SetAction(1, ({
    "!speak We're off to Yozrath!",
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
  wages = (((wages = guard->GetLevel() * 10000) > 100000) ? 100000 : wages);
    guard->AddCurrency("dinar", wages);
    eventForce("speak Here you are, " + wages + " dinar as agreed, " + guard->GetKeyName() );
    if (!(guard->GetQuestCompleted("Desert Merchant"))) {
      guard->AddQuest("the Desert Caravaner", "Desert Merchant");
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
  guardlevel = guardlevel/sizeof(Guards);
  guardlevel = random(guardlevel);
  if (guardlevel < 10) guardlevel = 10;
  if (guardlevel > 50) guardlevel = 50;
  num = random(num) + 2;
  if (enemies > 10) return;
  while (num--) {
    if (random(2)) {
    	attacker = new(YOZRATH_VIRTUAL "merchant/raider1");
    } else {
    	attacker = new(YOZRATH_VIRTUAL "merchant/raider2");
    }
    attacker->SetLevel(guardlevel);
    attacker->eventMove(environment());
    attacker->eventForce("follow merchant");
    attacker->SetAttack(this_object());
    }
}
  

varargs int eventDie(object agent) {
  if (sizeof(Guards)) {
  Guards->eventPrint("You have failed to guard the Desert Merchant.");
  CHAT_D->eventSendChannel("Quest", "reports",
    capitalize(conjunction(Guards->GetCapName())) + " failed to guard the Desert Merchant.");
  }
  return ::eventDie(agent);
}

object *GetGuards() { return Guards; }

mixed eventWander() {
  string env = base_name(environment());
  int x, y;
  string cmd;
  
  if (GetInCombat()) return;
  
  if (sscanf(env, "/domains/yozrath/virtual/desert/%d,%d", x, y) != 2) {
    eventForce("say I seem to be lost.");
    eventForce("wave");
    eventDestruct();
    return;
  }
  
  if (x < 0) cmd = "go east";
  if (x > 0) cmd = "go west";
  if (y < -2) cmd = "go north";
  if (y > -2) cmd = "go south";
  if (x == 0 && y == -2) cmd = "endwander";
  eventForce(cmd);
  return 1;
}


void eventGreet(object who) {
  return RequestJob(who, "");
}
