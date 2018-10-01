// Black Francis
// Torak 2013 with great help from mahkefel

#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_NPC;

int eventRequestNo13(string command);
object Crowd;
object SetCrowd(object who);
object GetCrowd();
void eventPerformNumber(int x);
int eventAction();

static void create() {
  ::create();
  SetKeyName("francis");
  SetId( ({ "black", "francis" }) );
  SetAdjectives( ({ "black", "francis" }) );
  SetShort("Black Francis");
  SetRace("human");
  SetBaseLanguage("Enlan");
  SetGender("male");
  SetClass("bard");
  SetLevel(500);
  SetMorality(0);
  SetInventory( ([
    ]) );
  SetLong(
    "Black Francis is a middle aged white human with a beer belly to "
    "match his lifestyle. "
    "He appears eager to please you with his music. "
    "Perhaps if you asked him <for songs> he would tell you what songs he knows."
    );
  AddRequestResponse("songs", "I can perform, 'No. 13 baby' if you <ask francis for number13>.");
  AddRequestResponse("number13",  (: eventRequestNo13 :) );
  SetMessage("say", "sing");
}

object SetCrowd(object who) { return Crowd = who; }
object GetCrowd() { return Crowd; }

int eventRequestNo13(string what) {
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
      environment()->eventPrint("With a pluck of his guitar, Black Francis starts his song.");
      eventForce("say "
        "Got hair in a girl that flows to her bones and a comb in her pocket "
        "if the winds get blown! Stripes on her eyes when she walks slow but "
        "her face falls down when she go, go, go! Black tear falling on my lazy queen.."
        "gotta tattoed tit, say number 13.");
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
        "Viva! Don't want no blue eyes. La loma! I want brown eyes. Rica! I'm in a state. "
        "I'm in.. a state.. I'm in.. a state. I'm in.. a state! I'm in a state!");
      call_out( (: eventPerformNumber, 2 :), 10);
      break;
    case 2:
      eventForce("say "
        "Choir in the yard in the house next door where a grandma brought some songs from the shore. "
        "Six foot girl gonna sweat when she dig, stand close to the fire when they light the pig!"
        "Standing in her chinos shirt pulled of clean, gotta tattoed tit say number thirteen.");
      call_out( (: eventPerformNumber, 3 :), 10);
      break;
    case 3:
      eventForce("say "
        "Viva! Don't want no blue eyes. La loma! I want brown eyes. Rica! I'm in a state. "
        "I'm in.. a state.. I'm in.. a state.  I'm in.. a state! I'm in a state!");
      call_out( (: eventPerformNumber, 4 :), 10);
      break;
    case 4:
      send_messages( ({ "play" }),
        "With eyes wide shut $agent_name $agent_verb on.",
        this_object(), who, environment() );
      eventForce("say "
        "Viva! Don't want no blue eyes. La loma! I want brown eyes. Rica! I'm in a state.");
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
