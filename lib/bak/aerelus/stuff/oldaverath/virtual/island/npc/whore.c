// By arathorn
// First thing I coded all year, and it's a whore.
// finished by Ranquest 02/14/99--lazy git.
//-- torak finalized with mondo zeddhelp<tm> --//
// Made this for Haven 2 to taunt Cyric.

void whoreson(string sex);
void sexOne();
void funOne(object who);
void sexTwo(object who);
void funTwo(object who);
void sexThree(object who);
void funThree(object who);
void sexFour(object who);

#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_SENTIENT;
static void create() {
  sentient::create();
  SetKeyName("harriet");
  SetWander(1);
  SetId( ({ "harriet", "woman", "whore" }) );
  SetAdjectives( ({ "beautiful", "and", "overly", "friendly" }) );
  SetShort("Harriet, a beautiful and overly friendly woman");
  SetLong("Harriet is a friendly woman that roams around the "
          "lower class areas of Averath. Her skills come to "
          "the highest bidders.");
  AddAlcohol(100);
  SetLimit(1);
  SetInventory( ([
    AVERATH_OBJ "dress" : "wear dress",
    ]) );
  SetMessage("say", "sexily whisper");
  SetAction(8, ({
    "!say like what you see?",
    "!say i really need some attention.",
    "!say If you got the money, I got the time.",
    "!sigh quietly",
    "!smile sexily",
    "!wink erotically",
    }) );
  SetCombatAction(3, ({
    "!yell help!  This pervert is a masochist!",
    }) );
  AddCommandResponse("give" ,(:whoreson:) );
  AddCommandResponse("request" ,(:whoreson:) );
  AddRequestResponse("sex", (:whoreson:) );
  AddCommandResponse("sell", (:whoreson:) );
  AddCommandResponse("price", "I charge 20 ducats for my services.");
  SetRace("human");
  SetClass("rogue");
  SetLevel(3);
  SetGender("female");
  SetCurrency("ducats", random(30));
  }

void whoreson(string sex) {
  object who = this_player();
  if (sex = "sex") {
    if (who->GetCurrency("ducats") < 20) {
      eventForce("say you don't have enough money!");
      eventForce("say I charge 20 ducats "
        "whenever someone requests my services.");
      eventForce("spit derisively");
      return;
      }
    if (who->GetGender() != "male") {
      eventForce("spit");
      eventForce("say I only service men.");
      return;
      }
    else {
      SetWander(0);
      who->AddCurrency("ducats",-20);
      AddCurrency("ducats",20);
      call_out( (: sexOne :), 1);
      }
    }
  } 

void sexOne() {
  object who = this_player();
  eventForce("say you better be good at this.");
  message("", "Harriet slowly walks over to " +
              who->GetCapName() + " and starts kissing "
              "him all over.",
              environment(this_object()) );
  call_out( (: funOne, who :), 15);
  }

void funOne(object who) {
  eventForce("kiss " + who->GetKeyName());
  eventForce("remove dress");
  call_out( (: sexTwo, who :), 15);
  }

void sexTwo(object who) {
  message("", "Harriet %^RED%^flings%^RESET%^ herself on top of "
              + who->GetKeyName() + " in an %^RED%^erotic%^RESET%^ "
              "fury, removing his clothes with ease.",
              environment(this_object()) );
  who->eventForce("remove all");
  call_out( (: funTwo, who :), 15);
  who->AddStamina(-20);
  }

void funTwo(object who) {
  eventForce("lick " + who->GetKeyName());
  who->eventForce("moan");
  call_out( (: sexThree, who :), 15);
  }

void sexThree(object who) {
  message("", "Harriet moans in pleasure with the "
              "force of " + who->GetKeyName() +
              " %^RED%^ramming%^RESET%^ into her "
              "hard and deep.",
              environment(this_object()) );
  call_out( (: funThree, who :), 15 );
  who->AddStamina(-40);
  }

void funThree(object who) {
  eventForce("french " + who->GetKeyName());
  who->eventForce("lick harriet");
  eventForce("say Ohh!  Mmmm.. Ohhh...  Yes!");
  call_out( (: sexFour, who :), 15 );
  }

void sexFour(object who) {
  message("", "Harriet goes through a final "
              "%^RED%^erotic moan%^RESET%^ "
              "as she arches her back in "
              "pure %^RED%^orgasmic%^RESET%^ "
              "pleasure as " + who->GetKeyName() +
              " continues to slam into her!",
              environment(this_object()) );
  eventForce("yell Ohh!  Yes!  Yes!  Ohhh!");
  eventForce("moan");
  eventForce("wear dress");
  SetWander(1);
  if (who->GetStat("strength") < 50) {
    who->eventForce("sleep");
    }
  who->AddCaffeine(100);
  who->AddStamina(-80);

  if (!random(10)) {
    message("system","You feel %^GREEN%^sickened%^RESET%^ "
    "by what you have done."
    "Maybe you have caught something from her?",who);
    new(STD_GERMS "std")->eventMove(who);
    return;
    }
  }
