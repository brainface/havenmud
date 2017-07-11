/* Shiny New Whore Code!  YAY!
 * Duuk
 * 3/12/2006
 */
#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <position.h>
#include "../parva.h"
inherit LIB_NPC;

int eventHire(string command);
object John;
object SetJohn(object who);
object GetJohn();
void eventPerform(int x);
int eventCombatAction();
int eventAction();

static void create() {
  ::create();
  SetKeyName("Aria Lanthria");
  SetShort("Aria Lanthria the Nymph");
  SetRace("nymph");
  SetBaseLanguage("Enlan");
  SetGender("female");
  SetClass("bard");
  SetLevel(25);
  SetMorality(-1000);
  SetInventory( ([
    PARVA_OBJ "aria_dress" : "wear dress",
    ]) );
  SetId( ({ "aria", "lanthria", "nymph" }) );
  SetAdjectives( ({ "aria", }) );
  SetLong(
    "Aria Lanthria is a nymph, a beautiful creature most commonly found on the "
    "forest plane. Her long silky hair has a golden hue that reflects the light "
    "in a seductive manner, making her appearance even more attractive than it "
    "otherwise would be. She often tilts her head slightly with her lips pursed, "
    "giving her a pouty look that comes across very sex-kittenish."
    );
  AddRequestResponse("price", "I charge 20,000 oros for my services.");
  AddRequestResponse("sex",  (: eventHire :) );
  AddRequestResponse("service", (: eventHire :) );
  AddRequestResponse("services", (: eventHire :) );
  SetCombatAction(5, (: eventCombatAction :) );
  SetMessage("say", "sexily purr");
  SetMessage("ask", "sexily inquire");
}

object SetJohn(object who) { return John = who; }
object GetJohn() { return John; }

int eventHire(string what) {
  object who = this_player();
  object *viewers;
  string *tmp = ({ });
  if (who->GetCurrency("oros") < 20000) {
    eventForce("say I charge 20000 oros for my time.  Get lost.");
    return 1;
  }
  viewers = all_inventory(environment());
  viewers = filter(viewers, (: living :) );
  viewers -= ({ this_object(), who });
  viewers = filter(viewers, (: !($1->GetInvis()) :) );
  if (sizeof(viewers)) {
    foreach(object v in viewers) { tmp += ({ capitalize(v->GetKeyName()) }); }
    eventForce("say I don't know about you, but I don't want " + conjunction(tmp, "or") + 
               " to share our special time with us.");
    return 1;
  }
  SetJohn(who);
  who->AddCurrency("oros", -20000);
  call_out( (: eventPerform, 0 :), 5);
}

