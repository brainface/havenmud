// By arathorn
// First thing I coded all year, and it's a whore.
// finished by Ranquest 02/14/99--lazy git.
//-- torak finalized with mondo zeddhelp<tm> --//

void whoreson(string sex);
void sexOne();
void funOne(object who);
void sexTwo(object who);
void funTwo(object who);
void sexThree(object who);
void funThree(object who);
void sexFour(object who);

#include <lib.h>
#include "../ungkh.h"
inherit LIB_SENTIENT;
static void create() {
  sentient::create();
  SetKeyName("Aria Lanthria");
  SetId( ({ "nymph", "aria lanthria", "aria", "lanthria"}) );
  SetAdjectives( ({"lustful","nymph"}) );
  SetShort("aria Lanthria the nymph");
  SetLong("Of all the creatures on Kailie, the nymphs "
          "are the most beautiful and exotic.  Aria Lanthria "
          "was captured many ages ago, and thrown into "
          "the whore industry.  After the first few times, "
          "she began to enjoy it.  Now she services the "
          "best she can.");
  AddAlcohol(100);
  SetInventory( ([
    U_OBJ + "silk_dress" : "wear dress",
    ]) );
  SetMessage("say", "sexily whisper");
  SetAction(8, ({
    "!say i used to hate this but now i love it!",
    "!moan seductively.",
    "!emote licks her finger slowly.",
    "!emote fondles herself erotically.",
    "!say me so horny.  Me so horny.  Me love you long time.",
    "!say i will do anyone!  Even Ogres!",
    "!say like what you see?",
    "!say i really need some sex.",
    "!say please buy me!",
    }) );
  SetCombatAction(3, ({
    "!yell help!  This pervert is a masochist!",
    }) );
  AddCommandResponse("give" ,(:whoreson:) );
  AddCommandResponse("request" ,(:whoreson:) );
  AddCommandResponse("sex", (:whoreson:) );
  AddCommandResponse("sell", (:whoreson:) );
  AddCommandResponse("price", "I charge 200 skins for my services.");
  SetRace("nymph");
  RemoveLanguage("nymal");
  SetLanguage("Uruk", 100, 1);
  SetClass("valkyr");
  SetLevel(3);
  SetGender("female");
  }

void whoreson(string sex) {
  object who = this_player();
  if (sex = "sex") {
    if (who->GetCurrency("skins") < 200) {
      eventForce("say you don't have enough money!");
      eventForce("say I must pay my owner 200 skins "
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
      who->AddCurrency("skins",-200);
      AddCurrency("skins",200);
      call_out( (: sexOne :), 1);
      }
    }
  } 

void sexOne() {
  object who = this_player();
  eventForce("say you better be good at this.");
  message("", "Aria slowly walks over to " +
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
  message("", "Aria %^RED%^flings%^RESET%^ herself on top of "
              + who->GetKeyName() + " in an %^RED%^erotical%^RESET%^ "
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
  message("", "Aria moans in pleasure with the "
              "force of " + who->GetKeyName() +
              " %^RED%^ramming%^RESET%^ into her "
              "hard and deep.",
              environment(this_object()) );
  call_out( (: funThree, who :), 15 );
  who->AddStamina(-40);
  }

void funThree(object who) {
  eventForce("french " + who->GetKeyName());
  who->eventForce("lick aria");
  eventForce("say Ohh!  Mmmm.. Ohhh...  Yes!");
  call_out( (: sexFour, who :), 15 );
  }

void sexFour(object who) {
  message("", "Aria goes through a final "
              "%^RED%^erotic moan%^RESET%^ "
              "as she arches her back in "
              "pure %^RED%^orgasmic%^RESET%^ "
              "pleasure as " + who->GetKeyName() +
              " continues to slam into her!",
              environment(this_object()) );
  eventForce("yell Ohh!  Yes!  Yes!  Ohhh!");
  eventForce("moan");
  eventForce("wear dress");
  if(who->GetStatLevel("strength") < 50) {
    who->eventForce("sleep");
    }
  who->AddCaffeine(100);
  who->AddStamina(-80);

  if (!random(2)) {
    message("system","You feel %^GREEN%^sickened%^RESET%^ "
    "by what you have done."
    "Maybe you have caught something from her?",who);
  new("/std/germs/ungkh_germ")->eventMove(who);
    return;
    }
  }
