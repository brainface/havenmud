/*  Sage version 2.0
 *  Duuktsaryth@Haven
 */
#include <lib.h>
inherit LIB_SENTIENT;
int Charge = 350;
string LocalCurrency = "imperials";
string *Languages = ({ });
void eventTeachLanguage(object who, string command, string args);
string *SetTaughtLanguages(string *);
string AddTaughtLanguage(string);
string RemoveTaughtLanguage(string);
string GetLocalCurrency();
int GetCharge();

static void create() {
  ::create();
  AddCommandResponse("teach", (: eventTeachLanguage :) );
}

void eventGreet(object who) {
  eventForce("speak You could <ask " + GetKeyName() + " to teach LANGUAGE> or <ask " + GetKeyName() + " to teach advanced
LANGUAGE> to learn a language.");
  who->eventPrint("Using the <advanced> option will cost 1 development point in addition to currency.");
  eventForce("speak I charge " + GetCharge() + " " + GetLocalCurrency() + " to give a lesson.");
  eventForce("speak I speak " + conjunction(Languages, "and") + ".");
}

int SetCharge(int amount) {
  /* Doesn't do anything */
  return Charge;
}

int GetCharge() {
  float x;
  x = Charge * currency_rate(LocalCurrency);
  return to_int(x);
  }

varargs void SetLanguage(string language, int level, int native) {
  AddTaughtLanguage(language);
  return ::SetLanguage(language, level, native);
  }

string *SetTaughtLanguages(string *lans) {
  return Languages = lans;
 }

string *AddTaughtLanguage(string lan) {
  return (Languages += ({ lan }) );
  }

string *RemoveTaughtLanguage(string lan) {
  return (Languages -= ({ lan }) );
  }

string *GetTaughtLanguages() {
        return distinct_array(Languages + ({ GetNativeLanguage() }));
}

string SetLocalCurrency(string cur) {
  return (LocalCurrency = cur);
  }

string GetLocalCurrency() {
  return (LocalCurrency);
  }

void eventTeachLanguage(object who, string command, string args) {
  string advfl = 0;

  if (!args) {
    eventForce("speak I teach " + conjunction(GetTaughtLanguages()) );
    return;
  }
  if (sscanf(args, "%s %s", advfl, args) == 2) {
        if (advfl == "advanced") {
                if (who->GetDevelopmentPoints() < 1) {
                        eventForce("speak Your mind is not capable of handling "
                                   "such information right now.");
                        return;
                } 
    } else {
        eventForce("speak I'm not sure what you're asking.  "
                   "ask me to teach <language> or teach <advanced> <language>.");
        return;
    }
  }
  if (who->GetLanguageLevel(args) >= 100) {
      eventForce("speak You have already mastered that language.");
      return;
   }
  args = capitalize(args);
  if (member_array(args, GetTaughtLanguages()) == -1) {
    eventForce("speak I don't speak that language.");
    return;
   }
  if (who->GetCurrency(GetLocalCurrency()) < GetCharge()) {
    eventForce("speak You don't have enough money.");
    eventForce("speak I charge " + GetCharge() + 
               " " + GetLocalCurrency() + " per class.");
    return;
   }
  if (newbiep(who)) {
     eventForce("speak You are too young for such training!");
     return;
    }
  who->AddCurrency(GetLocalCurrency(), -(GetCharge()));
  send_messages( "give",
    "$agent_name $agent_verb $target_name a lesson in " +  args + " for " + GetCharge() + " " + GetLocalCurrency() + ".", 
    this_object(), who, environment() );
  if (advfl) {
        who->AddLanguagePoints(args, 25000);
        who->AddDevelopmentPoints(-1);
  } else {
        who->AddLanguagePoints(args, 1000);
  }
  return;
 }