void eventPerform(int i) {
  object who = GetJohn();
  if (!present(who, environment(this_object()))) {
    SetJohn(0);
    return;
  }
  switch(i) {
    case 0:
      eventForce("say Let's see what we could do that might interest someone like you...");
      environment()->eventPrint("The music seems to slow and become more seductive.");
      send_messages( ({ "dance" }),
        "$agent_name slowly $agent_verb around $target_name, touching $target_objective "
        "lightly, never lingering long enough to do more than excite.",
        this_object(), who, environment());
      call_out( (: eventPerform, 1 :), 10);
      break;
    case 1:
      send_messages( ({ "start", }),
        "$agent_name $agent_verb to slowly remove her dress.",
        this_object(), 0, environment());
      eventForce("remove dress");
      eventForce("say You should get more comfortable, shouldn't you?");
      who->eventForce("remove all");
      who->eventForce("unwield all");
      call_out( (: eventPerform, 2 :), 10);
      break;
    case 2:
      send_messages( ({ "run", }),
        "$agent_name $agent_verb $agent_possessive hands over $target_possessive_noun body, slowly "
        "caressing muscles. Slowly, she leans and runs her tongue up $target_possessive_noun neck, "
        "running her fingers over $target_possessive chest while gently humming.",
        this_object(), who, environment() );
      call_out( (: eventPerform, 3 :), 10);
      break;
    case 3:
      send_messages( ({ }),
        "Aria slowly runs her hands down, moving around to face $target_name directly. Kneeling down, "
        "Aria flicks her tongue to run gently over $target_possessive_noun exposed " + (who->GetGender() == "male" ? "cock" : "nipples") + 
        ".", this_object(), who, environment() );
      eventForce("say You should really lie down.");
      eventForce("wink sexily");
      who->SetPosition(POSITION_LYING);
      send_messages( ({ "climb", "lie" }),
        "$agent_name $agent_verb onto the velvet covered bed and $agent_verb down.",
        who, 0, environment() );
      call_out( (: eventPerform, 4 :), 10);
      break;
    case 4:
      send_messages( ({ }),
        "Aria climbs up on the bed to lie next to $target_name.",
        this_object(), who, environment() );
      if (who->GetGender() == "male") { eventForce("say Lie on your back.  I like to be on top."); }
        else { eventForce("say Lie back and enjoy."); }
      if (who->GetGender() == "male") {
        send_messages( ({ }),
          "Aria climbs on top of $target_name, mounting $target_objective with great skill. "
          "With a gentle motion of her hips, Aria inserts $target_possessive_noun " + who->GetRace() + "-sized "
          "manhood inside of her.",
          this_object(), who, environment() );
        if (who->GetSize() > GetSize()) {
          eventForce("say MmMMMmmm, I like the bigger ones, my " + who->GetRace() + " friend.");
          eventForce("moan");
        }
        if (who->GetSize() < GetSize()) {
          who->eventPrint("If Aria is not impressed with your " + who->GetRace() + " endowments, she does "
                          "an excellent job of hiding it.");
          }
        } else { /* female */
          send_messages( ({ }),
            "Aria deftly flicks her tongue over $target_possessive_noun opening, lapping lightly "
            "while occasionally darting a finger or two in and out. Her tongue flicks heavily in "
            "the right places, and the sensation affects $target_name quickly.",
            this_object(), who, environment() );
          who->eventForce("pant");
          who->eventForce("moan");
          eventForce("emote gently purrs and hums while nibbling and licking.");
        }
        call_out( (: eventPerform, 5 :), 10);
        break;
      case 5:
        if (who->GetGender() == "male") {
          send_messages( ({ }),
            "Aria arches her back and moves her hips faster and harder.",
            this_object(), 0, environment() );
          eventForce("moan");
          who->eventForce("pant");
        } else {
          send_messages( ({ "arch" }),
            "Aria moves her head and tongue faster and harder. Her hands move to $target_possessive_noun "
            "breasts, kneeding them and pinching $target_possessive nipples lightly. $target_name "
            "$target_verb $target_possessive back, overcome with the ectasy of the moment.",
            this_object(), who, environment());
          who->eventForce("moan");
          eventForce("emote hums gently while running her tongue in and over.");
        }
        call_out( (: eventPerform, 6 :), 10);
        break;
      case 6:
        send_messages( ({ "explode" }),
          "$target_name $target_verb in a deep and powerful orgasm!",
          this_object(), who, environment() );
        who->SetParalyzed(10);
        eventForce("say MMMmmMm. That was great.  Thank you.");
        eventForce("kiss " + GetJohn()->GetKeyName());
        if (!random(2)) {
          send_messages( ({ "drift" }),
            "$agent_name $agent_verb off into a sound and peaceful sleep.",
            who, 0, environment() );
          who->SetPosition(POSITION_LYING);
          who->SetSleeping(10);
        }
        break;
  }
  
  // Kairehn - I need this for my whore quest, kthx
  if (present(who, environment(this_object())))
  {
    who->SetProperty("whoremolester", 1);
  }
  CHAT_D->eventSendChannel("Aria", "reports", capitalize(who->GetKeyName()) + " paid Aria for luvvin.");
  log_file("players/aria", capitalize(who->GetKeyName()) + " paid Aria for luvvin.\n" );
  if (!random(20)) {
    who->eventPrint("You feel %^GREEN%^sickened%^RESET%^ by what you have done. Maybe you have caught something from her?");
    load_object(STD_GERMS "std")->eventInfect(who);    
    return;
  } 
}