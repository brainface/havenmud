// goblin singer
// dalnairn recode
// torak@haven 2014-2019

#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_NPC;

int eventRequestHearse(string command);
object Crowd;
object SetCrowd(object who);
object GetCrowd();
void eventPerformNumber(int x);
int eventAction();

static void create() {
  ::create();
  SetKeyName("nergui");
  SetId( ({ "nergui" }) );
  SetAdjectives( ({ "", "" }) );
  SetShort("Nergui");
  SetRace("goblin");
  SetBaseLanguage("Runic");
  SetGender("male");
  SetClass("bard");
  SetLevel(200);
  SetMorality(0);
  SetInventory( ([
    ]) );
  SetLong(
    "Nergui is a middle aged goblin with a beer belly to "
    "match his lifestyle. "
    "He appears eager to please you with his music. "
    "Perhaps if you asked him <for songs> he would tell you what songs he knows."
    );
  AddRequestResponse("songs", "I can perform, 'Hearse Song' if you <ask nergui for hearse>.");
  AddRequestResponse("hearse",  (: eventRequestHearse :) );
  SetMessage("say", "sing");
}

object SetCrowd(object who) { return Crowd = who; }
object GetCrowd() { return Crowd; }

int eventRequestHearse(string what) {
  object who = this_player();
  object *viewers;
  string *tmp = ({ });
  viewers = all_inventory(environment());
  viewers = filter(viewers, (: living :) );
  viewers -= ({ this_object(), who }),
  viewers = filter(viewers, (: !($1->GetInvis()) :) );
  if (sizeof(viewers)) {
    foreach(object v in viewers) { tmp += ({ capitalize(v->GetKeyName()) }); }
    eventForce("say hey we got a good crowd tonight with " +conjunction(tmp, "or") + 
    " to rock out with us!");
  }
  SetCrowd(who);
  call_out( (: eventPerformNumber, 0 :), 5);
}

void eventPerformNumber(int i) {
  object who = GetCrowd();
  if (!present(who, environment(this_object()))) {
    SetCrowd(0);
    return;
  }

debug(i);

  switch(i) {
    case 0:
      environment()->eventPrint("With a pluck of his guitar, Nergui starts his song.");
      eventForce("say "
        "have you ever thought as the hearse goes by, "
        "one of these days you are going to die? "
        "the motor pool sends out a car, "
        "you goin for a ride but you dont get far.");
      send_messages( ({ "rock" }),
        "$agent_name $agent_verb out all over his axe.",
        this_object(), who, environment() );
      call_out( (: eventPerformNumber, 1 :), 10);
      break;
    case 1:
      send_messages( ({ "rock" }),
        "$agent_name $agent_verb out to $agent_possessive_noun song while he continues to sing.",
        this_object(), who, environment() );
      eventForce("say "
        "as you watch the death wagon riding by, "
        "you dont know wether to laugh or cry. "
        "you wish it werrent but you know that its true, "
        "the very next load may consist of you!");
      call_out( (: eventPerformNumber, 2 :), 10);
      break;
    case 2:
      eventForce("say "
        "the burial detail lowers you down, "
        "the officers they just stand around. "
        "they shovel in dirt, they shovel in rocks, "
        "they dont give a damn if they break the box.");
      call_out( (: eventPerformNumber, 3 :), 10);
      break;
    case 3:
      eventForce("say "
        "the worms crawl in, the worms crawl out, "
        "they creep all over your chin and mouth. "
        "they call in their friends, their friend's friends too, "
        "you look like hell when they get through!");
      call_out( (: eventPerformNumber, 4 :), 10);
      break;
    case 4:
      send_messages( ({ "play" }),
        "With eyes wide shut $agent_name $agent_verb on.",
        this_object(), who, environment() );
      eventForce("say "
        "your eyes drop out, your teeth fall in, "
        "the worms are all over your mouth and chin. "
        "each one takes a bite or two of what the pentagram says is you.");
        call_out( (: eventPerformNumber, 5 :), 10);
        break;
    case 5:
      send_messages( ({ "play" }),
        "After a rockin guitar rift $agent_name $agent_verb on.",
        this_object(), who, environment() );
      eventForce("emote " 
        "does some killer rifts all over his axe with inspirational talent!");
      call_out( (: eventPerformNumber, 6 :), 10);
      break;
    case 6:
      send_messages( ({ "bow" }),
        "$agent_name $agent_verb to his audience in triumph!",
        this_object(), who, environment() );
      eventForce("say thank, thank you very much.");
      break;
  }
}
